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

        map<int,map<int,multiset<int>>> st; // {xaxis, {level, val}}
        queue<pair<TreeNode*, pair<int, int>>> q; // {node, {xaxis, level}}

        q.push({root, {0, 0}});

        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int xaxis = q.front().second.first;
            int level = q.front().second.second;
            q.pop();
            st[xaxis][level].insert(node->val);

            if (node->left)
                q.push({node->left, {xaxis - 1, level + 1}});
            if (node->right)
                q.push({node->right, {xaxis + 1, level + 1}});
        }

       for(auto it:st)
       {
        vector<int>col;
        for(auto it2:it.second)
        {
            col.insert(col.end(),it2.second.begin(),it2.second.end());
        }
        ans.push_back(col);
       }

      
        return ans;
        }

    
};
