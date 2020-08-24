/**
Problem : https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3434/

Implement the StreamChecker class as follows:

StreamChecker(words): Constructor, init the data structure with the given words.
query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.
 

Example:

StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
streamChecker.query('a');          // return false
streamChecker.query('b');          // return false
streamChecker.query('c');          // return false
streamChecker.query('d');          // return true, because 'cd' is in the wordlist
streamChecker.query('e');          // return false
streamChecker.query('f');          // return true, because 'f' is in the wordlist
streamChecker.query('g');          // return false
streamChecker.query('h');          // return false
streamChecker.query('i');          // return false
streamChecker.query('j');          // return false
streamChecker.query('k');          // return false
streamChecker.query('l');          // return true, because 'kl' is in the wordlist
 

Note:

1 <= words.length <= 2000
1 <= words[i].length <= 2000
Words will only consist of lowercase English letters.
Queries will only consist of lowercase English letters.
The number of queries is at most 40000.
**/

//Solution

class Trie{
    
    public:    
        bool endOfWord;
        Trie* next[26];
        
        Trie(){
            endOfWord=false;
            memset(next,NULL,sizeof(next));
        }
};

class StreamChecker {
public:
    Trie* root;
    string queryWord;
    
    StreamChecker(vector<string>& words) {
        this->root=new Trie();
        for(int i=0;i<words.size();i++){
            insert(words[i]);
        }
    }
    
    void insert(string word){
        Trie* node = root;
        for(int i=word.size()-1;i>=0;i--){
            if(node->next[word[i]-'a']==NULL){
                node->next[word[i]-'a']=new Trie();
            }
            node=node->next[word[i]-'a'];
        }
        node->endOfWord=true;
    }
    
    bool query(char letter) {
        queryWord+=letter;
        Trie* node=root;
        for(int i=queryWord.size()-1;i>=0;i--){
            if(node->next[queryWord[i]-'a']==NULL){
                return false;
            }
            node=node->next[queryWord[i]-'a'];
            if(node->endOfWord)
                return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
