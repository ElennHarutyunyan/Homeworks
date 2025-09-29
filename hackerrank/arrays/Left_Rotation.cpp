#include <iostream>
#include <vector>
using namespace std;

vector<int> rotLeft(const vector<int>& a, int d) {
    size_t n = a.size();
    vector<int> result(n);
    for (size_t i = 0; i < n; i++) {
        size_t newIndex = (n + i - d % n) % n;
        result[newIndex] = a[i];
    }
    return result;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    int d = 2;
    vector<int> result = rotLeft(a, d);
    for (int x : result) cout << x << " ";
    cout << endl; // Output: 3 4 5 1 2
}


