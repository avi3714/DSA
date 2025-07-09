struct Node{
  Node* links[26];
  bool flag=false;
  
 bool containskey(char ch)
 {
    if(links[ch-'a'] != NULL)
    return true;
    else
    return false;
 }
 void put(char ch,Node* node)
 {
    links[ch-'a']=node;
 }
 void setEnd()
 {
    flag=true;
 }
 bool isfound()
 {
    return flag;
 }

};
class Trie {
public:
Node* root;

    Trie() {
        root=new Node();
        
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(node->links[word[i] -'a'] ==NULL)
            {
                node->put(word[i],new Node());
            }
            node=node->links[word[i] - 'a'];
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containskey(word[i]))
            return false;
            node = node->links[word[i] - 'a'];
        }
        return node->isfound();
        
    }
    
    bool startsWith(string word) {
         Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(node->links[word[i] -'a'] ==NULL)
            return false;
             node = node->links[word[i] - 'a'];
            
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */