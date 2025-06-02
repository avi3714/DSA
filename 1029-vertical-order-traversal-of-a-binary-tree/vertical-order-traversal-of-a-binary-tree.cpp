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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        multiset<pair<int, pair<int, int>>> st; // {xaxis, {level, val}}
        queue<pair<TreeNode*, pair<int, int>>> q; // {node, {xaxis, level}}

        q.push({root, {0, 0}});

        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int xaxis = q.front().second.first;
            int level = q.front().second.second;
            q.pop();

            st.insert({xaxis, {level, node->val}});

            if (node->left)
                q.push({node->left, {xaxis - 1, level + 1}});
            if (node->right)
                q.push({node->right, {xaxis + 1, level + 1}});
        }

        // Determine min and max x-axis
        int minX = INT_MAX, maxX = INT_MIN;
        for (auto& it : st) {
            minX = min(minX, it.first);
            maxX = max(maxX, it.first);
        }

        int totalCols = maxX - minX + 1;
        ans.resize(totalCols); // Resize answer vector to hold all verticals

        for (auto& it : st) {
            int x = it.first;
            int val = it.second.second;
            ans[x - minX].push_back(val); // shift x to 0-based index
        }

        return ans;
    }
};
