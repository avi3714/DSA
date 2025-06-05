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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* ,long long>>q;
        q.push({root,0});
        long long maxi=1;
        while(!q.empty())
        {
            long long size=q.size();
            long long minimal=q.front().second;
            long long last;
            long long first=0;
            for(int i=0;i<size;i++)
            {
                TreeNode* Node=q.front().first;
                long long index=q.front().second;
                q.pop();
                long long curr=index-minimal;
                if(i==size-1)
                last=curr;
                if(Node->left)
                q.push({Node->left,curr*2+1});
                if(Node->right)
                q.push({Node->right,curr*2+2});
            }
            maxi=max(last-first+1,maxi);
        }
        return maxi;
        
    }
};