// Time Complexity: O(1) for all operations
// Space Complexity: O(n)
// Time Spent : 18 minutes 11 seconds

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;

    Node(int x) : val(x), prev(nullptr), next(nullptr) {}
};

class Deque {
private:
    Node* head;
    Node* tail;

public:
    Deque() : head(nullptr), tail(nullptr) {}

    bool isEmpty() {
        return head == nullptr;
    }

    int front() {
        return head ? head->val : -1;
    }

    int back() {
        return tail ? tail->val : -1;
    }

    void pushFront(int x) {
        Node* temp = new Node(x);
        if (!head) {
            head = tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    void pushBack(int x) {
        Node* temp = new Node(x);
        if (!tail) {
            head = tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    int popFront() {
        if (!head) return -1;

        int ans = head->val;
        Node* delNode = head;

        head = head->next;
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;

        delete delNode;
        return ans;
    }

    int popBack() {
        if (!tail) return -1;

        int ans = tail->val;
        Node* delNode = tail;

        tail = tail->prev;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;

        delete delNode;
        return ans;
    }
};

int main() {
    Deque dq;

    dq.pushFront(10);
    dq.pushBack(20);
    dq.pushFront(5);
    dq.pushBack(30);

    cout << dq.front() << endl;
    cout << dq.back() << endl;

    cout << dq.popFront() << endl;
    cout << dq.popBack() << endl;

    cout << dq.isEmpty() << endl;

    return 0;
}
