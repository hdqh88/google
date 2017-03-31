//Given a binary tree, determine if it is a valid binary search tree (BST).
//
//Assume a BST is defined as follows:
//
//    The left subtree of a node contains only nodes with keys less than the node's key.
//    The right subtree of a node contains only nodes with keys greater than the node's key.
//    Both the left and right subtrees must also be binary search trees.
//Example 1:
//      2
//     / \
//    1   3
//Binary tree [2,1,3], return true.
//Example 2:
//      1
//     / \
//    2   3
//Binary tree [1,2,3], return false.

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution_098 {
public:
    // Inorder  Recursive
    // Time:	O(n)
    // Space:	O(1)
    bool isValidBST(TreeNode *root) {
        TreeNode *prev = nullptr;
        return helper(root, prev);
    }

    bool helper(TreeNode *node, TreeNode *&prev) {
        if (!node) return true;
        if (!helper(node->left, prev)) return false;
        if (prev && prev->val >= node->val) return false;
        prev = node;
        return helper(node->right, prev);
    }


    // Inorder  Iterative   FASTER
    // Time:	O(n)
    // Space:	O(n)
    bool isValidBST_1(TreeNode *root) {
        if (!root) return true;
        stack<TreeNode *> stk;
        TreeNode *prev = nullptr;
        while (root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;
            } else {
                root = stk.top();
                stk.pop();
                if (prev && prev->val >= root->val) return false;
                prev = root;
                root = root->right;
            }
        }
        return true;
    }
};