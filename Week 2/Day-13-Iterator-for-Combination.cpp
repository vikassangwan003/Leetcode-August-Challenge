/**
Problem:  https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3422/

Design an Iterator class, which has:

A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
A function next() that returns the next combination of length combinationLength in lexicographical order.
A function hasNext() that returns True if and only if there exists a next combination.
 

Example:

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false
 

Constraints:

1 <= combinationLength <= characters.length <= 15
There will be at most 10^4 function calls per test.
It's guaranteed that all calls of the function next are valid.

**/

class CombinationIterator {
public:
    string chars;
    int len;
    set<string>vec;
    int numberOfPatterns;
    int flag;
    set<string>::iterator cur;

    CombinationIterator(string characters, int combinationLength) {
        chars=characters;
        len=combinationLength;
        flag=0;
        vec = generate(chars,len);
        cur=begin(vec);
        numberOfPatterns=vec.size();
    }
    
    string next() {
        return !(cur==end(vec))?*cur++:"";;
    }
    
    bool hasNext() {
       return !(cur==end(vec));; 
    }
    
    set<string> generate(string chars,int len){
        int counter=pow(2,chars.length());
        set<string>res;
        for(int i=0;i<counter;i++){
            string str="";
            for(int j=0;j<chars.length();j++){
                if(i&(1<<j)){
                    str+=chars[j];
                }
            }
            if(str.length()==len)
                res.insert(str);
        }
        return res;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
