class Trie {
public:
    /** Initialize your data structure here. */
    Trie* head;
    Trie* children[26];
    bool isEnd;
    
    Trie(){
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
        head=NULL;
        isEnd=false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(head==NULL)
            head=new Trie;
        Trie* crawler=head;
        for(auto i: word){
            if(crawler->children[i-'a']==NULL){
                crawler->children[i-'a']=new Trie;
            }
            crawler=crawler->children[i-'a'];
        }
        crawler->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(head==NULL){
            if(word.length()==0)
                return true;
            else
                return false;
        }
        Trie* crawler=head;
        for(auto i:word){
            if(crawler->children[i-'a']==NULL)
                return false;
            crawler=crawler->children[i-'a'];
        }
        if(crawler->isEnd==false)
            return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(head==NULL){
            if(prefix.length()==0)
                return true;
            else
                return false;
        }
        
        Trie* crawler=head;
        for(auto i: prefix){
            if(crawler->children[i-'a']==NULL)
                return false;
            crawler=crawler->children[i-'a'];
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