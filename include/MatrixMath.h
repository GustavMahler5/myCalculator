#include <iostream>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <sstream>

using namespace std;

#define SUCCESS (1)
#define ERROR (-1)
#define FP_DELTA 0.0001

// Absolute value helper function
double absoluteValue(double x);

// Our matrix arithmetic operations
void matrixPrint(double mat[3][3], ofstream& outputFile);
bool matrixEquals(double mat1[3][3], double mat2[3][3]);
void matrixAdd(double mat1[3][3], double mat2[3][3], double result[3][3]);
void matrixMultiply(double mat1[3][3], double mat2[3][3], double result[3][3]);
void matrixScalarAdd(double x, double mat[3][3], double result[3][3]);
void matrixScalarMultiply(double x, double mat[3][3], double result[3][3]);
double matrixTrace(double mat[3][3]);
void matrixTranspose(double mat[3][3], double result[3][3]);
void matrixSubmatrix(int x, int y, double mat[3][3], double result[2][2]);
double matrixDeterminant(double mat[3][3]);
double matrixDeterminantTwoByTwo(double mat[2][2]);
int matrixInverse(double mat[3][3], double result[3][3]);

