///////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Information & Policies > Academic Integrity Policy)
///////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// Nobody
//
// Name: Yiyan Huang
// login ID: y84huang
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// cs136_passed(assign_mrks, assign_cnt, style, midterm, final, quizzes)
//   returns true if CS136 was passed, given the sum of all assignment marks
//   (assign_mrks), the number of submitted assignments (assign_cnt), the style
//   mark, midterm, final, and overall quiz mark (quizzes), and false
//   otherwise.
// requires: all parameters must be non-negative
//           assign_cnt must be smaller than 10
int int_division_acc(int dividend, int divisor, int acc) {
  if (divisor > dividend && dividend > divisor / 2) {
    return acc + 1;
  } else if (divisor > dividend && dividend <= divisor / 2) {
    return acc;
  } else {
    return int_division_acc(dividend - divisor, divisor, acc + 1);
  }
}

int int_division(int dividend, int divisor) {
  return int_division_acc(dividend, divisor, 0);
}

bool cs136_passed(int assign_mrks, int assign_cnt, int style,
                  int midterm, int final, int quizzes) {
                    
  // your implementation goes here
  int assign_mark = int_division ((assign_mrks + style), (assign_cnt + 1));
                       
  int exam_component = int_division(midterm + final * 2, 3);
  
  int overall_mark = int_division((quizzes * 5) + (final * 50) + (midterm * 25) + 
                                  (assign_mark * 20), 100);
  
  if ((int)(assign_mark) >= 50 && (int)(exam_component) >= 50 && 
      assign_cnt >= 6 && (int)(overall_mark) >= 50 ) {
    return true;
  } else {
    return false;
  }
}

int main(void) {
  // public tests
  assert(cs136_passed(450, 9, 50, 50, 50, 50) == true);   // calculated mark: 50
  assert(cs136_passed(450, 9, 50, 50, 40, 100) == false); // calculated mark: 48
  
  // your additional tests go here
  assert(int_division(8, 3) == 3);
  assert(int_division(7, 3) == 2);
  assert(cs136_passed(445, 9, 10, 49, 57, 99) == false);  // calculated mark: 54
                                                          // assignment mark: 46
  trace_msg("All assertion-based tests passed!");
  return EXIT_SUCCESS;
}
