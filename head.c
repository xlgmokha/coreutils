#include <stdio.h>
#include <stdlib.h>
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
