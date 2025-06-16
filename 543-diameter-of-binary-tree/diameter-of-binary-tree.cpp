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
int heightofbinarytree(TreeNode* node,int &d,TreeNode* &highnode,unordered_map<TreeNode*,int>&mpp)
{
       if(node==NULL)
       return 0;
       int heightleft=heightofbinarytree(node->left,d,highnode,mpp);
       int heightright=heightofbinarytree(node->right,d,highnode,mpp);
       if(heightleft+heightright>=d)
       {
          d=heightleft+heightright;
          highnode=node;
       }
       if(heightleft>=heightright)
       {
        mpp[node]=0;
       }
       else
       {
        mpp[node]=1;
       }     
       return 1+max(heightleft,heightright);
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root ==NULL)
        return 0;          
        unordered_map<TreeNode*,int>mpp;
        int d=0;
        TreeNode* highnode=NULL;
        int height=heightofbinarytree(root,d,highnode,mpp);
        
        vector<int>v;
        TreeNode* othernode=highnode->right;
        while(highnode)
        {
            v.push_back(highnode->val);
            if(mpp[highnode]==0)
            highnode=highnode->left;
            else
            highnode=highnode->right;
        }
        reverse(v.begin(),v.end());
        while(othernode)
        {
            v.push_back(othernode->val);
            if(mpp[othernode]==0)
            othernode=othernode->left;
            else
            othernode=othernode->right;
        }
        for(auto it:v)
        {
            cout<<it<<" ";
        }

        cout<<endl;
        return d;


        
    }
};