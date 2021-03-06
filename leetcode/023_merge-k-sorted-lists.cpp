//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

#include <iostream>
#include <vector>
#include <queue>

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
class Solution_023 {
public:
    // Heap
    // Exp: https://discuss.leetcode.com/topic/2780/a-java-solution-based-on-priority-queue
    // Time:	O(n*log(k))     n: # total elements;    k: size of the list
    // Space:	O(1)
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        priority_queue<ListNode*, vector<ListNode*>, cmp> min_heap;
        for (ListNode *node : lists)
            if (node) min_heap.push(node);
        while (!min_heap.empty()) {
            head = head->next = min_heap.top();
            min_heap.pop();
            if (head->next) min_heap.push(head->next);
        }
        return dummy->next;
    }

    struct cmp {
        bool operator()(ListNode *a, ListNode *b) {
            // min_heap
            return a->val > b->val;
        }
    };
};


//int main() {
//    vector<ListNode*> lists({NULL, NULL});
//    Solution_023 sol;
//    ListNode* result = sol.mergeKLists(lists);
//    cout << "##########" << endl;
//    while (result) {
//        cout << result->val << "\t";
//        result = result->next;
//    }
//    cout << "##########" << endl;
//}