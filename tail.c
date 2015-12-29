#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int choice;
  int lines_to_print = 10;
  char *ep;

  while ( (choice = getopt(argc, argv, "n:")) != -1 ) {
    switch(choice) {
      case 'n':
        lines_to_print = strtol(optarg, &ep, 10);
        break;
      case '?':
      default:
        break;
    }
  }
  argc -= optind;
  argv += optind;

  FILE *file = fopen(argv[0], "r");
  if (file) {
    int current_position;
    int character;
    int lines_found = 0;

    fseek(file, 0L, SEEK_END);

    current_position = ftell(file);
    while(--current_position >= 0) {
      fseek(file, current_position, SEEK_SET);
      if (getc(file) == '\n' && (++lines_found) - 1 == lines_to_print) {
        break;
      }
    }

    while( (character = getc(file)) != EOF) {
      putchar(character);
    }

    fclose(file);
    return 0;
  }
  return 1;
}
