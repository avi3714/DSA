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
stack<TreeNode*>st;

    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr=root;
        int count=0;
        while(curr)
        {
            st.push(curr);
            curr=curr->left;
        }
        while(count<k)
        {
            TreeNode* temp=st.top();
            st.pop();
            count++;
            if(count==k)
            return temp->val;
            if(temp->right)
            {
                st.push(temp->right);                
                 temp=temp->right;
                 while(temp->left && count<k)
                 {
                    temp=temp->left;
                    st.push(temp);
                 }
            }
        }

        return 0;
    }
};