#include "MatrixMath.h"

// Return the absolute value
double absoluteValue(double x) {

    // Makes negative inputs positive.
    if (x < 0) {
        x = x * (-1);
    }
    return x;
}


// Add each element of a matrix and outputs the result.
void matrixPrint(double mat[3][3], ofstream& outputFile) {

    outputFile << "______________________";

    for (int i = 0; i < 3; i++) {
        outputFile << "\n|";
        for (int j = 0; j < 3; j++) {
            outputFile << mat[i][j] << " |";
        }
    }
    outputFile << "\n----------------------" << endl;
}


/*
Matrix A is equal to Matrix B if: 
|A[i][j] - B[i][j]| < FP_DELTA.
*/
bool matrixEquals(double mat1[3][3], double mat2[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            double x = (mat1[i][j]) - (mat2[i][j]);
            if (x < 0)
            {
                x = (-1) * x;
            }
            if ((x > FP_DELTA))
            {
                return false;
            }
        }
    }
    return true;
}


// Add each element of a matrix and outputs the result.
void matrixAdd(double mat1[3][3], double mat2[3][3], double result[3][3]) {
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}


// Performs matrix mutliplication via dot product.
void matrixMultiply(double mat1[3][3], double mat2[3][3], double result[3][3]) {

    double result_a = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                result_a += mat1[i][k] * mat2[k][j];
            }
            result[i][j] = result_a;
            result_a = 0;
        }
    }
}


// Add all elements of a matrix by a constant scalar.
void matrixScalarAdd(double x, double mat[3][3], double result[3][3]) {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = x + mat[i][j];
        }
    }
}


// Multiply all elements of a matrix by a constant scalar.
void matrixScalarMultiply(double x, double mat[3][3], double result[3][3]) {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = x * mat[i][j];
        }
    }
}


// Output the trace of a matrix via diagonal summation.
double matrixTrace(double mat[3][3]) {
    return mat[0][0] + mat[1][1] + mat[2][2];
}


// "Flip" the entries of the given matrix to give its transpose.
void matrixTranspose(double mat[3][3], double result[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = mat[j][i];
        }
    }
}


/**
 * This program uses separate variables denoting entries for the 3x3 to 2x2 matrix transfer.
 * If the 3x3 matrix variables (x, y) = (i, j), it skips the iteration without affecting the
 * submatrix variables (a, b). x and y iterates with the "skip" from i and j, while a and b
 * iterates "normally".
 **/
void matrixSubmatrix(int i, int j, double mat[3][3], double result[2][2]) {
    for (int x = 0, a = 0; x < 3; x++, a++) {
        if (x == i) {
            x++;
        }
        for (int y = 0, b = 0; y < 3 && x < 3; y++, b++) {
            if (y == j) {
                y++;
            }
            if (y > 2) {
                continue;
            }
            result[a][b] = mat[x][y];
            // Value verifaction testing:
            // printf("\n(%d, %d) gets the value %f\n", a, b, result[a][b]);
            // printf("\n(%d, %d) is now %f\n", x, y, mat[x][y]);
        }
    }
}


// Return the determinant of a 3x3 matrix via the "cross" method.
double matrixDeterminant(double mat[3][3]) {
    return (((mat[0][0]) * (mat[1][1]) * (mat[2][2])) +
            ((mat[0][1]) * (mat[1][2]) * (mat[2][0])) +
            ((mat[0][2]) * (mat[1][0]) * (mat[2][1])) -
            ((mat[0][2]) * (mat[1][1]) * (mat[2][0])) -
            ((mat[0][1]) * (mat[1][0]) * (mat[2][2])) -
            ((mat[0][0]) * (mat[1][2]) * (mat[2][1])));
}


// Determinant of a 2x2 matrix
double matrixDeterminantTwoByTwo(double mat[2][2]) {
    return (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
}


// This program gives the inverse of a matrix by comparing the "cross" method to the
// "cofactor expansion" method. If the determinant is 0, an error prints.
int matrixInverse(double mat[3][3], double result[3][3]) {

    double det = matrixDeterminant(mat);
    if (absoluteValue(det) <= FP_DELTA) {
        return ERROR;
    }
    else {

        double cofactor[3][3];
        double minor[2][2];
        double adjugate[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrixSubmatrix(i, j, mat, minor);
                if ((i + j) % 2 != 0) {
                    cofactor[i][j] = matrixDeterminantTwoByTwo(minor) * (-1);
                }
                else {
                    cofactor[i][j] = matrixDeterminantTwoByTwo(minor);
                }
            }
        }
        matrixTranspose(cofactor, adjugate);
        matrixScalarMultiply(1.0f / matrixDeterminant(mat), adjugate, result);
    }
    return SUCCESS;
}