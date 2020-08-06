/**

Problem Link :  https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3413/

Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.

   Hide Hint #1  
You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.


**/


class WordDictionary {
    
    
    class TrieNode{
        Map<Character,TrieNode>children;
        boolean endOfWord;
        
        public TrieNode(){
            children=new HashMap();
            endOfWord=false;
        }
    }
    
    private TrieNode root;
    
    /** Initialize your data structure here. */
    public WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    public void addWord(String word) {
        TrieNode current=root;
        for(char c: word.toCharArray()){
            TrieNode node=current.children.get(c);
            if(node==null){
               node = new TrieNode();
               current.children.put(c,node); 
            }
            current=node;
        }
        current.endOfWord=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        
        return dfs(root,word,0);
    }
    public boolean dfs(TrieNode node,String word,int i){
        if(i==word.length()) return node.endOfWord;
        if(word.charAt(i)=='.'){
            for(Map.Entry<Character,TrieNode> childNode : node.children.entrySet()){
               if(dfs(childNode.getValue(),word,i+1)) 
                   return true;
            }
        }
        TrieNode n=node.children.get(word.charAt(i));
        if(n==null)return false;
        else return dfs(n,word,i+1);
           
    }
    
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
