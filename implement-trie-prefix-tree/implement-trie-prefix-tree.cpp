class TrieNode{
public:
    TrieNode* child[26];
    bool isword;
    TrieNode():isword(false){
        for(auto &i:child)
            i=NULL;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *ptr=root;
        for(int i=0;i<word.size();i++){
            if(!ptr->child[word[i]-'a'])
                ptr->child[word[i]-'a']=new TrieNode();
            ptr=ptr->child[word[i]-'a'];
        }
        ptr->isword=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* ptr=root;
        for(int i=0;i<word.size();i++){
            if(!ptr->child[word[i]-'a'])
                return false;
            ptr=ptr->child[word[i]-'a'];
        }
        return ptr->isword==true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* ptr=root;
        for(int i=0;i<prefix.size();i++){
            if(!ptr->child[prefix[i]-'a'])
                return false;
            ptr=ptr->child[prefix[i]-'a'];
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */