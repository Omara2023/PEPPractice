#ifndef CARD_H
#define CARD_H

#include <iostream>

// Card struct representing a single card
struct Card {
    unsigned int rank : 4;  // 4 bits for rank (1-13 for Ace to King)
    unsigned int suit : 2;  // 2 bits for suit (0-3 for Clubs, Diamonds, Hearts, Spades)

    // Overload the == operator for comparing two cards
    bool operator==(const Card &other) const;

    // Overload the << operator for outputting a card
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
};

#endif // CARD_H
