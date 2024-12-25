#include <iostream>
#include <vector>
#include <ctime>
#include<cstdlib>
using namespace std;




void bubble(vector<int>& a) {
    for (int i = 0; i < a.size()-1; ++i) {
        bool swapped = false;
        for (int j = 0; j < a.size() - i - 1; ++j) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void choose(vector<int>& a) {
    for (int i = 0; i < a.size() - 1; ++i) {
        int index = i;
        for (int j = i + 1; j < a.size(); ++j) {
            if (a[j] < a[index]) index = j;
        }
        if (index != i) swap(a[i], a[index]);
    }
}


int main() {
    vector<int> a(10);
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        int num = rand() % 52;
        a[i] = num;
    }
    for (auto ch : a) cout << ch << ' ';
    cout << endl;
    bubble(a);
    for (auto el : a) cout << el << ' ';
    cout << endl;
    choose(a);
    for (auto el : a) cout << el << ' ';
}
