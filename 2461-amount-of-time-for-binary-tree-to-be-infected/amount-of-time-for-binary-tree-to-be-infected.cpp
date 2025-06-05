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
    void findnode(TreeNode* root,int start,TreeNode* &infected)
    {
        if(root==NULL)
        return;
        if(root->val==start)
        {
            infected=root;
            return;
        }
        findnode(root->left,start,infected);
        findnode(root->right,start,infected);
    }
    void findparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent)
    {
        queue<TreeNode*>pq;
        pq.push(root);
        while(!pq.empty())
        {
            TreeNode* fronti=pq.front();
            pq.pop();
            if(fronti->left)
            {
                pq.push(fronti->left);
                parent[fronti->left]=fronti;
            }
            if(fronti->right)
            {
                pq.push(fronti->right);
                parent[fronti->right]=fronti;
            }
        }

    }
public:

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,int>visited;
         unordered_map<TreeNode*,TreeNode*>parent;
         parent[root]=NULL;
         TreeNode* infected=NULL;
        findparent(root,parent);
        findnode(root,start,infected);
        queue<pair< TreeNode* ,int >>q;
        visited[infected]=1;
        q.push({infected,0});
        int maxi=0;
        while(!q.empty())
        {
            TreeNode* node=q.front().first;
            int value=q.front().second;
            maxi=max(maxi,value);
            q.pop();
            if(node->left && visited.find(node->left)==visited.end())
            {
                q.push({node->left,value+1});
                visited[node->left]=1;
            }
            if(node->right && visited.find(node->right)==visited.end())
            {
                q.push({node->right,value+1});
                visited[node->right]=1;
            }
            if(parent[node] && visited.find(parent[node])==visited.end())
            {
                q.push({parent[node],value+1});
                visited[parent[node]]=1;
            }
        }
        return maxi;

    }
};