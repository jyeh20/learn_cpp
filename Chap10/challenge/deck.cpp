#include <cstdio>

struct Card {
  char suit : 4;
  int value : 4;
};

class Deck {
  int _cards_remaining;
  int _num_decks;
  Card * _cards;
  public:
    Deck();
    Deck(int n);
    ~Deck();
    void shuffle_deck();
    int rand();
    const Card & deal_card();
    void new_deck();
    void new_deck(int n);
};