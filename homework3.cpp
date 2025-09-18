#include <iostream>
using namespace std;

int main() {
    int arr[6] = {1, 1, 2, 3, 2, 5};
    int n = 6;
    int xorAll = 0;
    for (int i = 0; i < n; i++) {
        xorAll ^= arr[i];
    }
    int bitValue = 1;
    while ((xorAll / bitValue) % 2 == 0) { 
        bitValue *= 2;
    }
    int group1[6], group2[6];
    int g1 = 0, g2 = 0;

    for (int i = 0; i < n; i++) {
        if ((arr[i] / bitValue) % 2 == 0)
            group1[g1++] = arr[i]; 
        else
            group2[g2++] = arr[i]; 
    }
    int num1 = 0;
    int num2 = 0;

    for (int i = 0; i < g1; i++)  
        num1 ^= group1[i];

    for (int i = 0; i < g2; i++) 
        num2 ^= group2[i];

    cout << "The two unique numbers are: " << num1 << " and " << num2 << endl;

    return 0;
}
