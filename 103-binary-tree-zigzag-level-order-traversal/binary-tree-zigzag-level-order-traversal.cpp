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
        stack<int>st;
        int count=0;
        if(root==NULL)
        return answer;
        q.push(root);
        while(!q.empty())
        {
            
            int r=q.size();
            vector<int>ans(r,-1);
            for(int i=0;i<r;i++)
              {
                TreeNode* node=q.front();
                q.pop();
              if(count%2==0)
                ans[i]=(node->val);
                else
                ans[r-1-i]=node->val;
                if(node->left)
                {
                     q.push(node->left);
                
                }
                if(node->right)
                {
                 q.push(node->right);
                
                }

            }
            count++;
            answer.push_back(ans);
            }
        
        return answer;
        
    }
};