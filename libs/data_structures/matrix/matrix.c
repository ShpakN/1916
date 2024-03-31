#include <malloc.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <intrin.h>
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

void freeMemMatrix(void **m, int n) {
    for (int i = 0; i < n; i++)
        free(m[i]);
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

int MaxWidth(matrix m, matrix **mm) {
    int maxWidth = 0;
    char buffer[64];

    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            sprintf(buffer, "%d", mm[i][j]);

            int w = strlen(buffer);
            if (w > maxWidth) {
                maxWidth = w;
            }
        }
    }

    return maxWidth;
}

void outputMatrix(matrix m, matrix **mm) {
    int w = MaxWidth(m, mm);
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            printf("%*d%c", w, mm[i][j], (j == m.nCols - 1) ? '\n' : ' ');
        }
    }
}

void outputMatrices(matrix *ms, int nMatrices, matrix **mm) {
    int w = MaxWidth(*ms, mm);
    for (int i = 0; i < ms->nRows; ++i) {
        for (int j = 0; j < ms->nCols; ++j) {
            printf("%*d%c", w, mm[i][j], (j == ms->nCols - 1) ? '\n' : ' ');
        }
    }
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
    int kr = 1;
    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nCols; j++)
            if (((i == j) && (mm[i][j] != 1)) || ((i != j) && (mm[i][j] != 0))) {
                kr = 0;
                break;
            }
        if (kr == 1) {
            return true;
        } else {
            return false;
        }
    }
}

bool issSymmetricMatrix(matrix *m, matrix ***mm) {
    int kr = 1;
    for (int i = 0; i < m->nRows - 1; ++i) {
        for (int j = i + 1; j < m->nCols; ++j) {
            if (mm[i][j] != mm[j][i]) {
                kr = 0;
                break;
            }
            if (kr == 1) {
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
                mm[j] = (matrix *) min;
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


void swapMaxMin(matrix ***m, int q, int n) {
    int maxI = 0, maxJ = 0, minI = 0, minJ = 0;

    for (int i = 0; i < q; i++)
        for (int j = 0; j < n; j++) {
            if (m[maxI][maxJ] < m[i][j]) {
                maxI = i;
                maxJ = j;
            }

            if (m[minI][minJ] > m[i][j]) {
                minI = i;
                minJ = j;
            }
        }

    struct matrix *tmp = m[maxI][maxJ];
    m[maxI][maxJ] = m[minI][minJ];
    m[minI][minJ] = tmp;
}


void sortRowsByMinElement(matrix ***mm, matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        struct matrix *max = &mm[i][0];

        for (int j = 1; j < mm; j++)
            if (mm[i][j] > max) {
                max = &mm[i][j];
            }

        mm[i] = max;
    }
}


void sortColsByMinElement(matrix ***mm, matrix m) {
    for (int i = 0; i < m.nCols; i++) {
        struct matrix *min = &mm[i][0];

        for (int j = 1; j < mm; j++)
            if (mm[i][j] < min) {
                min = &mm[i][j];
            }

        mm[i] = min;
    }
}


int mulMatrices(matrix ***m1, matrix m2) {
    int j;
    int f = 1;
    int i = 1;

    while (i <= m2.nRows && f) {
        j = 0;
        while (j < i && f) {
            if (m1[i][j] != m1[j][i]) {
                f = 0;
            } else {
                j++;
            }
        }

        if (f) {
            i++;
        }
    }

    return f;
}


void getSquareOfMatrixIfSymmetric(matrix *m, matrix m2, matrix ***mm) {
    int i, j, k;
    for (i = 0; i < m->nRows; i++) {
        for (j = 0; j < m->nCols; j++) {
            mm[i][j] = 0;

            if (mulMatrices((matrix ***) &m, m2)) {
                for (k = 0; k < mm; k++) {
                    mm[i][j] += mm[i][k] * mm[k][j];
                }
            }
        }
    }
}


void transposeIfMatrixHasNotEqualSumOfRows(matrix m, matrix **mm) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if ((m.values + m.values = m.values)) {
                mm[i][j] = mm[j][i];
            }
        }
    }
}


bool isMutuallyInverseMatrices(matrix m1, matrix m2, matrix **mm1, matrix **mm2) {
    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m1.nCols; j++) {
            for (int k = 0; i < m2.nRows; i++) {
                for (int l = 0; j < m2.nCols; j++) {
                    if (mm1[i][j] == -mm2[k][l]) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        }
    }
}


int getMinInArea(matrix m, matrix **mm) {
    matrix min = mm[0][0];
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if ((i < m.nRows / 2 && j >= i && j < m.nCols - i) ||
                (i >= m.nRows / 2 && j <= i && j >= m.nCols - i - 1)) {
                if (mm[i][j] < min)
                    min = mm[i][j];
            }
        }
    }
}


void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int), matrix ***mm) {
    for (int i = 0; i < m.nRows - 1; i++) {
        for (int j = i + 1; j < m.nCols; j++) {
            if (mm[i] > mm[j]) {
                for (int k = 0; k < m.nCols; k++) {
                    matrix *q = mm[i][k];
                    mm[i][k] = mm[j][k];
                    mm[j][k] = q;
                }
                matrix **w = mm[i];
                mm[i] = mm[j];
                mm[j] = w;
            }
        }
    }
}


int countEqClassesByRowsSum(matrix m, matrix ***mm) {
    int k = 0;

    for (int i = 0; i < m.nRows - 1; i++) {
        for (int j = i + 1; j < m.nCols; j++) {
            int g(int mm[i][j], int i);
            if (g(mm[i][j], i) == (g(mm[i][j], j)))
                k++;
        }
    }
}


int getNSpecialElement(matrix m, matrix ***mm) {
    int sum = 0;
    int k = 0;

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            sum = (int) (sum + mm[j][i]);
        }

        for (int a = 0; a < m.values; a++) {
            if (mm[a][i] > sum - mm[a][i]) {
                k++;
            }
        }
        sum = 0;
    }
}


void swapPenultimateRow(matrix m, int n, matrix ***mm) {
    int mini = 1;
    int minj = 1;

    for (int i = 1; i < m.nRows; i++) {
        for (int j = 1; j < m.nCols; j++) {
            if (mm[mini][minj] > mm[i][j]) {
                mini = i;
                minj = j;
            }
        }
    }
}


int countNonDescendingRowsMatrices(matrix *ms, int nMatrix, matrix **m) {
    int k = 0;

    for (int i = 0; i < ms->nRows; i++) {
        for (int j = i + 1; j < ms->nRows; j++) {
            if (m[i] < m[j]) {
                k++;
            }
        }
    }
}


void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix, matrix ***mm) {
    int *zeros = malloc((unsigned long long int) ms->values);
    int zeros_max = 0;
    for (int i = 0; i < ms->values; i++) {

        for (int j = 0; j < ms->values; j++) {
            if (mm[i][j] == 0) {
                zeros[i]++;
            }
        }

        if (zeros[i] > zeros_max) {
            zeros_max = zeros[i];
        }
    }
}


int normaMinMatrices(matrix *ms, int nMatrix, matrix **mm) {
    struct matrix min = mm[0][0];

    for (int i = 0; i < ms->nRows; i++) {
        for (int j = 0; j < ms->nCols; j++) {
            if (min < mm[i][j]) {
                min = mm[i][j];
            }
        }
    }
}


int getNSpecialElement2(matrix m, matrix ***mm) {
    int k = 0;

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            int q = 1;
            for (j = 0; j < i; j++) {
                q &= mm[k][j] < mm[k][i];
            }

            for (j = i + 1; j < m.nCols; j++) {
                q &= mm[k][j] > mm[k][i];
            }

            if (q) {
                k++;
            }
        }
    }
}


long long getScalarProductRowAndCol(matrix m, int i, int j, matrix ***mm) {
    int imaxRow = 0, jminCol = 0;
    for (i = 0; i < m.nRows; i++) {
        for (j = 0; j < m.nCols; j++) {
            if (mm[imaxRow][j] < mm[i][j])
                imaxRow = i;
            if (mm[i][jminCol] > mm[i][j])
                jminCol = j;
        }
    }

    int mult_rows = 0;
    for (i = 0; i < m.nRows; i++) {
        mult_rows += mm[imaxRow][i] * mm[i][jminCol];
    }
}
