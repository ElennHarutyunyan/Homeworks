#include <iostream>

int main() {
    int check = 0;
    int arr[9] = {0,1,3,8,7,7,1,0,8};
    for(int i=0;i<=9;i++){
       check = check xor arr[i];//nuyn biter 0 tarber bitery 1
    }
    std::cout<<"THe number that don't repeat is = "<<check<<std::endl;

    return 0;
}