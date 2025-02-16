#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct {
    int row;
    int col;
    int value;
} SparseMatrix;

void readSparseMatrix(SparseMatrix sm[], int *size) {
    int i, rows, cols, nonZero;
    printf("Enter the number of rows, columns and non-zero elements: ");
    scanf("%d%d%d", &rows, &cols, &nonZero);
    
    sm[0].row = rows;
    sm[0].col = cols;
    sm[0].value = nonZero;
    *size = nonZero + 1;
    
    for (i = 1; i <= nonZero; i++) {
        printf("Enter row, column and value for element %d: ", i);
        scanf("%d%d%d", &sm[i].row, &sm[i].col, &sm[i].value);
    }
}

void printSparseMatrix(SparseMatrix sm[]) {
    int i;
    int size = sm[0].value;
    printf("Sparse Matrix Representation:\n");
    printf("Row\tColumn\tValue\n");
    for (i = 0; i <= size; i++) {
        printf("%d\t%d\t%d\n", sm[i].row, sm[i].col, sm[i].value);
    }
}

void simpleTranspose(SparseMatrix sm[], SparseMatrix transpose[]) {
    int i, j, size;
    transpose[0].row = sm[0].col;
    transpose[0].col = sm[0].row;
    transpose[0].value = sm[0].value;
    size = sm[0].value;

    int k = 1;
    for (i = 0; i < sm[0].col; i++) {
        for (j = 1; j <= size; j++) {
            if (sm[j].col == i) {
                transpose[k].row = sm[j].col;
                transpose[k].col = sm[j].row;
                transpose[k].value = sm[j].value;
                k++;
            }
        }
    }
}

void fastTranspose(SparseMatrix sm[], SparseMatrix transpose[]) {
    int rowTerms[MAX], startingPos[MAX];
    int i, j, numCols = sm[0].col, numTerms = sm[0].value;
    
    transpose[0].row = numCols;
    transpose[0].col = sm[0].row;
    transpose[0].value = numTerms;

    if (numTerms > 0) {
        for (i = 0; i < numCols; i++)
            rowTerms[i] = 0;

        for (i = 1; i <= numTerms; i++)
            rowTerms[sm[i].col]++;

        startingPos[0] = 1;
        for (i = 1; i < numCols; i++)
            startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];

        for (i = 1; i <= numTerms; i++) {
            j = startingPos[sm[i].col]++;
            transpose[j].row = sm[i].col;
            transpose[j].col = sm[i].row;
            transpose[j].value = sm[i].value;
        }
    }
}

int main() {
    SparseMatrix sm[MAX], transpose[MAX];
    int size;
    
    readSparseMatrix(sm, &size);
    
    printf("\nOriginal Sparse Matrix:\n");
    printSparseMatrix(sm);
    
    simpleTranspose(sm, transpose);
    printf("\nSimple Transpose of Sparse Matrix:\n");
    printSparseMatrix(transpose);
    
    fastTranspose(sm, transpose);
    printf("\nFast Transpose of Sparse Matrix:\n");
    printSparseMatrix(transpose);
    
    return 0;
}
