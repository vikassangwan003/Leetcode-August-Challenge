Problem: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3409/


Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
 

Example 1:

Input: "USA"
Output: True
 

Example 2:

Input: "FlaG"
Output: False
 

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.


Solution:


class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length()==1)return true;
        if(islower(word[0])){
            for(int i=1;i<word.length();i++){
                if(isupper(word[i]))
                    return false;
            }
        }
        else if(isupper(word[0])&&isupper(word[1])){
            for(int i=2;i<word.length();i++){
                if(islower(word[i]))
                    return false;
            }
        }
        else if(isupper(word[0])&&islower(word[1])){
            for(int i=2;i<word.length();i++){
                if(isupper(word[i]))
                    return false;
            }
        }
        return true;
    }
};
