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
bool found(TreeNode* root,int value)
{
    if(root==NULL)
    return NULL;
    if(root->val==value)
    return true;
    else if(root->val > value)
    return found(root->left, value);
    else
    return found(root->right,value);
}
bool find(TreeNode* node, TreeNode* universal_node,int k)
{
        bool a=false,b=false;
            if(node==NULL)
            return false;
            int value_to_be_found=k- node->val;
            

            if(value_to_be_found > universal_node->val && value_to_be_found != node->val)
             a=found(universal_node, value_to_be_found);

             else if(value_to_be_found < universal_node->val && value_to_be_found != node->val )
             b=found(universal_node, value_to_be_found);
             
             if(a==true || b==true)
             return true;
            

              else
           {
            return find(node->left,universal_node,k) || find(node->right,universal_node,k);
           }


}
    bool findTarget(TreeNode* root, int k) {
        TreeNode* universal_root=root;
        return find(root,universal_root,k);    
    }
};