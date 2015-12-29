#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE *file = fopen(argv[1], "r");
  if (file) {
    int lines_to_print = 10;
    int character; 

    while( (character = getc(file)) != EOF ) {
      putchar(character);
      if (character == '\n') {
        --lines_to_print;
      }
      if (lines_to_print == 0) {
        break;
      }
    }

    fclose(file);
    return 0;
  }
  else {
    return 1;
  }
}
