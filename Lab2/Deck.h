#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "Card.h"

// Deck class containing a collection of cards
class Deck {
private:
    uint8_t cardsPerDeck;        // 52 cards per deck (8 bits)
    uint8_t numDecks;            // Number of packs (max 10 decks, 8 bits)
    uint16_t remainingCardCount; // Remaining cards in the deck (16 bits)
    Card * deck;                 // Array of Card representing the deck

    // Helper functions
    void Init_deck();
    void Delete_deck();
    Deck(Deck &);    
    Deck & operator=(Deck &);
    std::string suitToStr(uint8_t suit) const;
    std::string rankToStr(uint8_t rank) const;

public:
    // Constructors
    Deck();                   // Default: 1 pack of cards
    Deck(uint8_t n);          // Deck with n packs (up to 10)
    ~Deck();

    // Deck functions
    void CreateDeck();        // Populates the deck
    void ShuffleDeck();       // Shuffles the deck
    void DeleteDeck();        // Clears the deck
    uint16_t Remaining() const; // Returns the number of remaining cards
    uint16_t Deck_size();      // Returns original size of deck.
    void NewDeck();           // Resets the deck with 1 pack
    void NewDeck(uint8_t n);  // Resets the deck with n packs

    const Card DealCard();    // Deals one card and removes it from the deck

    class Iterator {
    private:
        Card * current;

    public:
        Iterator(Card * cur) : current(cur) {}
        Iterator(const Iterator& other) : current(other.current) {}

        Card & operator*() {
            return *current;
        }

        Iterator& operator++() {
            ++current;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator!=(const Iterator& other) const { return current != other.current; }
        bool operator==(const Iterator& other) const { return current == other.current; }
    
        // Random access support
        Iterator operator+(int n) const {
            return Iterator(current + n); // Return a new iterator offset by n
        }

        Iterator& operator+=(int n) {
            current += n; // Increment the current pointer
            return *this; // Return the updated iterator
        }

        // Subtraction operator
        int operator-(const Iterator& other) const {
            return current - other.current; // Return the difference in indices
        }

        // Subscript operator
        Card& operator[](int index) {
            return *(current + index); // Access the card at the specified index
        }

        // Postfix decrement operator
        Iterator operator--(int) {
            Iterator temp = *this; // Create a copy
            --current; // Decrement the current iterator
            return temp; // Return the copy
        }
    };

    Iterator begin();
    Iterator end();

    // Overloaded operators
    friend std::ostream& operator<<(std::ostream &os, const Card &card);

};

#endif // DECK_H
