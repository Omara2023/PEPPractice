#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include "Card.h"

// Deck class containing a collection of cards
class Deck {
private:
    uint8_t cardsPerDeck;        // 52 cards per deck (8 bits)
    uint8_t numDecks;            // Number of packs (max 10 decks, 8 bits)
    uint16_t remainingCardCount; // Remaining cards in the deck (16 bits)
    std::vector<Card> deck;      // Vector of Card representing the deck

    // Helper functions
    std::string suitToStr(uint8_t suit) const;
    std::string rankToStr(uint8_t rank) const;

public:
    // Constructors
    Deck();                   // Default: 1 pack of cards
    Deck(uint8_t n);          // Deck with n packs (up to 10)

    // Deck functions
    void CreateDeck();        // Populates the deck
    void ShuffleDeck();       // Shuffles the deck
    void DeleteDeck();        // Clears the deck
    uint16_t Remaining() const; // Returns the number of remaining cards
    void NewDeck();           // Resets the deck with 1 pack
    void NewDeck(uint8_t n);  // Resets the deck with n packs

    const Card DealCard();    // Deals one card and removes it from the deck
    const std::vector<Card> DealHand(); // Deals a hand of 5 cards and removes them

    // Overloaded operators
    friend std::ostream& operator<<(std::ostream &os, const Card &card);
};

#endif // DECK_H
