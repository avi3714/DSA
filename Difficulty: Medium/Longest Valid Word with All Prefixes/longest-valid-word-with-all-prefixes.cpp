struct Node{
  Node* links[26];
  bool flag=false;
  
  void put(char ch,Node* node)
  {
      links[ch- 'a']=node;
  }
  
  void setEnd()
  {
      flag=true;
  }
};
class Trie{
  public:
  Node* root;
  Trie()
  {
      root=new Node();
  }
  void insert(string str)
  {
      Node* node=root;
      for(int i=0;i<str.length();i++)
      {
          if(node->links[str[i] - 'a'] ==NULL)
          node->put(str[i], new Node());
          node=node->links[str[i] - 'a'];
      }
      node->setEnd();
  }
  bool check(string str)
  {
      Node* node=root;
      for(int i=0;i<str.length();i++)
      {
          node=node->links[str[i] - 'a'];
          if(node->flag==false)
          return false;
      }
      return true;
  }
};
class Solution {
        public:
    string longestValidWord(vector<string>& words) {
        // code here
        Trie A;
        for(int i=0;i<words.size();i++)
        {
            string s1=words[i];
            A.insert(s1);
        }
        string ans="";
        for(int i=0;i<words.size();i++)
        {
            if(A.check(words[i]))
            {
                if(ans.length() < words[i].length())
                {
                    ans=words[i];
                }
                else if(ans.length() == words[i].length())
                {
                    if(ans>words[i])
                    {
                        ans=words[i];
                    }
                }
            }
        }
        return ans;
        
    }
};
