/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// If current node < p and q, go a certain way
// If current node > p and q, go another way
// if between, found ans

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        int l = p->val;
        int r = q->val;

        if (curr == nullptr) {
            return nullptr;
        }
        else if (curr->val < l && curr->val < r) {
            curr = lowestCommonAncestor(curr->right, p, q);
        }
        else if (curr->val > l && curr->val > r) {
            curr = lowestCommonAncestor(curr->left, p, q);
        }
        else {
            return curr;
        }

        return curr;
    }
};
