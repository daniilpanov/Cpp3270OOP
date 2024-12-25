#pragma once
#include <string>

class Matrix
{
private:
	int size;
	double** matr;
public:
	Matrix(int);
	Matrix(Matrix&);
	~Matrix();
	double& operator()(int, int);
	void replaceCol(int n, double*);
	double determinant();
	std::string repr();
	int getLength();
};
