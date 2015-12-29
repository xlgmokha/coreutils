#include <stdio.h>

int main(int argc, const char *argv[])
{
  FILE *file = fopen(argv[1], "r");
  if (file) {
    int current_position = ftell(file);
    int character;

    fseek(file, 0L, SEEK_END);

    current_position = ftell(file);
    printf("file size: %d\n", current_position);

    while(current_position >= 0) {
      fseek(file, --current_position, SEEK_SET);
      character = getc(file);
      putchar(character);
    }

    fclose(file);
    return 0;
  }
}
