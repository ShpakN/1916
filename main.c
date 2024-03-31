#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/data_structures/matrix/matrix.c"

matrix * createMatrixFromArray(const int *a,

                               int nRows, int nCols) {

    matrix *m = getMemMatrix(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++) {
            m->values[i][j] = a[k++];
        }
    return m;
}

int test_countZeroRows() {
    matrix *m = createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5, 3
    );
    assert(test_countZeroRows(m, 5, 3) == 2);
    freeMemMatrices(m, 5);
}

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (size_t k = 0; k < nMatrices; k++)
        for (size_t i = 0; i < nRows; i++)
            for (size_t j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}

void test() {
    test_countZeroRows();
}

int main() {
    test();
}

