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
class BSTiterator{
    bool isnext=false;
    stack<TreeNode*>st;
 public:
 BSTiterator(TreeNode* root,bool answer)
 {
     isnext=answer;
     pushAll(root);
 }
 
 int next()
 {
    TreeNode* top_node=st.top();
    st.pop();
    if(isnext==true)
    {
        pushAll(top_node->right);
    }
    else
    pushAll(top_node->left);

    return top_node->val;
 }
 bool hasnext()
 {
    if(st.size()==0)
    return false;
    return true;
 }

 void pushAll(TreeNode* node)
 {
    if(isnext==true)
    {
       while(node)
       {
        st.push(node);
        node=node->left;
       }
    }
    else
    {
        while(node)
        {
            st.push(node);
            node=node->right;
        }
    }
 }

};
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
        return false;
        BSTiterator l(root,true);
        BSTiterator r(root,false);
        int i=l.next();
        int j=r.next();
        while(i<j)
        {
            if(i+j == k)
            return true;
            else if(i+j < k )
            i=l.next();
            else
            j=r.next();
        }
        return false;

        
    }
};