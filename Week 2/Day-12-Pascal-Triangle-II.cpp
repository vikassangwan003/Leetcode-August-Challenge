/**
Problem : https://leetcode.com/explore/featured/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3421/

Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?

**/

//Solution

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>res(rowIndex+1);
        res[0]=1;
        long prev=1;
        for(long i=1;i<=rowIndex;i++){
            // nCr=nCr-1*(n-r+1)/r
            res[i]=prev*(rowIndex-i+1)/i;
            prev=res[i];
        }
        return res;
    }
};
                                 
