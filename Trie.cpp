class Trie {
private:
    static inline int NumCharacters = 26;
    struct Node{
        bool mIsEnd;
        vector<Node*> mChildren;
        Node(){
            mIsEnd = false;
            for(int i=0; i<NumCharacters;i++){
                mChildren.push_back(nullptr);
            }
        }
    };
    Node* mRoot = nullptr;
public:
    /** Initialize your data structure here. */
    Trie() {
        mRoot = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* itr = mRoot;
        for(int i=0; i<word.length();i++){
            int indx = word[i] - 'a';
            if(!itr->mChildren[indx]){
                itr->mChildren[indx] = new Node();
            }
            itr = itr->mChildren[indx];
        }
        itr->mIsEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* itr = mRoot;
        for(int i=0; i<word.length();i++){
            int indx = word[i] - 'a';
            if(!itr->mChildren[indx]){
                return false;
            }
            itr = itr->mChildren[indx];
        }
        return itr->mIsEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* itr = mRoot;
        for(int i=0; i<prefix.length();i++){
            int indx = prefix[i] - 'a';
            if(!itr->mChildren[indx]){
                return false;
            }
            itr = itr->mChildren[indx];
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
