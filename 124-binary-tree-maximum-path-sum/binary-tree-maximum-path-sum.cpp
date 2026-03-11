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
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        // Suppose the path contains root.
        int globalAnswer = INT_MIN;
        helper(root, globalAnswer);
        return globalAnswer;
    }

    int helper(TreeNode* root, int& globalAnswer) {
        if (root == NULL) {
            return 0;
        }

        int leftSum = max(0, helper(root->left, globalAnswer));
        int rightSum = max(0, helper(root->right, globalAnswer));

        globalAnswer = max(globalAnswer, root->val + leftSum + rightSum);

        return root->val + max(leftSum, rightSum);
    }
};