// Time Complexity:
// peek: O(1)
// enqueue: O(1)
// dequeue: O(1)
// isEmpty: O(1)

// Space Complexity: O(n)

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() : head(nullptr), tail(nullptr) {}

    int peek() {
        return head ? head->val : -1;
    }

    void enqueue(int x) {
        Node* n = new Node(x);

        if (!tail) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }

    int dequeue() {
        if (!head) return -1;

        int out = head->val;
        Node* nxt = head->next;

        delete head;
        head = nxt;

        if (!head) tail = nullptr;

        return out;
    }

    bool isEmpty() {
        return head == nullptr;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.peek() << endl;

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    cout << q.isEmpty() << endl;

    cout << q.dequeue() << endl;
    cout << q.isEmpty() << endl;

    return 0;
}
