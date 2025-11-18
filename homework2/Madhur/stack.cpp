// Time Complexity: O(1) for push, pop, top, isEmpty
// Space Complexity: O(n)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
    Node(int x) : data(x), link(nullptr) {}
};

class Stack {
private:
    Node* topPtr;

public:
    Stack() : topPtr(nullptr) {}

    bool isEmpty() {
        return topPtr == nullptr;
    }

    void push(int x) {
        Node* n = new Node(x);
        n->link = topPtr;
        topPtr = n;
    }

    int top() {
        return topPtr ? topPtr->data : -1;
    }

    int pop() {
        if (!topPtr) return -1;

        int val = topPtr->data;
        Node* temp = topPtr;

        topPtr = topPtr->link;
        delete temp;

        return val;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.isEmpty() << endl;

    return 0;
}
