


class TrieNode {
public:
    TrieNode * child[26];
    bool isEnd;
    TrieNode()
    {
        isEnd=false;
        for(int i=0;i<26;i++)
            child[i]=NULL;
    }
    
};

class Trie {
public:
 
    TrieNode *root;   
    Trie() {
        root= new TrieNode();
    }
    
   
    void insert(string word) {
        TrieNode *tem=root;
        for(auto x:word)
        {
            if(!tem->child[x-'a'])
                tem->child[x-'a']= new TrieNode();
            tem=tem->child[x-'a'];
        }
        tem->isEnd=true;
    }
    
    
    bool search(string word) {
        TrieNode *tem=root;
        for(auto x:word)
        {
            if(!tem->child[x-'a'])
                return false;
            tem=tem->child[x-'a'];
        }
        return  tem->isEnd;
    }
    
    
    bool startsWith(string prefix) {
        TrieNode *tem=root;
        for(auto x:prefix)
        {
            if(!tem->child[x-'a'])
                return false;
            tem=tem->child[x-'a'];
        }
        return  true;
    }
};
