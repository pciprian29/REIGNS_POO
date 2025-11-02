#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <ctime>

class Stats {
private:
    int Church, People, Army, Money;

    int limite(int x) const {
        return std::max(0, std::min(100, x));
    }

public:
    Stats()=default;
    Stats(int Church, int People, int Army, int Money): Church(Church), People(People), Army(Army), Money(Money) {
    }
    int getChurch() const { return Church; }
    int getPeople() const { return People; }
    int getArmy() const { return Army; }
    int getMoney() const { return Money; }

    friend std::ostream &operator<<(std::ostream &os, const Stats &s) {
        os << "Church: " << s.Church << ", People: " << s.People
                << ", Army: " << s.Army << ", Money: " << s.Money;
        return os;
    }

    void Apply_Effect(const std::array<int, 4> &effect) {
        this->Church += effect[0];
        this->People += effect[1];
        this->Army += effect[2];
        this->Money += effect[3];

        this->Church = limite(this->Church);
        this->People = limite(this->People);
        this->Army = limite(this->Army);
        this->Money = limite(this->Money);
    }

    ~Stats() = default;
};

class Card {
private:
    int id;
    std::string question;
    std::string left_option;
    std::string right_option;
    std::array<int, 4> left_stat_update;
    std::array<int, 4> right_stat_update;

public:
    Card(int id, std::string const question, std::string const left_option, std::string const right_option,
         std::array<int, 4> const &left_stat_update, std::array<int, 4> const &right_stat_update) {
        this->id = id;
        this->question = question;
        this->left_option = left_option;
        this->right_option = right_option;
        for (int i = 0; i < 4; i++) {
            this->left_stat_update[i] = left_stat_update[i];
            this->right_stat_update[i] = right_stat_update[i];
        }
    }

    void display_question() const {
        std::cout << question << std::endl;
        std::cout << "1) " << left_option << std::endl;
        std::cout << "2) " << right_option << std::endl;
    }

    const std::array<int, 4> &getEffect(int choice) const {
        if (choice == 1) return left_stat_update;
        else return right_stat_update;
    }

    friend std::ostream &operator<<(std::ostream &os, const Card &c) {
        os << "ID: " << c.id << " | " << "Question: " << c.question << std::endl;
        os << "1) Left Option: " << c.left_option << std::endl;
        os << "2) Right Option: " << c.right_option << std::endl;
        return os;
    }
    ~Card() = default;
};

class Deck {
private:
    std::vector<Card> cards;
public:
    Deck() = default;
    void addCard(const Card &card) {
        cards.push_back(card);
    }
    void displaycards() const {
        std::cout << cards.size() << std::endl;
        for (const auto &card: cards) {
            std::cout << card << std::endl;
        }
    }
    const Card &draw_random_card() const {
        int index = rand() % cards.size();
        return cards[index];
    }
    ~Deck() = default;
};

class Kingdom {
private:
    std::string name;
    Stats stats;

public:
    Kingdom(std::string name, Stats stats) {
        this->name = name;
        this->stats = stats;
    }

    Kingdom(const Kingdom &copy) : name(copy.name), stats(copy.stats) {
    }

    Kingdom &operator=(const Kingdom &copie) {
        if (this != &copie) {
            name = copie.name;
            stats = copie.stats;
        }
        return *this;
    }

    void Card_Effect(const Card &card, int choice) {
        const std::array<int, 4> &effect = card.getEffect(choice);
        this->stats.Apply_Effect(effect);
    }

    bool lost_game() const {
        return (stats.getChurch() == 0 || stats.getPeople() == 0 || stats.getArmy() == 0 || stats.getMoney() == 0 ||
                stats.getChurch() == 100 || stats.getPeople() == 100 || stats.getArmy() == 100 || stats.getMoney() ==
                100);
    }

    friend std::ostream &operator<<(std::ostream &os, const Kingdom &k) {
        os << "Name: " << k.name << std::endl;
        os << "Stats:" << k.stats << std::endl;
        return os;
    }

    ~Kingdom() = default;
};

int main() {
    srand(time(nullptr));
    Stats s(50, 50, 50, 50);
    Kingdom k("Dacia", s);
    Deck deck;
    deck.addCard(Card(1, "Poporul vrea taxe mai mici!",
                      "Scade taxele", "Refuza",
                      {-10, +5, 0, -5}, {+10, -5, 0, +5}));

    deck.addCard(Card(2, "Biserica cere o donatie",
                      "Doneaza", "Refuza",
                      {+5, -5, 0, -10}, {-5, +5, 0, 0}));

    deck.addCard(Card(3, "Armata vrea mai multi bani.",
                      "Accepta", "Refuza",
                      {0, -5, +10, -10}, {0, 0, -10, +5}));

    deck.addCard(Card(4, "Un nou bufon ar ridica moralul celor din palat",
                      "Accepta", "Refuza",
                      {0, +15, 0, -10}, {0, -5, 0, 0}));

    deck.addCard(Card(5, "In port a ajuns un o corabie infectata cu holera.",
                      "Inchide portul", "Nu faci nimic",
                      {0, +10, -10, -15}, {0, -30, 0, +10}));
    deck.addCard(Card(6,"Minerii au dat de aur!",
                        "Pastreaza aurul","Imparte aurul",
                        {0,0,0,+20},{+5,+5,+5,+5}));

    std::cout << "Bun venit, rege!" << std::endl;
    int turn = 1;
    while (!k.lost_game()) {
        std::cout << "Tura " << turn++ << std::endl;

        const Card& card = deck.draw_random_card();
        card.display_question();

        int choice;
        std::cout << "Alegerea ta (1 sau 2): ";
        std::cin >> choice;

        while (choice != 1 && choice != 2) {
            std::cout << "Poti introduce doar 1 sau 2";
            std::cin >> choice;
        }

        k.Card_Effect(card, choice);

        std::cout << "\n Starea regatului:\n" << k << std::endl;

        if (k.lost_game()) {
            std::cout << "\n Ai pierdut tronul!" << std::endl;
            break;
        }
    }

    std::cout << "\nGame over\n";
    return 0;
}
