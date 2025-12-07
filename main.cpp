#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>

#include "Stats.h"
#include "Card.h"
#include "CardData.h"
#include "Deck.h"
#include "Kingdom.h"
#include "GameManager.h"

#include "PlagueEvent.h"
#include "FestivalEvent.h"
#include "WarEvent.h"
#include "Exeptions.h"

int main() {
    try {
        srand((unsigned)time(nullptr));
        Stats s(50,50,50,50);
        Kingdom k("Dacia", s);

        Deck deck;
        initializeDeck(deck);

        GameManager gm;
        gm.addEvent(std::make_unique<PlagueEvent>(30));
        gm.addEvent(std::make_unique<FestivalEvent>(20));
        gm.addEvent(std::make_unique<WarEvent>(25));

        bool auto_mode = (std::getenv("GITHUB_ACTIONS") != nullptr);
        int turn = 1;
        int max_turns = 50;

        while (!k.isFallen() && turn <= max_turns) {
            std::cout << "\nTurn " << turn++ << '\n';
            const Card &card = deck.draw_random_card();
            card.display_question();
            int choice;
            if (auto_mode) {
                choice = 1 + rand() % 2;
                std::cout << "Auto choice: " << choice << std::endl;
            } else {
                std::cout << "Alegerea ta (1/2): ";
                std::cin >> choice;
            }
            if (choice != 1 && choice != 2) throw InvalidChoiceException();
            k.changeStats(card.getEffect(choice));

            if (turn % 3 == 0) {
                gm.triggerRandomEvent(k);
            }

            std::cout << k << std::endl;
        }

        if (k.isFallen()) std::cout << "Regatul a cazut!\n";
        else std::cout << "Limita de ture atinsa.\n";
    } catch (const GameException &e) {
        std::cerr << "GameException: " << e.what() << '\n';
        return 2;
    } catch (const std::exception &e) {
        std::cerr << "std::exception: " << e.what() << '\n';
        return 3;
    }
    return 0;
}

