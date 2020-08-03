Problem link :  https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3411/

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false

//Solution

class Solution {
public:
    bool isPalindrome(string s) {
        if(s=="")return true;
        int i=0,l=s.size()-1;
        while(i<l){
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(!isalnum(s[l])){
                l--;
                continue;
            }
            if(tolower(s[i])!=tolower(s[l])){
                return false;
            }
            i++;l--;
        }
        return true;
    }
};
