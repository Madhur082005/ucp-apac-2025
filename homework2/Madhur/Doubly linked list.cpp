// Time Complexity:  
// insertAtFront: O(1)
// insertAtBack: O(1)
// insertAfter: O(1)
// insertBefore: O(1)
// deleteFront: O(1)
// deleteBack: O(1)
// deleteNode: O(1)
// length: O(n)
// reverseIterative: O(n)
// reverseRecursive: O(n)

// Space Complexity: O(1) (except recursion stack)

#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
    Node* prev;
    Node(int x) : info(x), next(nullptr), prev(nullptr) {}
};

Node* insertAtFront(Node* head, int val) {
    Node* temp = new Node(val);
    if (!head) return temp;

    temp->next = head;
    head->prev = temp;
    return temp;
}

Node* insertAtBack(Node* head, Node* tail, int val) {
    Node* temp = new Node(val);
    if (!head) return temp;

    tail->next = temp;
    temp->prev = tail;
    return head;
}

Node* insertAfter(Node* head, int val, Node* loc) {
    if (!loc) return head;

    Node* temp = new Node(val);
    Node* nxt = loc->next;

    temp->next = nxt;
    temp->prev = loc;
    loc->next = temp;
    if (nxt) nxt->prev = temp;

    return head;
}

Node* insertBefore(Node* head, int val, Node* loc) {
    if (!loc) return head;

    if (loc->prev == nullptr)
        return insertAtFront(head, val);

    Node* prv = loc->prev;
    Node* temp = new Node(val);

    temp->next = loc;
    temp->prev = prv;
    prv->next = temp;
    loc->prev = temp;

    return head;
}

Node* deleteFront(Node* head) {
    if (!head) return nullptr;

    Node* nxt = head->next;
    delete head;

    if (nxt) nxt->prev = nullptr;
    return nxt;
}

Node* deleteBack(Node* head, Node* tail) {
    if (!tail) return nullptr;

    if (!tail->prev) {
        delete tail;
        return nullptr;
    }

    Node* newTail = tail->prev;
    newTail->next = nullptr;
    delete tail;

    return head;
}

Node* deleteNode(Node* head, Node* loc) {
    if (!head || !loc) return head;

    if (loc->prev == nullptr)
        return deleteFront(head);

    if (loc->next == nullptr)
        return deleteBack(head, loc);

    Node* prv = loc->prev;
    Node* nxt = loc->next;

    prv->next = nxt;
    nxt->prev = prv;

    delete loc;
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
    Node* curr = head;
    Node* last = nullptr;

    while (curr) {
        Node* nxt = curr->next;
        curr->next = curr->prev;
        curr->prev = nxt;

        last = curr;
        curr = nxt;
    }
    return last;
}

Node* reverseRecHelper(Node* curr, Node* prv) {
    if (!curr) return prv;

    Node* nxt = curr->next;
    curr->next = prv;
    curr->prev = nxt;

    return reverseRecHelper(nxt, curr);
}

Node* reverseRecursive(Node* head) {
    return reverseRecHelper(head, nullptr);
}

void printForward(Node* head) {
    Node* p = head;
    while (p) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << "\n";
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    head = insertAtFront(head, 2);
    head = insertAtFront(head, 1);

    tail = head;
    while (tail && tail->next)
        tail = tail->next;

    head = insertAtBack(head, tail, 3);
    tail = tail->next;

    head = insertAtBack(head, tail, 4);
    tail = tail->next;

    printForward(head);

    head = reverseIterative(head);
    printForward(head);

    head = reverseRecursive(head);
    printForward(head);

    cout << length(head) << "\n";

    return 0;
}
