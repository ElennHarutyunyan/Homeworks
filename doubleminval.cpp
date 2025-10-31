#include <iostream>
#include <iomanip>

int main() {
    unsigned long long bits = 1; 
    double d = *reinterpret_cast<double*>(&bits);

    std::cout << std::setprecision(20);
    std::cout << d << std::endl; 

    return 0;
}