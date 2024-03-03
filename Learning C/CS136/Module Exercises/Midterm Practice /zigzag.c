#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

void zigzag(int width, int height, char z) {
  int charPos = 1;
  int cur = 1;
  bool reverse = false;

  for (int i = 1; i <= height; i++) {
    while (cur <= width) {
      if (cur == charPos) {
        printf("%c", z);
      } else {
        printf(".");
      }
      
      cur += 1;
    }
    
    printf("\n");
    cur = 1;
    
    if (charPos == width && !(reverse)) {
      reverse = true;
      charPos -= 1;
    } else if (charPos == 1 && reverse) {
      reverse = false;
      charPos += 1;
    } else if (reverse) {
      charPos -= 1;
    } else {
      charPos += 1;
    }
  }
}

int main(void) {
  zigzag(4, 17, '#');
}