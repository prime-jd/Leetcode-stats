#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head; // Base case: 0 or 1 element

        // Split the list into two halves
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr; // Break the list into two halves

        // Recursively sort each half
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        return merge(l1, l2);
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next; 
        }
        if (l1) temp->next = l1;
        if (l2) temp->next = l2;

        ListNode* sortedHead = dummy->next;
        delete dummy; // Free the dummy node
        return sortedHead;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const vector<int>& values) {
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;
    for (int value : values) {
        temp->next = new ListNode(value);
        temp = temp->next;
    }
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}

int main() {
    Solution solution;
    vector<int> values = {4, 2, 1, 3};
    ListNode* head = createList(values);

    cout << "Original list: ";
    printList(head);

    head = solution.sortList(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
