#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int choice;
  int show_lines = 0;

  while ( (choice = getopt(argc, argv, "n")) != -1 ) {
    switch(choice) {
      case 'n':
        show_lines = 1;
        break;
      case '?':
      default:
        break;
    }
  }
  argc -= optind;
  argv += optind;

  char *filename = argv[0];
  FILE *file = fopen(filename, "r");

  if (file) {
    int character, previous;
    int line = 0;

    if (show_lines == 1) {
      printf("%6d\t", ++line);
    }

    while( (character = getc(file)) != EOF ) {
      if (previous == '\n' && show_lines == 1) {
        printf("%6d\t", ++line);
      }
      putchar(character);
      previous = character;
    }
    fclose(file);
  }
  return 0;
}
