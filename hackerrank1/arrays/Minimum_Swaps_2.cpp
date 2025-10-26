#include <iostream>
#include <vector>
using namespace std;

int minimumSwaps(vector<int> arr) {
    int swaps = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        while (arr[i] != static_cast<int>(i) + 1) {
            swap(arr[i], arr[arr[i] - 1]);
            swaps++;
        }
    }
    return swaps;
}

int main() {
    vector<int> arr = {4, 3, 1, 2};
    cout << minimumSwaps(arr) << endl; // Output: 3
}
