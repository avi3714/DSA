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
    private:
    int findheight(TreeNode* root)
    {
         int h=0;
         while(root!=NULL){
         root=root->left;
         h++;}
         return h;
    }
    void findallnodesatheighth(TreeNode* root,vector<TreeNode*>&nodes,int h)
    {
        if(root==NULL)
        return ;
        if(h==0)
        {
            nodes.push_back(root);
            return;
        }
        if(root->left)
        findallnodesatheighth(root->left,nodes,h-1);
        if(root->right)
        findallnodesatheighth(root->right,nodes,h-1);
    }
public:
    int countNodes(TreeNode* root) {
        if(root==NULL)
        return 0;
        int h=findheight(root);
        if(h==1)
        return 1;
        if(h==2)
        {
            if(root->right)
            return 3;
            else
            return 2;
        }
        vector<TreeNode*>nodes;
        findallnodesatheighth(root,nodes,h-2);
        
        int count=0;
        for(auto it:nodes)
        {
            if(it->left==NULL)
            break;
            else
            count++;
            if(it->right==NULL)
            break;
            else
            count++;

        }
        count+=(pow(2,h-1)-1);
        return count;
        
    }
};