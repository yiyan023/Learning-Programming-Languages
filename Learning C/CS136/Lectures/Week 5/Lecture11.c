#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// swaps two numbers in a position 
void swap(int  *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// prints all the elements in an array
void print_arr(int a[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d", a[i]);
    }

    printf("\n");
}

// finds the index of the smallest number
int find_smallest_index(int arr[], int start, int len) {
    int smallest_index = 0;
    for (int i = start; i < len; ++i) {
        if (arr[i] < arr[smallest_index]) {
            smallest_index = i;
        }
    }
    return smallest_index;
}

// sorting algorithms:
    // selection sort, insertion sort, quicksort

    // selection sort
    // find the smallest item in the list & swap it with the first pisition, then find next smallest & keep going

void selection_sort(int arr[], int len) {
    int smallest_index = 0;
    for (int i = 0; i < len; ++i) {
        smallest_index = find_smallest_index(arr, i, len);
        print_array(arr, len);
        swap(&arr[i], &arr[smallest_index]);
    }
}

// insertion sort -- compares to all the values before it & inserts itself in the proper position
void insertion_sort(int a[], int len) {
    for (int i = 1; i < len; ++i) {
        for (int j = i; j > 0 && a[j - 1] > a[j]; --j) {
            swap(&a[j], &a[j - 1]);
        }
    }
}

// quicksort 
void quick_sort_range(int a[], int first, int last) {
    if (last <= first) return;

    int pivot = a[first];
    int pos = last;

    for (int i = last; i > first; --i) {
        if (a[i] > pivot) {
            swap(&a[pos],  &a[i]);
            --pos;
        }
    }

    swap(&a[first], &a[pos]);
    quick_sort_range(a, first, pos - 1);
    quick_sort_range(a, pos + 1, last);
}

void quick_sort(int a[], int len) {
    quick_sort_range(a, 0, len - 1);
}

// binary search
int binary_search(const int target, int arr[], int len) {
    int left = 0;
    int right = len - 1;

    while (right > left) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
}

// print a matrix 
void print_matrix(const int a[], const int width, const int height) {
    for (int i = 0; i < height; i ++) {
        printf("[");
        for (int j = 0; j < width; ++j) {
            print(" %d", a[j * i * width]);
        }
        printf("]");
    }
}

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    int *p = a + 4; //sets to the 4th index, which has a value of 5
    int x = *(p = p[-2]); //5 - 3 = 2

}