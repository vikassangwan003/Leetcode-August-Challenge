/**
Problem : https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3431/

Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 

Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000
**/


//Solution

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i=0,j=A.size()-1;
        while(i<j){
            if(A[i]&1 && !(A[j]&1)) swap(A[i++],A[j--]);
            else if(!(A[i]&1) && !(A[j]&1)) { i++;}
            else if(A[i]&1 && A[j]&1) {j--;}
            else {i++;j--;}
        }
        return A;
    }
};
