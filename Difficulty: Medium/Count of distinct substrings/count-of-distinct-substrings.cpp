/*You are required to complete this method */
struct Node{
 
  unordered_map<char,Node*>mpp;
  
  void put(char ch,Node* node)
  {
      mpp[ch]=node;
  }
  bool contains(char ch)
  {
      if(mpp.count(ch) > 0)
      return true;
      else
      return false;
  }
};
class Trie{
  public:
  Node* root;
  int answer=1;
  Trie()
  {
      root=new Node();
  }
  void insert(string str,int index)
  {
      Node* node=root;
      for(int i=index;i<str.length();i++)
      {
          if(!node->contains(str[i]))
          {
              answer++;
              node->put(str[i],new Node());
          }
          node=node->mpp[str[i] ];
      }
  }
  
};
int countDistinctSubstring(string s) {
    // Your code here
    int answer=0;
    Trie A;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
       A.insert(s,i);
    }
    return A.answer;
}