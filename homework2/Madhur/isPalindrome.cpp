// Technique Used: DLL two-pointer inward check
// Time Complexity: O(n)
// Space Complexity: O(1)
// Time Spent: 15 minutes

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
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
            temp->prev = tail;
            tail = temp;
        }
    }
    return head;
}

bool checkPalindrome(Node* head) {
    if (!head) return true;

    Node* l = head;
    Node* r = head;

    while (r->next) r = r->next;

    while (l != r && l->prev != r) {
        if (l->data != r->data) return false;
        l = l->next;
        r = r->prev;
    }
    return true;
}

int main() {
    vector<int> v1 = {9, 2, 4, 2, 9};
    vector<int> v2 = {9, 12, 4, 2, 9};

    Node* L1 = buildList(v1);
    Node* L2 = buildList(v2);

    cout << (checkPalindrome(L1) ? "True" : "False") << endl;
    cout << (checkPalindrome(L2) ? "True" : "False") << endl;

    return 0;
}
