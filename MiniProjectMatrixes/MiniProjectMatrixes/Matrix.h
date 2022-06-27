#pragma once
#include <vector>

class Matrix {
private:
	double** matrix;
	int x;
	int y;

public:
	Matrix();
	~Matrix();
	Matrix(int x, int y);
	Matrix(double** arr);
	Matrix(std::string filename);
	Matrix(const Matrix& other);

	Matrix transpose();
	Matrix inverse();
	double determinant();
	void makeIdentity();

	int getX();
	int getY();
	bool setAt(int x, int y, double val);
	double getAt(int x, int y);

	void toString();
	double getMaxNum();

	Matrix operator+(Matrix other);
	Matrix operator-(Matrix other);
	Matrix operator*(Matrix other);
	Matrix operator*(double scalar);
	void operator=(const Matrix& other);

	std::vector<double> getRowVector(int rowNum);
	std::vector<double> getColumnVector(int columnNum);
	Matrix getRowVectorMatrix(int rowNum);
	Matrix getColumnVectorMatrix(int columnNum);
};