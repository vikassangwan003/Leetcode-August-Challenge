/**
Problem: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3423/

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
**/

// Solution


class Solution {
public:
    int longestPalindrome(string s) {
        int a[52]={0};
        for(int i=0;i<s.length();i++){
            if(isupper(s[i]))a[s[i]-'A']++;
            else a[s[i]-'a'+26]++;
        }
        int doubles=0,singles=0;
        for(int i=0;i<52;i++){
            if(a[i]%2==0){
                doubles+=a[i];
            }
            else {
                doubles+=a[i]-1;
                singles=1;
            }
        }
       return doubles+singles; 
    }
};

