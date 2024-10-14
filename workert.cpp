#include <stdio.h>

#define SIZE 5

// Function to add two matrices
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0; // Initialize result cell to 0
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int m[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = m[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int m[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Define two 5x5 matrices
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    int result[SIZE][SIZE]; // Matrix to store results

    // Perform matrix addition
    printf("Matrix Addition:\n");
    addMatrices(m1, m2, result);
    printMatrix(result);
    printf("\n");

    // Perform matrix multiplication
    printf("Matrix Multiplication:\n");
    multiplyMatrices(m1, m2, result);
    printMatrix(result);
    printf("\n");

    // Perform matrix transposition on the first matrix
    printf("Transpose of Matrix 1:\n");
    transposeMatrix(m1, result);
    printMatrix(result);
    printf("\n");

    return 0;
}
