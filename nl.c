#include <stdio.h>

int main(int argc, const char *argv[])
{
  const char *filename = argv[1];
  FILE *file = fopen(filename, "r");

  if (file) {
    int character;
    int line_number;

    printf("%6d  ", ++line_number);
    while( ( character = getc(file) ) != EOF ) {
      putchar(character);
      if (character == '\n') {
        printf("%6d  ", ++line_number);
      }
    }
    fclose(file);
    return 0;
  }
  return 1;
}
