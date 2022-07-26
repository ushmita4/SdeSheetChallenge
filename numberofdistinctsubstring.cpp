

struct TrieNode
{
    TrieNode *childern[26];

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            childern[i] = NULL;
        }
    }
    ~TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            if (childern[i] != NULL)
            {
                delete childern[i];
            }
        }
    }
};


TrieNode *trie;
int countNodes;

void insert(string &str) {

    TrieNode *curr = trie;

    for (int i = 0; i < str.length(); i++) {
        int ind = str[i] - 'a';

        if (curr->childern[ind] == NULL) {
            curr->childern[ind] = new TrieNode();
        }
        curr = curr->childern[ind];
    }
}


void countNodeInTrie(TrieNode *curr) {

    if (curr == NULL) {
        return;
    }

    for (int i = 0; i < 26; i++) {
        if (curr->childern[i] != NULL) {
            countNodes++;
            countNodeInTrie(curr->childern[i]);
        }
    }
}

int distinctSubstring(string &word) {

    trie = new TrieNode();
    countNodes = 0;

    for (int i = 0; i < word.length(); i++) {
        string h = word.substr(i);
        insert(h);
    }

    TrieNode *curr = trie;
    countNodeInTrie(curr);

    delete trie;

    return countNodes;
}
