#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/data_structures/matrix/matrix.c"

matrix *createMatrixFromArray(const int *a,

                              int nRows, int nCols) {

    matrix m = getMemMatrix(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++) {
            m.values[i][j] = a[k++];
        }
    return &m;
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

int test_output() {
    matrix *m = inputMatrices(
            (matrix *) (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5);
    outputMatrix(*m, (matrix **) m);
}

int test_outputs() {
    matrix *m = inputMatrices(
            (matrix *) (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5);
    outputMatrices(m, 2, (matrix **) m);
}

int test_swapRows() {
    matrix *m = createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5, 2);
    swapRows((matrix **) m, 2, 3);
}

int test_swapColums() {
    matrix *m = createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5, 2);
    swapColumns((matrix **) m, 2, 3);
}

int test_sortRowsByMinElement() {
    matrix *m = createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5, 2);

    sortRowsByMinElement((matrix ***) m, *m);
}

int test_sortColsByMinElement() {
    matrix *m = createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5, 2);

    sortColsByMinElement((matrix ***) m, *m, NULL, NULL);
}

int test_getSquareOfMatrixIfSymmetric() {
    matrix *m = createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5, 2);

    getSquareOfMatrixIfSymmetric((matrix *) m, *m, (matrix ***) m);
}

int test_transposeIfMatrixHasNotEqualSumOfRows() {
    matrix ***m = (matrix ***) createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5, 2);

    transposeIfMatrixHasNotEqualSumOfRows(*(matrix *) m, *m);
}

int test_isMutuallyInverseMatrices() {
    matrix *m1 = createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5, 2);
    matrix *m2 = createMatrixFromArray(
            (int[]) {
                    0, 0, 1,
                    1, 1, 1,
                    1, 1, 0,
                    1, 1, 1,
                    1, 0, 0,
            },
            5, 2);

    isMutuallyInverseMatrices(*m1, *m1, (matrix **) m2, (matrix **) m2);
}

int test_getMinInArea() {
    matrix ***m = (matrix ***) createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5, 2);

    getMinInArea(*(matrix *) m, *m);
}

int test_insertionSortRowsMatrixByRowCriteriaF() {
    matrix ***m = (matrix ***) createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5, 2);

    insertionSortRowsMatrixByRowCriteriaF(*(matrix *) m, m);
}

int test_countEqClassesByRowsSum() {
    matrix ***m = (matrix ***) createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5, 2);

    countEqClassesByRowsSum(*(matrix *) m, m);
}

int test_getNSpecialElement() {
    matrix ***m = (matrix ***) createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5, 2);

    getNSpecialElement(*(matrix *) m, m);
}

int test_swapPenultimateRow() {
    matrix ***m = (matrix ***) createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5, 2);

    swapPenultimateRow(*(matrix *) m, 3, m);
}

int test_countNonDescendingRowsMatrices() {
    matrix ***m = (matrix ***) createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5, 2);

    countNonDescendingRowsMatrices((matrix *) m, 3, (matrix **) m);
}

int test_printMatrixWithMaxZeroRows() {
    matrix ***m = (matrix ***) createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5, 2);

    printMatrixWithMaxZeroRows((matrix *) m, 3, m);
}

int test_normaMinMatrices() {
    matrix ***m = (matrix ***) createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5, 2);

    normaMinMatrices((matrix *) m, 3, (matrix **) m);
}

int test_getNSpecialElement2() {
    matrix ***m = (matrix ***) createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5, 2);

    getNSpecialElement2(*(matrix *) m, m);
}

int test_getScalarProductRowAndCol() {
    matrix ***m = (matrix ***) createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5, 2);

    getScalarProductRowAndCol(*(matrix *) m, 2, 5, m);
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
    test_output();
    test_outputs();
    test_swapRows();
    test_swapColums();
    test_sortRowsByMinElement();
    test_sortColsByMinElement();
    test_getSquareOfMatrixIfSymmetric();
    test_transposeIfMatrixHasNotEqualSumOfRows();
    test_isMutuallyInverseMatrices();
    test_getMinInArea();
    test_insertionSortRowsMatrixByRowCriteriaF();
    test_countEqClassesByRowsSum();
    test_swapPenultimateRow();
    test_countNonDescendingRowsMatrices();
    test_printMatrixWithMaxZeroRows();
    test_normaMinMatrices();
    test_getNSpecialElement2();
    test_getScalarProductRowAndCol();
}

int main() {
    test();
}
