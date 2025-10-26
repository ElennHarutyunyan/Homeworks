#include <iostream>
#include <vector>
using namespace std;

long arrayManipulation(int n, const vector<vector<int>>& queries) {
    vector<long> arr(n + 1, 0);

    for (const auto& q : queries) {
        int start = q[0] - 1; 
        int end = q[1];       
        long value = q[2];    

        arr[start] += value;  
        arr[end] -= value;    
    }
    long max_val = 0;
    long current = 0;
    for (int i = 0; i < n; i++) {
        current += arr[i];        
        if (current > max_val) {
            max_val = current;    
        }
    }

    return max_val;
}

int main() {
    int n = 5;
    vector<vector<int>> queries = {{1,2,100}, {2,5,100}, {3,4,100}};
    cout << arrayManipulation(n, queries) << endl; // 200
}
