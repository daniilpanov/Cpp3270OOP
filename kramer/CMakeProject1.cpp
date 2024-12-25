// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "CMakeProject1.h"
#include <math.h>
#include "matrix.h"

using namespace std;

double* solve(Matrix&, double* vect);

int main()
{
    setlocale(LC_ALL, "RU");
    int n;
    cout << "Введите размер левой матрицы\n";
    cin >> n;
    Matrix matr{ n };
    double* vect = new double[n];
    cout << "Введите расширенную матрицу\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matr(j, i);
        }
        cin >> vect[i];
    }

    cout << "Введенная матрица: \n" << matr.repr() << endl;
    cout << "Введенный вектор: \n";
    for (int i = 0; i < n; i++) cout << vect[i] << endl;
    cout << endl;

    double* res = solve(matr, vect);

    cout << "Вектор-результат: \n";

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << endl;
    }
}

double* solve(Matrix& const matr, double* vect) {
    int size = matr.getLength();
    double* res = new double[size];
    double det = matr.determinant();

    for (int i = 0; i < size; i++)
    {
        Matrix tmpMatr{ matr };
        tmpMatr.replaceCol(i, vect);
        res[i] = tmpMatr.determinant() / det;
    }
    return res;
}