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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> answer;
        map<int, vector<int>> myMap;
        dfs(root, myMap, 0);

        for (auto it = myMap.rbegin(); it != myMap.rend(); ++it) {
            answer.push_back(it->second);
        }

        return answer;
    }

    void dfs(TreeNode* root, map<int, vector<int>>& myMap, int height) {
        if (root == nullptr) {
            return;
        }

        int value = root->val;
        myMap[height].push_back(value);

        dfs(root->left, myMap, height + 1);
        dfs(root->right, myMap, height + 1);
    }
};