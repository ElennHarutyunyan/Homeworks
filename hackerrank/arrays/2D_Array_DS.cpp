#include <iostream>
#include <vector>
using namespace std;

int hourglassSum(const vector<vector<int>>& arr) {
    int maxsum = -100; // Minimum possible hourglass sum
    for (size_t i = 0; i <= 3; i++) {
        for (size_t j = 0; j <= 3; j++) {
            int sum = arr[i][j] + arr[i][j+1] + arr[i][j+2]
                    + arr[i+1][j+1]
                    + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            maxsum = max(maxsum, sum);
        }
    }
    return maxsum;
}

int main() {
    vector<vector<int>> arr = {
        {1, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0},
        {0, 0, 2, 4, 4, 0},
        {0, 0, 0, 2, 0, 0},
        {0, 0, 1, 2, 4, 0}
    };

    cout << hourglassSum(arr) << endl; // Should print 19
    return 0;
}
