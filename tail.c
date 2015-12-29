#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
  FILE *file = fopen(argv[1], "r");
  if (file) {
    int current_position = ftell(file);
    int character;
    int lines_found = 0;
    int lines_to_print = 10;

    fseek(file, 0L, SEEK_END);

    current_position = ftell(file);
    while(--current_position >= 0) {
      fseek(file, current_position, SEEK_SET);
      if (getc(file) == '\n' && ++lines_found == lines_to_print) {
        break;
      }
    }

    while( (character = getc(file)) != EOF) {
      putchar(character);
    }

    fclose(file);
    return 0;
  }
}
