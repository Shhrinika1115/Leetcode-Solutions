#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Reverse the linked list
ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;

    while (head != NULL) {
        ListNode* nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }

    return prev;
}

// Check if the linked list is a palindrome
bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;

    ListNode* slow = head;
    ListNode* fast = head;

    // Find the middle of the list
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half
    ListNode* secondHalf = reverse(slow);
    ListNode* firstHalf = head;

    // Compare both halves
    while (secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val)
            return false;

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    ListNode* head = NULL;
    ListNode* tail = NULL;

    cout << "Enter node values: ";

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        ListNode* newNode = new ListNode(x);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if (isPalindrome(head))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}