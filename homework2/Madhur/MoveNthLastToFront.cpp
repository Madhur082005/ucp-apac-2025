// Technique Used: Linked list fixed-distance two-pointer
// Time Complexity: O(n)
// Space Complexity: O(1)
// Time Spent: 16 minutes

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* buildList(vector<int>& arr) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int x : arr) {
        Node* temp = new Node(x);
        if (!head) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

Node* moveKthFromEnd(Node* head, int k) {
    if (!head || k <= 0) return head;

    Node* fast = head;
    Node* slow = head;

    for (int i = 0; i < k; i++) {
        if (!fast) return head;
        fast = fast->next;
    }

    if (!fast) return head;

    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    Node* nodeToMove = slow->next;
    slow->next = nodeToMove->next;

    nodeToMove->next = head;
    head = nodeToMove;

    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {15, 2, 8, 7, 20, 9, 11, 6, 19};

    Node* L1 = buildList(arr);
    Node* L2 = buildList(arr);

    L1 = moveKthFromEnd(L1, 2);
    L2 = moveKthFromEnd(L2, 7);

    printList(L1);
    printList(L2);

    return 0;
}
