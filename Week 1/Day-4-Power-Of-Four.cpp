Problem :  https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3412/

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true
Example 2:

Input: 5
Output: false
Follow up: Could you solve it without loops/recursion?

//Solution


class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num==0)return false;
        return floor(log(num)/log(4))==ceil(log(num)/log(4));
    }
};


//Another Solution
//return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;

