#include <cstdio>
#include <cstring>

constexpr char SUITS[] = "SHDC";
constexpr char VALUES[] = "A123456789TJQK";

struct Card {
  char suit : 4;
  int value : 4;
};

Card* get_unshuffled_deck();

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
    void print_string();
};

void Deck::new_deck() {
  _cards = get_unshuffled_deck();
}

void Deck::print_string() {
  for (int i = 0; i < sizeof(_cards); ++i) {
    Card c = _cards[i];
    printf("%c%c ", c.suit, c.value);
  }
}

// Helpers

Card * get_unshuffled_deck() {
  Card deck[52];
  int index = 0;
  for (int i = 0; i < strlen(SUITS); ++i) {
    char suit = SUITS[i];
    for (int j = 0; j < strlen(VALUES); ++j) {
      Card card;
      card.suit = suit;
      card.value = VALUES[j];
      deck[++index] = card;
    }
  }
  return deck;
}

int main() {
  get_unshuffled_deck();
  return 1;
}