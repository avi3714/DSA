/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

int find(Node* root,int input)
{
    if(root==NULL)
    return INT_MAX;
    if(input==root->data)
    return input;
    if(input<root->data)
    {
        return min(root->data,find(root->left,input));
    }
    else
    {
        return find(root->right,input);
    }
}

int findCeil(Node* root, int input) {
    // Your code here
    int ans= find(root,input);
    if(ans==INT_MAX)
    return -1;
    return ans;
}