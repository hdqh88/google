//Given a singly linked list, determine if it is a palindrome.
//
//Follow up:
//Could you do it in O(n) time and O(1) space?

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution_234 {
public:
    // Exp: https://discuss.leetcode.com/topic/18304/share-my-c-solution-o-n-time-and-o-1-memory
    // Time:	O(n)
    // Space:	O(1)
    bool isPalindrome(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while (slow != NULL) {
            if (head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *pre = NULL;
        ListNode *next = NULL;
        while (head != NULL) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }

    // Reverse half list.   My own.   Work but TLE
    // Time:	O(n)
    // Space:	O(1)
    bool isPalindrome1(ListNode *head) {
        if (!head) return true;
        int count = 0;
        ListNode *p = head, *q = nullptr, *tmp = nullptr;
        while (p) {
            count++;
            p = p->next;
        }
        p = head;
        for (int i = 0; i < count / 2; i++)
            p = p->next;
        q = p->next;
        while (q) {
            tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }
        for (int i = 0; i < count / 2; i++) {
            if (head->val != p->val) return false;
            head = head->next;
            p = p->next;
        }
        return true;
    }
};


//int main() {
//    ListNode* head = new ListNode(1);
//    ListNode* dummy = head;
//    dummy->next = new ListNode(0);
//    dummy = dummy->next;
//    dummy->next = new ListNode(0);
//    Solution_234 sol;
//    cout << sol.isPalindrome(head) << endl;
//}