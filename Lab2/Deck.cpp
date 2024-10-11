#include "Deck.h"
#include <algorithm>
#include <ctime>

// Constructor: Initializes a deck with 1 pack of cards
Deck::Deck() : cardsPerDeck(52), numDecks(1), deck(nullptr){
    CreateDeck();
}

// Constructor: Initializes a deck with n packs (max 10)
Deck::Deck(uint8_t n) : cardsPerDeck(52), numDecks(n), deck(nullptr) {
    if (n > 10) n = 10; // Maximum 10 decks
    CreateDeck();
}

// Helper function to convert suit to string
std::string Deck::suitToStr(uint8_t suit) const {
    switch (suit) {
        case 0: return "C"; // Clubs
        case 1: return "D"; // Diamonds
        case 2: return "H"; // Hearts
        case 3: return "S"; // Spades
    }
    return "";
}

// Helper function to convert rank to string
std::string Deck::rankToStr(uint8_t rank) const {
    if (rank == 1) return "A"; // Ace
    if (rank == 11) return "J"; // Jack
    if (rank == 12) return "Q"; // Queen
    if (rank == 13) return "K"; // King
    return std::to_string(rank); // 2-10
}

// Creates a deck with the specified number of packs
void Deck::CreateDeck() {
    if (deck) {
        delete [] deck;
    }
    
    uint16_t count = 0;
    deck = new Card[Deck_size()];
    for (uint8_t n = 0; n < numDecks; ++n) {
        for (uint8_t suit = 0; suit < 4; ++suit) {
            for (uint8_t rank = 1; rank <= 13; ++rank) {
                deck[count++] = {rank, suit};
            }
        }
    }
    remainingCardCount = Deck_size();
    ShuffleDeck();
}

u_int16_t Deck::Deck_size() {
    return cardsPerDeck * numDecks;
}

Deck::Iterator Deck::begin() {
    return Iterator(deck);
}

Deck::Iterator Deck::end() {
    return Iterator(deck + Deck_size());
}


// Shuffles the deck randomly
void Deck::ShuffleDeck() {
    std::srand(std::time(0)); // Seed for randomness
    std::random_shuffle(begin(), end());
}

// Deletes the current deck
void Deck::DeleteDeck() {
    delete [] deck;
    remainingCardCount = 0;
}

// Returns the number of remaining cards in the deck
uint16_t Deck::Remaining() const {
    return remainingCardCount;
}

// Resets the deck to 1 pack of cards
void Deck::NewDeck() {
    numDecks = 1;
    CreateDeck();
}

// Resets the deck to n packs of cards
void Deck::NewDeck(uint8_t n) {
    numDecks = (n > 10) ? 10 : n;
    CreateDeck();
}

// Deals one card and removes it from the deck
const Card Deck::DealCard() {
    if (remainingCardCount == 0) {
        throw std::out_of_range("No cards left in the deck");
    }
    Card dealtCard = deck[--remainingCardCount];    
    return dealtCard;
}

Deck::~Deck() {
    delete[] deck; //
}