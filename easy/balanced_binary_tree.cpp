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

// Recursively traverse each node and see if they are balanced by calculating the height
// This one is hard as fuck

class Solution {
public:
    bool isBalanced(TreeNode* root) {

        if (getHeight(root) == -1){
            return false;
        }

        return true;

    }

    int getHeight(TreeNode*root) {
        if (root == NULL)
        {
            return 0;
        }
        int l = getHeight(root->left);
        int r = getHeight(root->right);

        if (l == -1 || r == -1) {
            return -1;
        }
        if (std::abs(l - r) > 1) {
            return -1;
        }
        return std::max(l, r) + 1;
    }
};
