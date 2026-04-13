#include <iostream>
#include <math.h>

using namespace std;

class Calculator {

    float add(float x, float y) {}
    float subtract(float x, float y) {}
    float multiply(float x, float y) {}
    float divide(float x, float y) {}
    float exponent(float x, float y) {}
    float root(float x, float y) {}
    float log(float x, float y) {}
    int factorial(int x) {}

    void matrixPrint(float mat[3][3]) {}
    int matrixEquals(float mat1[3][3], float mat2[3][3]) {}
    void matrixAdd(float mat1[3][3], float mat2[3][3], float result[3][3]) {}
    void matrixMultiply(float mat1[3][3], float mat2[3][3], float result[3][3]) {}
    void matrixScalarAdd(float x, float mat[3][3], float result[3][3]) {}
    void matrixScalarMultiply(float x, float mat[3][3], float result[3][3]) {}
    float matrixTrace(float mat[3][3]) {}
    void matrixTranspose(float mat[3][3], float result[3][3]) {}
    void matrixSubmatrix(int x, int y, float mat[3][3], float result[2][2]) {}
    float matrixDeterminant(float mat[3][3]) {}
    void matrixInverse(float mat[3][3], float result[3][3]) {}
    
};
