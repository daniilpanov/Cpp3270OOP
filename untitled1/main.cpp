#include <iostream>

using namespace std;
#include <vector>
#include <cmath>

double fact(int n) {
    double f = 1.0;
    for (int i = 1; i <= n; ++i) {
        f *= i;
    }
    return f;
}

double row_s(double x, double e) {
    int n = 0;
    double s = 0.0, a = 1.0;
    while (abs(a) > e) {
        a = pow(x, n)/fact(n);
        s += a;
        ++n;
    }
    return s;
}

bool contains(const vector<int> & arr, int x) {
    for (auto num : arr) {
        if (num == x) return true;
    }
    return false;
}


int main() {
    cout << "#1 " << row_s(5, 1e-5) << '\n';
    cout << "exp = " << exp(5) << '\n';
    int x;
    cin >> x;
    vector <int> arr = {1, 2, 3, 4, 5};
    if (contains(arr, x)) cout << "#2 " << "массив содержит данное число x";
    else cout << "#2 " << "массив не содержит данное число x";
    cout << endl;
}

