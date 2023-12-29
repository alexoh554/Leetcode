/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 // Slow BFS Solution

 #include <queue>
 #include <vector>

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> q;

        TreeNode* cur = root;
        if (cur != nullptr) {
            q.push(cur);
        }
        vector<vector<int>> ans;

        while (!q.empty()) {
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                cur = q.front();
                q.pop();

                if (cur != nullptr) {
                    level.push_back(cur->val);

                    if (cur->left != nullptr) {
                        q.push(cur->left);
                    }
                    if (cur->right != nullptr) {
                        q.push(cur->right);
                    }
                }
            }
            ans.push_back(level);
        }

        return ans;
    }
};