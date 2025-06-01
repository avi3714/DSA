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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>answer;
        queue<TreeNode*>q;
        if(root==NULL)
        return answer;
        q.push(root);
        while(!q.empty())
        {
            vector<int>ans;
            int r=q.size();
            for(int i=0;i<r;i++)
            {
                TreeNode* node=q.front();
                ans.push_back(node->val);
                q.pop();
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);

            }
            if(answer.size()%2==1)
            reverse(ans.begin(),ans.end());
            answer.push_back(ans);


        }
        return answer;
        
    }
};