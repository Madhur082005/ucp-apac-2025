// Technique Used: Two-pointer scan on sorted linked list
// Time Complexity: O(n)
// Space Complexity: O(1)
// Time Spent : 19 minutes 04 seconds

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr) {}
};

// Build linked list using a slightly different style
Node* buildList(const vector<int>& arr) {
    Node* head = nullptr;
    Node* current = nullptr;

    for (int x : arr) {
        Node* temp = new Node(x);

        if (head == nullptr) {
            head = temp;
            current = temp;
        } else {
            current->next = temp;
            current = temp;
        }
    }
    return head;
}

// Remove duplicates - different naming + slight restructuring
Node* deleteDuplicates(Node* head) {
    if (head == nullptr) return head;

    Node* walker = head;

    while (walker->next != nullptr) {
        if (walker->data == walker->next->data) {
            Node* nodeToDelete = walker->next;
            walker->next = walker->next->next;
            delete nodeToDelete;
        } else {
            walker = walker->next;
        }
    }

    return head;
}

// Print function same work, different formatting
void show(Node* head) {
    Node* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    vector<int> A = {1, 2, 2, 4, 5, 5, 5, 10, 10};
    vector<int> B = {8, 8, 8, 8};

    Node* L1 = buildList(A);
    Node* L2 = buildList(B);

    L1 = deleteDuplicates(L1);
    L2 = deleteDuplicates(L2);

    show(L1);
    show(L2);

    return 0;
}
