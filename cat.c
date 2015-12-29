#include <stdio.h>

int main(int argc, char *argv[])
{
  char *program_name = argv[0];
  char *filename = argv[1];
  FILE *file = fopen(filename, "r");

  if (file) {
    int character;
    while( (character = getc(file)) != EOF ) {
      putchar(character);
    }
    fclose(file);
  }
  return 0;
}
