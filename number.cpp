#include <stdlib.h>

#include <iostream>

using namespace std;

int answer;

void game();

int main() {
  game();
  return 0;
}

void game() {
  cout << "I'm thinking of a number between 1 - 100, can you guess it? ";
  answer = rand() % 100;
  int guess, chance;
  int max = 7;
  do {
    cin >> guess;
    if (guess == answer) break;
    cout << "My answer is " << (guess > answer ? "lower" : "higher")
         << ", you have " << (max - chance) << " guess"
         << (max - chance == 1 ? "" : "es") << " left." << endl;
    chance++;
  } while (guess != answer && chance <= max);
  if (guess == answer) {
    cout << "You got my number in " << chance << " guess"
         << (chance == 1 ? "" : "es") << endl;
    return;
  }
  cout << "You couldn't guess " << answer << " :(" << endl;
}
