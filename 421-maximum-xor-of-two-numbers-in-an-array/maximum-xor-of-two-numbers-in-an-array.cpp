struct Node{
Node* links[2];

void put(int bit,Node* node)
{
    links[bit]=node;
}

};
class Trie{
 public:
 Node* root;
 Trie()
 {
    root=new Node();
 }
 void insert(int num)
 {
    Node* node=root;
    for(int i=31;i>=0;i--)
    {
        int bit=0;
        if(((1<<i) & (num))!=0)
        bit=1;
        else
        bit=0;
        if(node->links[bit] == NULL)
        node->put(bit,new Node());
        node=node->links[bit];
    }
 }
 int getmax(int num)
 {
    Node* node=root;
    int temp=0;
    for(int i=31;i>=0;i--)
    {
        int bit=0;
        if(((1<<i) & (num))!=0)
        bit=1;
        else
        bit=0;
        if(node->links[1-bit] != NULL)
        {
        temp=temp+(1<<i);
        node=node->links[1-bit];
        }
        else
        node=node->links[bit];
    }
    return temp;
    
 }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        Trie A;
        for(int i=0;i<n;i++)
        {
            A.insert(nums[i]);
        }
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            int number=nums[i];
            maxi=max(maxi,A.getmax(number));
        }
        return maxi;

    }
};