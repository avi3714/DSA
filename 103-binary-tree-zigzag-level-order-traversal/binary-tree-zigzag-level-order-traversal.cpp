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
            vector<int>ans;
            if(count%2==0)
            {
            int r=q.size();
            for(int i=0;i<r;i++)
            {
                TreeNode* node=q.front();
                ans.push_back(node->val);
                q.pop();
                if(node->left)
                {
                     q.push(node->left);
                st.push(node->left->val);
                }
                if(node->right)
                {
                 q.push(node->right);
                st.push(node->right->val);
                }

            }
            count++;
            
            }
            else
            {
                while(!st.empty())
                {
                    int ri=st.top();
                    st.pop();
                    ans.push_back(ri);
                    TreeNode* xp=q.front();
                    q.pop();
                    if(xp->left)
                    q.push(xp->left);
                    if(xp->right)
                    q.push(xp->right);
                }
                count++;
            }
                answer.push_back(ans);
            


        }
        return answer;
        
    }
};