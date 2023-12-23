class Solution {
public:
    int getHeight(TreeNode* node, int& diameter) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = getHeight(node->left, diameter);
        int rightHeight = getHeight(node->right, diameter);

        // Update the diameter if necessary
        diameter = max(diameter, leftHeight + rightHeight);

        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        getHeight(root, diameter);

        return diameter;
    }
};
