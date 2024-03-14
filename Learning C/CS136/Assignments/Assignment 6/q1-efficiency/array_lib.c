///////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments >  Information & Policies > Academic Integrity Policy)
///////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// 
//
// Name: Yiyan Huang
// login ID: y84huang
///////////////////////////////////////////////////////////////////////////////

#include <assert.h>
#include <limits.h>
#include "array_lib.h"
#include "merge_sort.h"

// See array_lib.h for documentation.
bool k_in_row(const int arr[], int arr_len, int k) {
  assert(arr);
  assert(arr_len > 0);

  int maxCount = 1;
  int prev = arr[0];

  for (int i = 1; i < arr_len; ++i) {
    int count = 1;
    
    if (arr[i] == prev) {
      count += 1;
    } else {
      count = 1;
    }
    
    if (count > maxCount) {
      maxCount = count;
    }
  }
  
  return maxCount >= k;
}

// See array_lib.h for documentation.
int max_freq(int arr[], int arr_len) {
  assert(arr);
  assert(arr_len > 0);
  
  merge_sort(arr, arr_len);

  int prev = arr[0];
  int maxFreq = 1;
  int maxElement = INT_MIN;

  for (int i = 1; i < arr_len; i++) {
    int freq = 1;

    if (arr[i] == prev) {
      freq += 1;
    } else {
      freq = 1;
    }

    if (freq > maxFreq) {
      maxFreq = freq;
      maxElement = arr[i];
    }
  }

  return maxElement;
}

// See arrayfun.h for documentation.
int max_diff(const int arr[], int arr_len) {
  assert(arr);
  assert(arr_len > 0);
  
  int minVal = INT_MAX;
  int maxVal = INT_MIN;

  for (int i = 0; i < arr_len; ++i) {
    if (arr[i] < minVal) {
      minVal = arr[i];
    }

    if (arr[i] > maxVal) {
      maxVal = arr[i];
    }
  }

  return maxVal - minVal;
}

// See array_lib.h for documentation.
int max_val_idx(const int arr[], int arr_len) {
  assert(arr);
  assert(arr_len > 0);
  
  int max_idx = 0;
  int maxVal = arr[0];

  for (int i = 0; i < arr_len; ++i) {
    if (arr[i] > maxVal) {
      maxVal = arr[i];
      max_idx = i;
    }
  }

  return max_idx;
}

