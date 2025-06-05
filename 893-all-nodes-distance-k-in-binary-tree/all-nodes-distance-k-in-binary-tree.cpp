/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void marktheparents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent)
{
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
   TreeNode* frontnode=q.front();
   q.pop();
   if(frontnode->left)
   {
    parent[frontnode->left]=frontnode;
    q.push(frontnode->left);
   }
   if(frontnode->right)
   {
    parent[frontnode->right]=frontnode;
    q.push(frontnode->right);
   }
    }
    
}
void findthenodeatdistancek(TreeNode* target,int k,unordered_map<TreeNode*,int>&mpp,unordered_map<TreeNode*,TreeNode*>&parent,vector<int>&ans)
{
    if(target==NULL)
    return;
    mpp[target]=1;
    if(k==0){
    ans.push_back(target->val);
    return;}
    if(target->left && mpp.find(target->left)==mpp.end()&&k>=0)
    findthenodeatdistancek(target->left,k-1,mpp,parent,ans);
    if(target->right && mpp.find(target->right)==mpp.end()&&k>=0)
    findthenodeatdistancek(target->right,k-1,mpp,parent,ans);
    if(parent[target]!=NULL && mpp.find(parent[target])==mpp.end()&&k>=0)
    findthenodeatdistancek(parent[target],k-1,mpp,parent,ans);

}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,int>mpp;
        unordered_map<TreeNode*,TreeNode*>parent;
        parent[root]=NULL;
        marktheparents(root,parent);
        vector<int>ans;
        findthenodeatdistancek(target,k,mpp,parent,ans);
        return ans;

    }
};