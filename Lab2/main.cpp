#include "Deck.h"
#include "Card.h"
#include <iostream>

int main() {
    try {
        // Test: Create a deck with 1 pack
        Deck deck(1);  // Create a deck with 1 pack of cards
        std::cout << "Remaining cards in deck: " << deck.Remaining() << "\n";

        // Deal and print a single card
        Card card = deck.DealCard();
        std::cout << "Dealt card: " << card << "\n";

        // Deal a hand of 5 cards
        std::cout << "Dealt hand: ";
        for (int i = 0, j = 5; i < j; i++) {
            std::cout << deck.DealCard() <<  std::endl;
        }
        std::cout << "\n";

        // Print remaining cards
        std::cout << "Remaining cards in deck: " << deck.Remaining() << "\n";

    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
