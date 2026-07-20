#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Function to remove all nodes with value = val
ListNode* removeElements(ListNode* head, int val) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode* curr = &dummy;

    while (curr->next != NULL) {
        if (curr->next->val == val) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }

    return dummy.next;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL)
            cout << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    ListNode* head = NULL;
    ListNode* tail = NULL;

    // Input linked list
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        ListNode* newNode = new ListNode(x);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int val;
    cin >> val;

    head = removeElements(head, val);

    printList(head);

    return 0;
}