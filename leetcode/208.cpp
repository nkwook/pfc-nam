class Trie {
    bool isEnd;
    vector<Trie*> key;
public:
    Trie() {
        isEnd=false;
        key=vector<Trie*>(26, nullptr);
    }
    
    void insert(string word) {
        Trie* target=this;
        for(char c: word){
            if(!target->key[c-'a']){
                target->key[c-'a']=new Trie();
            }
            target=target->key[c-'a'];
        }
        
        target->isEnd=true;
        
    }
    
    bool search(string word) {
        Trie* target=this;
        for(char c: word){
            if(!target->key[c-'a']) return false;
            target=target->key[c-'a'];
        }
        if(target->isEnd) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Trie* target=this;
        for(char c: prefix){
            if(!target->key[c-'a']) return false;
            target=target->key[c-'a'];
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