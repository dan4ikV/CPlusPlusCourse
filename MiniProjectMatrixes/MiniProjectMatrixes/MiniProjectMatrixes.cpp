// MiniProjectMatrixes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    cout << "creating a matrix with default constructor, the defaul value is 1x1 matrix with 0 value:" << endl;
    cout << "m1:" << endl;
    Matrix m1;
    m1.toString();

    cout << "creating a matrix of size 3x4:" << endl;
    cout << "m2:" << endl;
    Matrix m2(3, 4);
    m2.toString();

    cout << "Editing the values of the created matrix:" << endl;
    cout << "Edited m2:" << endl;
    m2.setAt(0, 0, 0);
    m2.setAt(0, 1, 1);
    m2.setAt(0, 2, 2);
    m2.setAt(0, 3, 3);
    m2.setAt(1, 0, 1);
    m2.setAt(1, 1, 2);
    m2.setAt(1, 2, 3);
    m2.setAt(1, 3, 4);
    m2.setAt(2, 0, 2);
    m2.setAt(2, 1, 3);
    m2.setAt(2, 2, 4);
    m2.setAt(2, 3, 5);
    m2.toString();

    cout << "Transposition of a matrix:" << endl;
    cout << "m3 = m2.transpose:" << endl;
    Matrix m3 = m2.transpose();
    m3.toString();

    cout << "Multiplying two previous matrixes:" << endl;
    cout << "m3 * m2 = " << endl;
    (m2 * m3).toString();

    cout << "Creating a matrix from an array:" << endl;
    cout << "m4" << endl;
    double** arr = new double* [3];
    for (int i = 0; i < 3; i++) {
        arr[i] = new double[3];
        for (int j = 0; j < 3; j++) {
            arr[i][j] = j + j;
        }
    }
    Matrix m4(arr);
    m4.toString();

    cout << "Creating a matrix from a multiplication of 2 matrixes:" << endl;
    cout << "m5 = m2 * m3" << endl;
    Matrix m5 = m2 * m3;
    m5.toString();

    cout << "Matrix addition:" << endl;
    cout << "m5 + m4" << endl;
    (m5 + m4).toString();

    cout << "Determinant of m4 is zero because it has a column of zeroes:" << endl;
    cout << "m4.determinant";
    cout << m4.determinant() << endl;

    cout << "m5 edited:" << endl;
    m5.setAt(0, 2, 3);
    m5.toString();
    cout << "m5 determinant: " << endl;
    cout << m5.determinant() << endl << endl;

    cout << "m5 inverse: " << endl;
    m5.inverse().toString();
    cout << "multiplying m5 by it's inverse we recieve an identity matrix:" << endl;
    (m5 * m5.inverse()).toString();

    cout << "matrix m6 - from a file with integers:" << endl;
    Matrix m6("C:/Users/danyl/source/repos/MiniProjectMatrixes/MiniProjectMatrixes/integerMatrix.txt");
    m6.toString();

    cout << "matrix m7 from a file with doubles:" << endl;
    Matrix m7("C:/Users/danyl/source/repos/MiniProjectMatrixes/MiniProjectMatrixes/doubleMatrix.txt");
    m7.toString();

    cout << "m8 = m7 - m6 (testing substract operator overloading and functioning)" << endl;
    Matrix m8 = m7 - m6;
    m8.toString();

    cout << "Multiplying m6 by a scalar (2):" << endl;
    (m6 * 2).toString();

    cout << "Printing second row of m8" << endl;
    vector<double> row = m8.getRowVector(1);
    for (int i = 0; i < row.size(); i++) {
        cout << row.at(i) << " ";
    }
    cout << endl << endl;

    cout << "Printing second column of m8" << endl;
    vector<double> col = m8.getColumnVector(1);
    for (int i = 0; i < col.size(); i++) {
        cout << col.at(i) << " ";
    }
    cout << endl << endl;


    cout << "Trying to get 7th column: " << endl;
    try {
        m8.getColumnVectorMatrix(7).toString();
    }
    catch (const char* err) {
        cout << err;
    }

    cout << endl << endl << "Printing the 2nd row" << endl;
    try {
        m8.getRowVectorMatrix(1).toString();
    }
    catch (const char* err) {
        cout << err;
    }

    cout << "Turning a matrix to an identity matrix: " << endl;
    m6.makeIdentity();
    m6.toString();
    
    cout << "Trying to multiply a non-square matrix by itself:" << endl;
    try {
        (m3 * m3).toString();
    }
    catch (const char* err) {
        cout << err;
    }
    cout << endl << endl;
}