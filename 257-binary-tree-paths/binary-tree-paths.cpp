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
void addpath(TreeNode* node,string path,vector<string>&answer)
{
    if(!path.empty())
    {
      path+="->";
    }
    path+=to_string(node->val);
    if(node->left)
    addpath(node->left,path,answer);
    if(node->right)
    addpath(node->right,path,answer);
    if(!node->left&&!node->right)
    {
      if(path.length()>0)
        answer.push_back(path);
        //ans.clear();
    }
    //path.pop_back();
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>answer;
        addpath(root,"",answer);
        return answer;
        
    }
};