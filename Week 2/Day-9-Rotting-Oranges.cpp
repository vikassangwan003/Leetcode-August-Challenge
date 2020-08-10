/**
Problem : https://leetcode.com/explore/featured/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3418/

In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 

Example 1:



Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.

**/

//Solution

class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        
        queue<pair<int,int>>q;
        int freshOranges=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                    freshOranges++;
            }
        }
        
        int time=0;
        vector<vector<int>> direction ={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()&&freshOranges>0){
            time++;    
            int size=q.size();
            while(size--){
                pair<int,int>temp=q.front();
                q.pop();
                int i=temp.first;
                int j=temp.second;
                for(vector<int>dir:direction){
                    int x=i+dir[0];
                    int y=j+dir[1];
                    if(x>=row||y>=col||x<0||y<0||grid[x][y]==0||grid[x][y]==2)continue;
                    // cout<<" x is "<<x<<" y is"<<y<<"\n";
                    grid[x][y]=2;
                    q.push({x,y});
                    --freshOranges;
                }
            }
        }
        cout<<"tim"<<time<<" "<<freshOranges;
        return freshOranges==0?time:-1;
    }
};


