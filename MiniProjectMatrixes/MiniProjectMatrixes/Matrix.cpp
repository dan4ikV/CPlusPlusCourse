#include <iostream>
#include "Matrix.h"
//for formating cout (setw function)
#include <iomanip>
//for file reading
#include <fstream>
#include <sstream>
#include <vector>



using namespace std;

	Matrix::Matrix() {
		x = 1;
		y = 1;
		matrix = new double*[x];
		for (int i = 0; i < x; i++) {
			matrix[i] = new double[y];
			for (int j = 0; j < y; j++) {
				matrix[i][j] = 0;
			}
		}
	}
	Matrix::Matrix(int newX, int newY){
		x = newX;
		y = newY;
		matrix = new double* [x];
		for (int i = 0; i < x; i++) {
			matrix[i] = new double[y];
		}
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				matrix[i][j] = 0;
			}
		}
	}

	Matrix::Matrix(double** arr) {
		x = sizeof(arr) - 1;
		y = sizeof(arr[0]) - 1;
		matrix = new double* [x];
		for (int i = 0; i < x; i++) {
			matrix[i] = new double[y];
		}
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				matrix[i][j] = arr[i][j];
			}
		}
	}

	Matrix::Matrix(string fileName)
	{

		int tempX = 0;
		int tempY = 0;

		ifstream infile(fileName);
		string inFileLine;
		int index = 0;
		double infileElement;
		double* tempElementsHolder = nullptr;

		if (infile.is_open()) {
			if (infile.good()) {
				while (getline(infile, inFileLine))
				{
					tempX++;
					stringstream infileElementStream(inFileLine);
					tempY = 0;
					while (true)
					{
						infileElementStream >> infileElement;
						if (!infileElementStream)
							break;
						tempY++;
						double* tempArr = new double[index + 1];
						copy(tempElementsHolder, tempElementsHolder + index, tempArr);
						tempArr[index] = infileElement;
						tempElementsHolder = tempArr;
						index += 1;
					}
				}
			}
		}
		else {
			cout << "error opening file, creating 1x1 matrix with 0 value" << endl;
		}

		if (tempX == 0 || tempY == 0) {
			x = 1;
			y = 1;
			matrix = new double *[1];
			for (int i = 0; i < 1; i++) {
				matrix[i] = new double[1];
				for (int j = 0; j < 1; j++) {
					matrix[i][j] = 0;
				}
			}
			delete[] tempElementsHolder;
		}
		else {

			y = tempY;
			x = tempX;
			matrix = new double* [x];
			for (int i = 0; i < x; i++) {
				matrix[i] = new double[y];
			}
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					matrix[i][j] = tempElementsHolder[y*i+j];
				}
			}
			delete[] tempElementsHolder;
		}
	}


	Matrix::~Matrix() {
		for (int i = 0; i < x; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}

	Matrix::Matrix(const Matrix& other) {
		x = other.x;
		y = other.y;
		matrix = new double* [x];
		for (int i = 0; i < x; i++) {
			matrix[i] = new double[y];
		}
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				matrix[i][j] = other.matrix[i][j];
			}
		}
	}

	Matrix Matrix::transpose() {
		Matrix newMatrix(y, x);
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				newMatrix.setAt(j, i, matrix[i][j]);
			}
		}
		return newMatrix;
	}

	void Matrix::makeIdentity() {
		if (x == y) {
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					if (i == j) {
						matrix[i][j] = 1;
					}
					else {
						matrix[i][j] = 0;
					}
				}
			}
		}
		else {
			throw "Only square matrix can be an identity matrix;";
		}
	}

	int Matrix::getX() {
		return x;
	}

	int Matrix::getY() {
		return y;
	}

	double Matrix::getAt(int newX, int newY) {
		if (newX >= 0 && newX < x && newY >= 0 && newY < y) {
			return matrix[newX][newY];
		}
		else {
			throw "Index not found in matix";
		}
	}

	bool Matrix::setAt(int newX, int newY, double val) {
		if (newX >= 0 && newX < x && newY >= 0 && newY < y) {
			matrix[newX][newY] = val;
			return true;
		}
		else {
			return false;
		}
	}

	void Matrix::toString() {
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				cout << left << setw(3) << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	double Matrix::determinant() {
		if (x == y) {
			if (x == 1) {
				return matrix[0][0];
			}
			else {
				double det = 0;
				int sign = 1;
				for (int i = 0; i < x; i++) {
					Matrix tempMatrix(x - 1, y - 1);
					for (int k = 0; k < x - 1; k++) {
						for (int j = 0; j < x - 1; j++) {
							if (j < i) {
								tempMatrix.setAt(k, j, matrix[k + 1][j]);
							}
							else {
								tempMatrix.setAt(k, j, matrix[k + 1][j + 1]);
							}
						}
					}
					det += sign * matrix[0][i] * tempMatrix.determinant();
					sign = sign * -1;
				}
				return det;
			}
		}
		else {
			throw "non-square matrixes don't have determinants";
		}
	}

	Matrix Matrix::inverse(){
		if (x == y) {
			Matrix copy(*this);
			Matrix identity(x, y);
			for (int i = 0; i < x; i++) {
				identity.setAt(i, i, 1);
			}
			//creating zeroes on the left
			for (int i = 0; i < x; i++) {
				for (int j = i + 1; j < x; j++) {
					double factor = -(copy.getAt(j, i)) / copy.getAt(i, i);
					for (int k = 0; k < x; k++) {
						copy.setAt(j, k, copy.getAt(j, k) + factor * copy.getAt(i, k));
						identity.setAt(j, k, identity.getAt(j, k) + factor * identity.getAt(i, k));
					}
				}
			}

			//turning diagonal into 1
			for (int i = 0; i < x; i++) {
				double temp = copy.getAt(i, i);
				for(int j = 0; j < x; j++) {
					copy.setAt(i, j, copy.getAt(i, j) / temp);
					identity.setAt(i, j, identity.getAt(i, j) / temp);

				}
			}

			//creating zeroes on the right
			for (int i = x - 1; i >= 0; i--) {
				for (int j = i - 1; j >= 0; j--) {
					double factor = -(copy.getAt(j, i)) / copy.getAt(i, i);
					for (int k = 0; k < x; k++) {
						copy.setAt(j, k, copy.getAt(j, k) + factor * copy.getAt(i, k));
						identity.setAt(j, k, identity.getAt(j, k) + factor * identity.getAt(i, k));
					}
				}
			}
			return identity;
		}
		else {
			throw "Can't take inverse of a non-square matrix";
		}
	}

	Matrix Matrix::operator+(Matrix other) {
			if (x == other.getX() && y == other.getY()) {
				Matrix newMatrix(x, y);
				for (int i = 0; i < x; i++) {
					for (int j = 0; j < y; j++) {
						newMatrix.setAt(i, j, getAt(i, j) + other.getAt(i, j));
					}
				}
				return newMatrix;
			}
			else {
				throw "Size of matrixes not appropriate to add them!";
			}
	}

	Matrix Matrix::operator-(Matrix other) {
			if (x == other.getX() && y == other.getY()) {
				Matrix newMatrix(x, y);
				for (int i = 0; i < x; i++) {
					for (int j = 0; j < y; j++) {
						newMatrix.setAt(i, j, getAt(i, j) - other.getAt(i, j));
					}
				}
				return newMatrix;
			}
			else {
				throw "Size of matrixes not appropriate to substract them!";
			}
	}

	Matrix Matrix::operator*(Matrix other) {
			if (y == other.getX()) {
				Matrix newMatrix(x, other.getY());
				for (int i = 0; i < newMatrix.getX(); i++) {
					for (int j = 0; j < newMatrix.getY(); j++) {
						double temp = 0;
						for (int k = 0; k < y; k++) {
							temp += matrix[i][k] * other.getAt(k, j);
						}
						newMatrix.setAt(i, j, round(temp * 100000) / 100000);
					}
				}
				return newMatrix;
			}
			else {
				throw "Inappropriate matrix sizes for multiplication!";
			}
	}

	Matrix Matrix::operator*(double scalar) {
			Matrix newMatrix(x, y);
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					newMatrix.setAt(i, j, matrix[i][j] * scalar);
				}
			}
			return newMatrix;
	}

	void Matrix::operator=(const Matrix& other) {
		x = other.x;
		y = other.y;
		matrix = new double* [x];
		for (int i = 0; i < x; i++) {
			matrix[i] = new double[y];
		}
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				matrix[i][j] = other.matrix[i][j];
			}
		}
	}

	std::vector<double> Matrix::getRowVector(int x) {
		std::vector<double> temp(y);
		for (int i = 0; i < y; i++) {
			temp.at(i) = matrix[x][i];
		}
		return temp;
	}

	std::vector<double> Matrix::getColumnVector(int y) {
		std::vector<double> temp(x);
		for (int i = 0; i < x; i++) {
			temp.at(i) = matrix[i][y];
		}
		return temp;
	}

	Matrix Matrix::getRowVectorMatrix(int rowNum) {
		if (rowNum < x && rowNum >= 0) {
			Matrix newMatrix(1, y);
			for (int i = 0; i < y; i++) {
				newMatrix.setAt(0, i, matrix[rowNum][i]);
			}
			return newMatrix;
		}
		else {
			throw "Row number inapropriate!";
		}
	}

	Matrix Matrix::getColumnVectorMatrix(int colNum) {
		if (colNum < x && colNum >= 0) {
			Matrix newMatrix(1, x);
			for (int i = 0; i < x; i++) {
				newMatrix.setAt(0, i, matrix[i][colNum]);
			}
			return newMatrix;
		}
		else {
			throw "Column number inapropriate!";
		}
	}
