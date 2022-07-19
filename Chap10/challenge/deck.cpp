#include <cstdio>
#include <cstdlib>
#include <cstring>

constexpr char SUITS[] = "SHDC";
constexpr char VALUES[] = "A23456789TJQK";
constexpr int deck_size = 52;

struct Card {
  char suit;
  int value;
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
    void insert_card(int to, int from);
    const Card & deal_card();
    void new_deck();
    void new_deck(int n);
    void print_string();
};

Deck::Deck() {
  new_deck();
  _cards_remaining = deck_size;
  _num_decks = 1;
}

Deck::Deck(int n) {
  new_deck(n);
  _cards_remaining = deck_size * n;
  _num_decks = n;
}

Deck::~Deck() {
  _cards = nullptr;
}

const Card & Deck::deal_card() {
  --_cards_remaining;
  return _cards[_cards_remaining];
}

void Deck::shuffle_deck() {
  for (int i = _cards_remaining; i > 0; i--) {
    int random_num = rand() % i;
    insert_card(i-1, random_num);
  }
}

void Deck::new_deck() {
  _cards = get_unshuffled_deck();
}

void Deck::new_deck(int n) {
  Card cards[deck_size * n];
  Card * unshuffled_deck = get_unshuffled_deck();
  for (int i = 0; i < n; ++i) {
    cards[deck_size * n + i] = unshuffled_deck[i];
  }
  _cards = cards;
}

void Deck::print_string() {
  if (_cards_remaining <= 0) {
    puts("[]");
    return;
  }
  for (int i = 0; i < _cards_remaining; ++i) {
    Card c = _cards[i];
    printf("%d: [%c%c]\n", i, c.suit, c.value);
  }
    puts("");
}

// Helpers

Card * get_unshuffled_deck() {
  static Card deck[deck_size];
  int index = 0;
  for (int i = 0; i < strlen(SUITS); ++i) {
    char suit = SUITS[i];
    for (int j = 0; j < strlen(VALUES); ++j) {
      Card card;
      card.suit = suit;
      card.value = VALUES[j];
      deck[index++] = card;
    }
  }
  return deck;
}

void Deck::insert_card(int to, int from) {
  Card temp = _cards[to];
  _cards[to] = _cards[from];
  _cards[from] = temp;
}

int main() {
  Deck d;
  d.shuffle_deck();
  d.print_string();
  for (int i = 0; i < 52; i++) {
    Card c = d.deal_card();
    printf("\nRemoving Card\n%c%c\n", c.suit, c.value);
  }
  d.print_string();
  return 1;
}