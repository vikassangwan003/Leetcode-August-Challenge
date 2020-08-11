/**
Problem:  https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3419/

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701
 

Constraints:

1 <= s.length <= 7
s consists only of uppercase English letters.
s is between "A" and "FXSHRXW".

**/

//Solution

class Solution {
public:
    int titleToNumber(string s) {
        int l=s.length()-1,ans=0;
        for(int i=l;i>=0;i--){
            // cout<<s[l-i]-64<<" "<<pow(26,i)<<" "<<"\n";
            ans+=(s[l-i]-64)*pow(26,i);
        }
        return ans;
    }
};
// 101= 1*2^2+0*2^1+1*2^0
// ABC= A*26^2+B*26+C

