#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};
class IntList {
private:
    Node* head;
    Node* tail;

public:
    IntList() : head(nullptr), tail(nullptr) {}
    ~IntList() { clear(); }
        void addFront(int value) {
        Node* n = new Node(value);
        n->next = head;
        if (head) head->prev = n;
        else tail = n;
        head = n;
    }
    void addBack(int value) {
        Node* n = new Node(value);
        n->prev = tail;
        if (tail) tail->next = n;
        else head = n; 
        tail = n;
    }

    void insertAfter(int key, int value) {
        Node* cur = head;
        while (cur && cur->data != key)
            cur = cur->next;
        if (!cur) return;
        Node* n = new Node(value);
        n->next = cur->next;
        n->prev = cur;
        if (cur->next) cur->next->prev = n;
        else tail = n;
        cur->next = n;
    }
    void insertBefore(int key, int value) {
        Node* cur = head;
        while (cur && cur->data != key)
            cur = cur->next;
        if (!cur) return; 
        Node* n = new Node(value);
        n->next = cur;
        n->prev = cur->prev;
        if (cur->prev) cur->prev->next = n;
        else head = n;
        cur->prev = n;
    }

    void remove(int value) {
        Node* cur = head;
        while (cur && cur->data != value)
            cur = cur->next;
        if (!cur) return; 
        if (cur->prev) cur->prev->next = cur->next;
        else head = cur->next;
        if (cur->next) cur->next->prev = cur->prev;
        else tail = cur->prev;
        delete cur;
    }

    void print() const {
        for (Node* p = head; p; p = p->next)
            cout << p->data << " ";
        cout << endl;
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};

int main() {
    IntList list;
    list.addBack(10);
    list.addBack(20);
    list.addBack(30);
    list.print();         

    list.addFront(5);
    list.print();        

    list.insertAfter(20, 25);
    list.print();        

    list.insertBefore(10, 8);
    list.print();        

    list.remove(25);
    list.print();       
}
