#include "MatrixMath.h"

int main(int argc, char* argv[]) {

    // If there are insufficient arguments to terminal, print usage and terminate program
	if (argc < 3) {
		cout << "Error. Usage: ./main inputFile outputFile" << endl;
		return 1;
	}

    // Open input and output files
	ifstream inputFile(argv[1]);
	ofstream outputFile(argv[2]);

    // Check if files have been properly opened. Terminate program if fail to open
	if (!inputFile.is_open()) {
		cout << "Error. Bad input file" << endl;
		return 1;
	} 
	if (!outputFile.is_open()) {
		cout << "Error. Bad output file" << endl;
		return 1;
	}


    // Declare matrices A and B
    double A[3][3];
    double B[3][3];

    // Read first matrix A
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!(inputFile >> A[i][j])) {
                cout << "Error. Bad input file" << endl;
                return 1;
            }
        }
    }

    // Read second matrix B
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!(inputFile >> B[i][j])) {
                cout << "Error. Bad input file" << endl;
                return 1;
            }
        }
    }

    inputFile.close();

    // Print matrices A and B to output file
    outputFile << "Printing Matrix A:" << endl;
    matrixPrint(A, outputFile);
    outputFile << "\nPrinting Matrix B:" << endl;
    matrixPrint(B, outputFile);

    // Test matrix equality
    outputFile << "\nTesting matrix equality:" << endl;
    if (matrixEquals(A, B)) {
        outputFile << "Matrix A and B are equal." << endl;
    }
    else {
        outputFile << "Matrix A and B are not equal." << endl;
    }

    // Perform matrix addition
    outputFile << "\nA + B:" << endl;
    double result[3][3];
    matrixAdd(A, B, result);
    matrixPrint(result, outputFile);

    // Perform matrix multiplication
    outputFile << "\nA * B:" << endl;
    matrixMultiply(A, B, result);
    matrixPrint(result, outputFile);

    // Perform scalar addition
    outputFile << "\nA + 2:" << endl;
    matrixScalarAdd(2, A, result);
    matrixPrint(result, outputFile);

    // Perform scalar multiplication
    outputFile << "\n2 * A:" << endl;
    matrixScalarMultiply(2, A, result);
    matrixPrint(result, outputFile);

    // Find the trace of A and B
    outputFile << "\nTrace of A: " << matrixTrace(A) << endl;
    outputFile << "Trace of B: " << matrixTrace(B) << endl;

    // Find the transpose of A and B
    outputFile << "\nTranspose of A:" << endl;
    matrixTranspose(A, result);
    matrixPrint(result, outputFile);
    outputFile << "\nTranspose of B:" << endl;
    matrixTranspose(B, result);
    matrixPrint(result, outputFile);

    // Find the determinant of A and B
    outputFile << "\nDeterminant of A: " << matrixDeterminant(A) << endl;
    outputFile << "Determinant of B: " << matrixDeterminant(B) << endl;

    // Find the inverse of A and B. If determinant is 0, print error message.
    outputFile << "\nInverse of A:" << endl;
    if (matrixInverse(A, result) == ERROR) {
        outputFile << "Cannot compute inverse of A. Determinant is 0." <<
        endl;
    }
    else {
        matrixPrint(result, outputFile);
    }

    outputFile << "\nInverse of B:" << endl;
    if (matrixInverse(B, result) == ERROR) {
        outputFile << "Cannot compute inverse of B. Determinant is 0." <<
        endl;
    }
    else {
        matrixPrint(result, outputFile);
    }

    outputFile.close();

    return 0;
}

