#include <iostream>
#include <vector>
using namespace std;
int binarysearch(vector<int> &arr, int x){
    int low = 0;
    int high = arr.size() - 1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == x)
            return mid;
        else if(x > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
   return -1; 
}
int main(){
    vector<int> arr = {4,7,8,45,68,98,99,102,111};
    int x = 45;
    int res = binarysearch(arr, x);

    if(res == -1){
        cout << "Don't have element";
    } else {
        cout << "Found at index: " << res;
    }

    return 0;
}