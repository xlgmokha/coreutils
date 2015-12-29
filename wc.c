#include <stdio.h>
#include <wctype.h>

int main(int argc, const char *argv[])
{
  int character;
  int lines = 0, words = 0, bytes = 0, got_space = 0;
  const char *filename = argv[1];
  FILE *file = fopen(filename, "r");

  if (file) {
    while ( (character = getc(file)) != EOF ) {
      if (character == '\n') {
        ++lines;
      }
      if (iswspace(character) != 0) {
        if (got_space == 0) {
          ++words;
        }
        got_space = 1;
      }
      else {
        got_space = 0;
      }

      ++bytes;
    }
    printf(" %7d %7d %7d %s\n", lines, words, bytes, filename);

    fclose(file);
    return 0;
  }

  return 1;
}
