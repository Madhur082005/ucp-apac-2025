// Time Complexity:
// insertAtFront: O(1)
// insertAtBack: O(n)
// insertAfter: O(1)
// insertBefore: O(n)
// deleteFront: O(1)
// deleteBack: O(n)
// deleteNode: O(n)
// length: O(n)
// reverseIterative: O(n)
// reverseRecursive: O(n)

// Space Complexity: O(1) (ignoring recursion frame)

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

Node* insertAtFront(Node* head, int x) {
    Node* n = new Node(x);
    n->next = head;
    return n;
}

Node* insertAtBack(Node* head, int x) {
    Node* n = new Node(x);
    if (!head) return n;

    Node* p = head;
    while (p->next) p = p->next;
    p->next = n;
    return head;
}

Node* insertAfter(Node* head, int x, Node* pos) {
    if (!pos) return head;

    Node* n = new Node(x);
    n->next = pos->next;
    pos->next = n;

    return head;
}

Node* insertBefore(Node* head, int x, Node* pos) {
    if (!pos) return head;
    if (head == pos) return insertAtFront(head, x);

    Node* p = head;
    while (p && p->next != pos) p = p->next;

    if (!p) return head;

    Node* n = new Node(x);
    n->next = pos;
    p->next = n;

    return head;
}

Node* deleteFront(Node* head) {
    if (!head) return nullptr;

    Node* nxt = head->next;
    delete head;
    return nxt;
}

Node* deleteBack(Node* head) {
    if (!head) return nullptr;

    if (!head->next) {
        delete head;
        return nullptr;
    }

    Node* p = head;
    while (p->next->next) p = p->next;

    delete p->next;
    p->next = nullptr;

    return head;
}

Node* deleteNode(Node* head, Node* pos) {
    if (!head || !pos) return head;

    if (head == pos) return deleteFront(head);

    Node* p = head;
    while (p && p->next != pos) p = p->next;

    if (!p) return head;

    p->next = pos->next;
    delete pos;

    return head;
}

int length(Node* head) {
    int cnt = 0;
    Node* p = head;

    while (p) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

Node* reverseIterative(Node* head) {
    Node* prev = nullptr;
    Node* cur = head;

    while (cur) {
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

Node* reverseRecHelper(Node* cur, Node* prev) {
    if (!cur) return prev;

    Node* nxt = cur->next;
    cur->next = prev;
    return reverseRecHelper(nxt, cur);
}

Node* reverseRecursive(Node* head) {
    return reverseRecHelper(head, nullptr);
}

void printList(Node* head) {
    Node* p = head;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << "\n";
}

int main() {
    Node* head = nullptr;

    head = insertAtFront(head, 3);
    head = insertAtFront(head, 2);
    head = insertAtFront(head, 1);

    head = insertAtBack(head, 4);
    head = insertAtBack(head, 5);

    printList(head);

    head = reverseIterative(head);
    printList(head);

    head = reverseRecursive(head);
    printList(head);

    cout << length(head) << endl;

    return 0;
}
