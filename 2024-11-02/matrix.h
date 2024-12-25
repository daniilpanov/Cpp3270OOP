#include <iostream>
#include <string>

class Matrix
{
private:
    int size {0};
    double* matr {nullptr};
public:
    Matrix() = default;
	Matrix(int);
	Matrix(Matrix&);
	~Matrix();
    double& operator()(int, int);
    void operator=(Matrix&);
    void operator=(Matrix&&);
	void replaceCol(int n, double*);
	double determinant();
	std::string repr();
	int getLength();
};
