#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// Your documentation goes here.
char readchar(bool ws_mode) {
  assert(ws_mode == READ_WHITESPACE || ws_mode == IGNORE_WHITESPACE);
  char input = CHAR_MIN;
  int status = INT_MIN;
  if (ws_mode == IGNORE_WHITESPACE) {
    status = scanf(" %c", &input);
  } else {
    status = scanf("%c", &input);
  }
  if (status == 1 && (input == '\n' || (' ' <= input && input <= '~'))) {
    return input;
  }
  return READ_CHAR_FAIL;
}
int main(void) {
  // Registering READ_WHITESPACE and IGNORE_WHITESPACE
  const int WS_READ = lookup_symbol("READ_WHITESPACE");
  const int WS_SKIP = lookup_symbol("IGNORE_WHITESPACE");
  
  // Reading whitespace behaviour from input
  int ws_mode = read_symbol();

  while (true) {
    char ch = READ_CHAR_FAIL;
    if (ws_mode == WS_READ) {
      ch = readchar(READ_WHITESPACE);
    } else if (ws_mode == WS_SKIP) {
      ch = readchar(IGNORE_WHITESPACE);
    } else {
      printf("ERROR: Invalid whitespace behaviour.\n");
	  break;
    }
  
    if (ch == READ_CHAR_FAIL) {
        break;
    } else {
      printf("%c", ch);
    }
  }
}