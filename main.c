#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void count(char minAscii, char maxAscii, int minElement, int maxElement, int position, char** currentString) {
  printf("\ncount(%c, %c, %d, %d, %d, %s)\n", minAscii, maxAscii, minElement, maxElement, position, *currentString);

  for (char character = minAscii; character <= maxAscii; character++) {
    // increment the character at the current position
    (*currentString)[position] = character;
    getchar();

    // Print the current string numerically, as a string, and its address.
    for (int j = 0; j < maxElement; j++) {
      printf("%d\t", (*currentString)[j]);
    }
    printf("%s %p", *currentString, currentString);

    // increase the level of recursion
    if (position < maxElement - 1) {
      count(minAscii, maxAscii, minElement, maxElement, position + 1, currentString);
    }
  }
  printf("\ncount(%c, %c, %d, %d, %d, %s) finished", minAscii, maxAscii, minElement, maxElement, position, *currentString);

  /*
   * Issues:
   * Fills up string with A before starting to iterate
   * When at the end of a loop, exits count with the old value still intact.
   */
}

int main() {
  int minElement = 0;
  int maxElement = 4;
  /* char minAscii = 33; */
  /* char maxAscii = 126; */
  char minAscii = 65;
  char maxAscii = 68;

  // This is the most reliable way I could think of to make a pointer to a string.
  char *emptyString = (char *) malloc(sizeof(char) * maxElement);
  char **currentString = &emptyString;

  count(minAscii, maxAscii, minElement, maxElement, 0, currentString);

  return 0;
}
