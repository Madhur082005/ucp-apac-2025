/*
technique used:
- slow/fast cycle detection
- pointer catch-up to find cycle start

time complexity: O(n)
space complexity: O(1)
*/
// time spent: 20 minutes

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

void breakCycle(Node* head) {
    if (!head || !head->next) return;

    Node* slow = head;
    Node* fast = head;

    // detect cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) break;
    }

    if (!fast || !fast->next) return; // no cycle

    // move slow to head, find meeting point (start of cycle)
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    Node* startNode = slow;
    Node* ptr = startNode;

    // reach last node of cycle
    while (ptr->next != startNode) {
        ptr = ptr->next;
    }

    ptr->next = nullptr;
}

Node* buildList(const vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* p = head;

    for (int i = 1; i < arr.size(); i++) {
        p->next = new Node(arr[i]);
        p = p->next;
    }
    return head;
}

void makeCycle(Node* head, int fromVal, int toVal) {
    Node* from = nullptr;
    Node* to = nullptr;
    Node* p = head;

    while (p) {
        if (p->val == fromVal) from = p;
        if (p->val == toVal)   to = p;
        p = p->next;
    }

    if (from && to) from->next = to;
}

bool containsCycle(Node* head) {
    Node* s = head;
    Node* f = head;

    while (f && f->next) {
        s = s->next;
        f = f->next->next;
        if (s == f) return true;
    }
    return false;
}

int main() {

    vector<int> arr1 = {10,18,12,9,11,4};
    Node* head1 = buildList(arr1);
    makeCycle(head1, 4, 12);

    cout << "Before: " << (containsCycle(head1) ? "Cycle" : "No cycle") << "\n";
    breakCycle(head1);
    cout << "After : " << (containsCycle(head1) ? "Cycle" : "No cycle") << "\n";
    cout << "Test 1: " << (!containsCycle(head1) ? "PASS" : "FAIL") << "\n\n";

    vector<int> arr2 = {10,18,12,9,11,4};
    Node* head2 = buildList(arr2);
    makeCycle(head2, 4, 4);

    cout << "Before: " << (containsCycle(head2) ? "Cycle" : "No cycle") << "\n";
    breakCycle(head2);
    cout << "After : " << (containsCycle(head2) ? "Cycle" : "No cycle") << "\n";
    cout << "Test 2: " << (!containsCycle(head2) ? "PASS" : "FAIL") << "\n";

    return 0;
}
