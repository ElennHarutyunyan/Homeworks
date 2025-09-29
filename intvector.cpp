#include <iostream>
#include <stdexcept>
using namespace std;

class MyVector{
private:
    int* data;
    int size;
    int capacity;

public:
    MyVector(int cap = 10){ // սկզբնական capacity 10
        data = new int[cap];
        size = 0;
        capacity = cap;
    }

    ~MyVector(){
        delete[] data;
    }

    int vecsize(){
        return size;
    }

    int veccap(){
        return capacity;
    }

    int& operator[](int index){
        if(index < 0 || index >= size){
            cout<<"index is not in range";
        }
        return data[index];
    }

    void pushback(int value){
        if(size == capacity){
            capacity = static_cast<int>(capacity * 1.6) + 1;
            int* newdata = new int[capacity];
            for(int i = 0; i < size; i++){
                newdata[i] = data[i];
            }
            delete[] data;
            data = newdata;
        }
        data[size++] = value;
    }

    void popback(){
        if(size > 0) size--;
    }
};

int main() {
    MyVector v;

    v.pushback(10);
    v.pushback(20);
    v.pushback(30);

    cout << "v[1] = " << v[1] << endl; // 20

    v.popback();
    cout << "Size after pop_back: " << v.vecsize() << endl; // 2

    return 0;
}