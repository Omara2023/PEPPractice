#include "Card.h"

// Overload the == operator
bool Card::operator==(const Card &other) const {
    return rank == other.rank && suit == other.suit;
}

// Helper function to convert rank to string
std::string rankToStr(unsigned int rank) {
    switch (rank) {
        case 1: return "A";  // Ace
        case 11: return "J"; // Jack
        case 12: return "Q"; // Queen
        case 13: return "K"; // King
        default: return std::to_string(rank); // For ranks 2-10
    }
}

// Helper function to convert suit to string
std::string suitToStr(unsigned int suit) {
    switch (suit) {
        case 0: return "Clubs";
        case 1: return "Diamonds";
        case 2: return "Hearts";
        case 3: return "Spades";
        default: return "Unknown Suit"; // Shouldn't happen
    }
}

// Overload the << operator for outputting a card
std::ostream& operator<<(std::ostream& os, const Card& card) {
    os << rankToStr(card.rank) << " of " << suitToStr(card.suit);
    return os;
}
