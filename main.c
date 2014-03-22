#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void count(char minAscii, char maxAscii, int minElement, int maxElement, int position, char** currentString) {
  /* printf("\ncount(%c, %c, %d, %d, %d, %s)\n", minAscii, maxAscii, minElement, maxElement, position, *currentString); */

  for (char character = minAscii; character <= maxAscii; character++) {
    (*currentString)[position] = character; // Increment the character at the current position
    printf("%s\n", *currentString); // Print the current string

    if (position < maxElement - 1) {
      count(minAscii, maxAscii, minElement, maxElement, position + 1, currentString); // increase the level of recursion
    }
  }

  /*
   * Issues:
   * Fills up string with A before starting to iterate
   * When at the end of a loop, exits count with the old value still intact.
   */
}

int main() {
  int minElement = 0;
  int maxElement = 10;
  char minAscii = 33;
  char maxAscii = 126;

  // This is the most reliable way I could think of to make a pointer to a string.
  char *emptyString = (char *) malloc(sizeof(char) * maxElement);
  char **currentString = &emptyString;

  for (int length = minElement + 1; length <= maxElement; length++) {
    count(minAscii, maxAscii, minElement, length, 0, currentString);
  }

  return 0;
}
