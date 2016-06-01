#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void count(char minAscii, char maxAscii, int minElement, int maxElement, int position, char* currentString) {
  for (char character = minAscii; character <= maxAscii; character++) {
    currentString[position] = character; // Increment the character at the current position

    if (position < maxElement - 1) {
      count(minAscii, maxAscii, minElement, maxElement, position + 1, currentString); // increase the level of recursion
    } else {
      printf("%s\n", currentString); // Print the current string
    }
  }
}

void initializeString(char* string, int length) {
  for (int i = 0; i <= length; i++) {
    string[i] = '\0';
  }
}

void brut(char minAscii, char maxAscii, int minElement, int maxElement) {
  char currentString[maxElement];
  initializeString(currentString, maxElement);

  for (int length = minElement + 1; length <= maxElement; length++) {
    count(minAscii, maxAscii, minElement, length, 0, currentString);
  }
}

int main() {
  // Set up the bounds for the strings
  int minElement = 0;   // Start at the beginning
  int maxElement = 10;  // Generate strings up to 10 characters long
  char minAscii  = 33;  // '!'
  char maxAscii  = 126; // '~'

  brut(minAscii, maxAscii, minElement, maxElement);

  return 0;
}
