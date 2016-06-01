#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void tick(char minAscii, char maxAscii, int length, int position, char* currentString) {
  // Loop through all the characters between minAscii and maxAscii at the current position in the string
  for (char character = minAscii; character <= maxAscii; character++) {
    currentString[position] = character; // Increment the character at the current position

    // recurse until the string at the current length is filled, else print the current string.
    if (position < length - 1) {
      tick(minAscii, maxAscii, length, position + 1, currentString);
    } else {
      printf("%s\n", currentString);
    }
  }
}

// Fill the string with zeroes
void initializeString(char* string, int length) {
  for (int i = 0; i <= length; i++) {
    string[i] = '\0';
  }
}

void brut(char minAscii, char maxAscii, int maxLength) {
  char currentString[maxLength];
  initializeString(currentString, maxLength);

  for (int length = 1; length <= maxLength; length++) { // With lengths ranging from 1 to maxLength
    tick(minAscii, maxAscii, length, 0, currentString); // Start generating strings of the current length
  }
}

int main() {
  // Set up the bounds for generated strings
  int maxLength = 10;  // Generate strings up to 10 characters long
  char minAscii  = 33;  // '!'
  char maxAscii  = 126; // '~'

  brut(minAscii, maxAscii, maxLength);

  return 0;
}
