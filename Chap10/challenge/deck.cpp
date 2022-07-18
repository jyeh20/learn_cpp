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
    Card * new_deck();
    Card * new_deck(int n);
    void print_string();
};

Deck::Deck() {
  _cards = new_deck();
  _cards_remaining = sizeof(_cards)/sizeof(_cards[0]);
  _num_decks = 1;
}

Deck::Deck(int n) {
  _cards = new_deck(n);
  _cards_remaining = sizeof(_cards)/sizeof(_cards[0]);
  _num_decks = n;
}

Card * Deck::new_deck() {
  return get_unshuffled_deck();
}

Card * Deck::new_deck(int n) {
  Card cards[52 * n];
  Card * unshuffled_deck = get_unshuffled_deck();
  for (int i = 0; i < n; ++i) {
    cards[52 * n + i] = unshuffled_deck[i];
  }
  return cards;
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