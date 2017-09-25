#include <iostream>
#include <vector>
#include <queue>

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
class Solution_102 {
public:
    //Level Order
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if (root) que.push(root);
        while (!que.empty()) {
            int num = que.size();
            vector<int> level;
            while (num-- > 0) {
                TreeNode *p = que.front();
                level.push_back(p->val);
                que.pop();
                if (p->left) que.push(p->left);
                if (p->right) que.push(p->right);
            }
            result.push_back(level);
        }
        return result;
    }
};