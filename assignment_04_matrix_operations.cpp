// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
void printMatrix(const int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

void readMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void transposeMatrix(const int input[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = input[i][j];
        }
    }
}

void addMatrices(const int A[10][10], const int B[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrices(const int A[10][10], const int B[10][10], int result[10][10], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int rows, cols;

    cout << "--- PART A: Transpose Matrix ---" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int matA[10][10];
    readMatrix(matA, rows, cols);

    cout << "\nOriginal Matrix:\n";
    printMatrix(matA, rows, cols);

    int transposed[10][10];
    transposeMatrix(matA, transposed, rows, cols);

    cout << "\nTransposed Matrix:\n";
    printMatrix(transposed, cols, rows);

    cout << "\n--- PART B: Add Two Matrices ---" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int matB1[10][10], matB2[10][10], sumMat[10][10];
    cout << "\nEnter Matrix 1 elements:\n";
    readMatrix(matB1, rows, cols);

    cout << "\nEnter Matrix 2 elements:\n";
    readMatrix(matB2, rows, cols);

    addMatrices(matB1, matB2, sumMat, rows, cols);

    cout << "\nSum of Matrices:\n";
    printMatrix(sumMat, rows, cols);

    cout << "\n--- PART C: Multiply Two Matrices ---" << endl;
    int r1, c1, r2, c2;
    cout << "Enter rows for Matrix A: ";
    cin >> r1;
    cout << "Enter columns for Matrix A: ";
    cin >> c1;

    cout << "Enter rows for Matrix B: ";
    cin >> r2;
    cout << "Enter columns for Matrix B: ";
    cin >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible! Columns of A must equal rows of B." << endl;
        return 0;
    }

    int matC1[10][10], matC2[10][10], prodMat[10][10];
    cout << "\nEnter Matrix A elements:\n";
    readMatrix(matC1, r1, c1);

    cout << "\nEnter Matrix B elements:\n";
    readMatrix(matC2, r2, c2);

    multiplyMatrices(matC1, matC2, prodMat, r1, c1, c2);

    cout << "\nProduct of Matrix A and Matrix B:\n";
    printMatrix(prodMat, r1, c2);

    return 0;
}
