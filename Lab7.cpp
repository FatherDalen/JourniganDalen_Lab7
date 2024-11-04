#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 4;

class Matrix {
private:
    int data[SIZE][SIZE];

public:
    // 1. Read values from a file into a matrix
    void readFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error opening file!" << endl;
            return;
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                file >> data[i][j];
            }
        }
        file.close();
    }

    // 2. Display a matrix
    void display() const {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // 3. Add two matrices with operator overloading
    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // 4. Multiply two matrices with operator overloading
    Matrix operator*(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < SIZE; ++k) {
                    result.data[i][j] += this->data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // 5. Get the sum of matrix diagonal elements
    int sumOfDiagonals() const {
        int mainDiagSum = 0, secDiagSum = 0;
        for (int i = 0; i < SIZE; ++i) {
            mainDiagSum += data[i][i];
            secDiagSum += data[i][SIZE - i - 1];
        }
        return mainDiagSum + secDiagSum;
    }

    // 6. Swap matrix rows
    void swapRows(int row1, int row2) {
        if (row1 < 0 || row1 >= SIZE || row2 < 0 || row2 >= SIZE) {
            cerr << "Invalid row indices!" << endl;
            return;
        }
        for (int j = 0; j < SIZE; ++j) {
            swap(data[row1][j], data[row2][j]);
        }
    }
};

int main() {
    Matrix mat1, mat2;

    // Load and display Matrix 1
    mat1.readFromFile("matrix1.txt");
    cout << "Matrix 1:" << endl;
    mat1.display();

    // Load and display Matrix 2
    mat2.readFromFile("matrix2.txt");
    cout << "Matrix 2:" << endl;
    mat2.display();

    // Addition of matrices
    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    sum.display();

    // Multiplication of matrices
    Matrix product = mat1 * mat2;
    cout << "Product of matrices:" << endl;
    product.display();

    // Sum of diagonals of Matrix 1
    cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

    // Swap rows in Matrix 1
    mat1.swapRows(0, 2);
    cout << "Matrix 1 after swapping rows 0 and 2:" << endl;
    mat1.display();

    return 0;
}