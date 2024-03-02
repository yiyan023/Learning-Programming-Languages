#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// Your declaration for your point structure goes here.
struct point {
  int x;
  int y;
};

// Your declaration for your rectangle structure goes here.
struct rectangle {
  struct point top_left;
  struct point bottom_right;
};

bool valid_rectangle(struct rectangle rect) {
  return rect.top_left.x <= rect.bottom_right.x && 
         rect.top_left.y <= rect.bottom_right.y;
}

// Your documentation goes here.
// rectangle_area(rect) finds the area of an inputted rectangle rect
// requires: rect is a valid rectangle
int rectangle_area(struct rectangle rect) {
  // Your implementation goes here.
  assert(valid_rectangle(rect));
  int area = (rect.bottom_right.x - rect.top_left.x) * 
             (rect.bottom_right.y - rect.top_left.y);
  return area;
}

int main(void) {
  struct point top_left = {1, 1};
  struct point bottom_right = {2, 2};
  struct rectangle rect = {top_left, bottom_right};
  assert(rectangle_area(rect) == 1);
  
  // Your additional tests go here.
  
  trace_msg("All assertion-based test passed!");
}