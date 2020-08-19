/**
Problem: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3428/

Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.

 

Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

Note:

1 <= N <= 9
0 <= K <= 9
**/

//Solution

class Solution {
public:
    void dfs(int N,int numSoFar,int k, vector<int> &ans){
        if(N<=0){
            ans.push_back(numSoFar);
            return;
        }
        int tailDigit=numSoFar%10;
        
        int afterAdd=tailDigit+k;
        if(afterAdd<10 && afterAdd>=0){
            dfs(N-1,numSoFar*10+afterAdd,k,ans);
        }
        
        if(k!=0){
         //k=0 then 22 in case of addition and in subtraction also 22 so to avoid repetition 
            int afterSub=tailDigit-k;
            if(afterSub<10 && afterSub>=0){
                // cout<<"N is:"<<N<<"\n";
            dfs(N-1,numSoFar*10+afterSub,k,ans);
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N==1){
            vector<int>v={0,1,2,3,4,5,6,7,8,9};
            return v;
        }
        
        vector<int>ans;
        for(int start=1;start<=9;start++){
            dfs(N-1,start,K,ans);
        }
        return ans;
    }
};
