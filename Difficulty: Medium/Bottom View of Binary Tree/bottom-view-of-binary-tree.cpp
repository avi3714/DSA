// Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        map<int,int>mpp;
        queue<pair<Node*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            Node* node=q.front().first;
            int xaxis=q.front().second.first;
            int level=q.front().second.second;
            q.pop();
            mpp[xaxis]=node->data;
            if(node->left)
            {
                q.push({node->left,{xaxis-1,level+1}});
            }
            if(node->right)
            {
                q.push({node->right,{xaxis+1,level+1}});
            }
        }
        vector<int>ans;
        for(auto it:mpp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};