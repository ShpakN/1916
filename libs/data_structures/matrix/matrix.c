#include <malloc.h>
#include <stdbool.h>
#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return ((matrix) {values, nRows, nCols});
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(void *m, int n) {
    for (int i = 0; i < n; i++)
        free(m);
}

void freeMemMatrices(matrix **ms, int nMatrices) {

    for (int i = 0; i < nMatrices; i++)
        free(ms[i]);
    free(ms);
}

void inputMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; ++i) {
        for (int j = 0; j < m->nCols; ++j) {
            m = malloc(i * j * sizeof(int));
        }
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < ms->nRows; ++i) {
        for (int j = 0; j < ms->nCols; ++j) {
            ms = malloc(i * j * nMatrices * sizeof(int));
        }
    }
}

void outputMatrix(matrix m) {
    return inputMatrix(&m);
}

void outputMatrices(matrix *ms, int nMatrices) {
    return inputMatrices(ms, nMatrices);
}

void swapRows(matrix **m, int i1, int i2) {
    int *temp = (int *) m[i1];
    m[i1] = m[i2];
    m[i2] = (matrix *) temp;
}

void swapColumns(matrix **m, int j1, int j2) {
    struct matrix *temp = m[j1];
    m[j1] = m[j2];
    m[j2] = temp;
}

void insertionSortRowsMatrixByRowCriteria(matrix m, matrix ***mm, int (*criteria)(int *, int)) {
    for (int y = 0; y < m.nRows; y++) {
        for (int i = 0; i < (m.nRows - 1); i++) {
            if (mm[i][0] > mm[i + 1][0]) {
                for (int j = 0; j < m.nCols; j++) {
                    int x = (int) mm[i][j];
                    mm[i][j] = mm[i + 1][j];
                    mm[i + 1][j] = (matrix *) x;
                }
            }
        }
    }
}

void selectionSortColsMatrixByColCriteria(matrix m, matrix **mm, int (*criteria)(int *, int)) {
    for (int i = 0; i < m.nRows - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < m.nRows; j++)
            if (mm[j] < mm[minPos])
                minPos = j;
        swapColumns(mm, (int) &mm[i], (int) &mm[minPos]);
    }
}

bool isSquareMatrix(matrix *m, matrix **mm) {
    int size = m->nCols * m->nRows;
    for (int i = 0; i < size; i++) {
        if (mm[i] != mm[i / m->nCols * m->nRows + i % m->nCols]) {
            return false;
        }
    }
    return true;
}

bool areTwoMatricesEqual(matrix *m1, matrix *m2, matrix **mm1, matrix **mm2) {
    int size1 = m1->nCols * m1->nRows;
    int size2 = m2->nCols * m2->nRows;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (mm1[i] != mm2[j]) {
                return false;
            }
        }
        return true;
    }
}

bool isEMatrix(matrix *m, matrix ***mm) {
    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nCols; j++) {
            if (i == j && mm[i][j] != 1) {
                return true;
            } else {
                return false;
            }
        }
    }
}

bool issSymmetricMatrix(matrix *m, matrix ***mm) {
    for (int i = 0; i < m->nRows - 1; ++i) {
        for (int j = i + 1; j < m->nCols; ++j) {
            if (mm[i][j] == mm[j][i]) {
                return true;
            } else {
                return false;
            }
        }
    }
}

void transposeMatrix(matrix *m, matrix **mm1, matrix **mm2) {
    int i, j;
    for (i = 0; i < m->nRows; i++) {
        for (j = 0; j < m->nRows; j++) {
            mm1[i][j] = mm2[j][i];
        }
    }
}

void transposeSquareMatrix(matrix *m, matrix **mm1, matrix **mm2) {
    int i, j;
    for (i = 0; i < m->nRows; i++) {
        for (j = 0; j < m->nRows; j++) {
            if (isSquareMatrix(m, mm1)) {
                mm1[i][j] = mm2[j][i];
            }
        }
    }
}

position getMinValuePos(matrix *m, matrix ***mm) {
    for (int j = 0; j < m->nRows; ++j) {
        int min = 0;
        for (int i = 1; i < m->nCols; ++i) {
            if (mm[i][j] < mm[min][j]) {
                mm[j] = (matrix **) min;
            }
        }
    }
}

position getMaxValuePos(matrix m, matrix **mm) {
    struct matrix max;
    for (int i = 0; (int **) i < m.values; i++)
        for (int j = 0; (int **) j < m.values; j++)
            if ((i == 0 && j == 0) || mm[i][j] > max) {
                max = mm[i][j];
            }
}

