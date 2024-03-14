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

#include "cs136-trace.h"
#include "grid.h"
#include <stdio.h>
#include <stdlib.h>

// Your additional includes go here.

// See grid.h for documentation.
const int GRID_MAX_SIZE = 100;

// See grid.h for documentation.
struct grid grid_create(int rows, int cols) {
    struct grid init;

    init.rows = rows;
    init.cols = cols;
    init.max_size = rows * cols;

    // Initialize the data array elements to 0
    for (int i = 0; i < GRID_MAX_SIZE; i++) {
        init.data[i] = 0;
    }

    return init;
}

// See grid.h for documentation.
int grid_rows(const struct grid *g) {
    // Your implementation goes here.
    return g->rows;
}

// See grid.h for documentation.
int grid_cols(const struct grid *g) {
    // Your implementation goes here.
    return g->cols;
}

// See grid.h for documentation.
bool grid_get(const struct grid *g, int row, int col, int *val) {
    // Your implementation goes here.
    if (row < g->rows && col < g->cols) {
       *val =  g->data[row  * g->cols + col];
        return true;
    } else {
        return false;
    }

}

// See grid.h for documentation.
bool grid_set(struct grid *g, int row, int col, int value) {
    // Your implementation goes here.
    if (row < g->rows && col < g->cols) {
        g->data[row  * g->cols + col] = value;
        return true;
    } else {
        return false;
    }
}

// See grid.h for documentation.
bool grid_resize(struct grid *g, int rows, int cols) {
    // Your implementation goes here.
    if (rows * cols <= GRID_MAX_SIZE) {

        int newVals[100] = {0};

        for (int i = 0; i < g->max_size; i++) {
            int rowPos = i / g->cols;
            int colPos = i % g->cols;

            if (colPos <= cols - 1 && rowPos <= rows - 1) {
                newVals[rowPos * cols + colPos] = g->data[rowPos * g->cols + colPos];
            } 
        }

        g->rows = rows;
        g->cols = cols;
        g->max_size = rows * cols;

        for (int i = 0; i < g->max_size; i++) {
            g->data[i] = newVals[i];
        }

        return true;
    } else {
        return false;
    }
}

// See grid.h for documentation.
// Additional specifications:
// * all columns shall have the width of the widest number
// * there shall be exactly one additional space separating numbers
// Examples:
// [0 0]       <- column width: 1
// [ 0 42]     <- column width: 2
// [42  2]     <- column width: 2
// [-2  2]     <- column width: 2
// [ 2 -2]     <- column width: 2
// [  0 -42]   <- column width: 3
// [ 136 -136] <- column width: 4
// [-136  136] <- column width: 4
void grid_print(const struct grid *g) {
    int maxWidth = 1;
    int charWidth[100];

    for (int i = 0; i < g->max_size; i++) {
        int temp = g->data[i];
        int curWidth = 1;

        if (temp < 0) {
            curWidth += 1;
        }

        while (abs(temp) >= 10) {
            temp /= 10;
            curWidth += 1;
        }

        charWidth[i] = curWidth;

        if (curWidth > maxWidth) {
            maxWidth = curWidth;
        }
    }

    for (int i = 0; i < g->max_size; i++) {
        if (i % g->cols == 0) {
            printf("[");
        }

        for (int j = 0; j < maxWidth - charWidth[i]; j++) {
            printf(" ");
        }

        printf("%d", g->data[i]);

        if ((i + 1) % g->cols == 0) {
            printf("]\n");
        } else {
            printf(" ");
        }
    }
}
