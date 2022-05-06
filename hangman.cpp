#include <iostream>

#define LETTERS 26
#define OFFSET 65

std::string word;
bool guesses[LETTERS];

void game();
void guess();
void printGame();
void printLetters();
void printWord();
bool isValid(char c);

int main() { game(); }

void game() {
  printf("Player 1, what should the word be? ");
  std::cin >> word;
  for (int i = 0; i < word.length() - 1; i++) {
    word[i] = toupper(word.at(i));
    if (!isValid(word[i])) {
      printf("Invalid word, please choose another\n");
      return;
    }
  }

  while (true) {
    printGame();
    guess();
  }
}

void guess() {
  printf("Player 2, your guess? ");
  char guess;
  std::cin >> guess;
  guess = toupper(guess);
  if (!isValid(guess)) {
    printf("Invalid guess, must be A-Z.");
    return;
  }
  int index = int(guess) - OFFSET;
  if (guesses[index]) {
    printf("You already guessed %c\n", guess);
    return;
  }

  guesses[index] = true;
}

void printGame() {
  printWord();
  printLetters();
}

void printWord() {
  for (char c : word) printf("%c", guesses[int(c - OFFSET)] ? c : '_');
  std::string guessString;
  for (int i = 0; i < sizeof(guesses); i++)
    if (guesses[i]) guessString.append(std::to_string(char(i)));
  if (guessString != "") printf("(%s)", guessString);
  printf("Guess: %s", guessString);
  printf("\n");
}

void printLetters() {
  for (int i = 0; i < sizeof(guesses); i++)
    printf("%c ", guesses[i] ? '-' : char(i + OFFSET));
  printf("\n");
}

bool isValid(char c) { return c >= OFFSET || c <= OFFSET + LETTERS; }
bool isValid(std::string str) {
  for (char c : str)
    if (!isValid(c)) return false;
  return true;
}