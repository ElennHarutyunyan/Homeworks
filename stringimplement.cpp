#include <iostream>
#include <cstring>

struct Small {
    static constexpr size_t SIZE = 23;
    char buffer[SIZE + 1]; 
};

struct Dynamic {
    char* ptr;   
    size_t capacity;
};

struct String {
    union {
        Small small;
        Dynamic dynamic;
    } data;

    size_t size;    
    bool is_dynamic; 
    String(const char* str) {
        size_t len = std::strlen(str);
        size = len;
        if (len <= Small::SIZE) {
            std::strcpy(data.small.buffer, str);
            is_dynamic = false;
        } else {
            data.dynamic.ptr = new char[len + 1];
            std::strcpy(data.dynamic.ptr, str);
            data.dynamic.capacity = len;
            is_dynamic = true;
        }
    }
    ~String() {
        if (is_dynamic) delete[] data.dynamic.ptr;
    }
    void print() const {
        if (is_dynamic) {
            std::cout << "[dynamic] " << data.dynamic.ptr << "\n";
        } else {
            std::cout << "[static] " << data.small.buffer << "\n";
        }
    }
};

int main() {
    String s1("Hello");
    String s2("This string is definitely longer than 23 bytes");

    s1.print();
    s2.print();
}
