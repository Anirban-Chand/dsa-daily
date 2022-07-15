***Approach:*** 
Step-1: Take a 2D array of bool values to keep track of the cells if they are visited or not,
Step-2: Write the recursive function for DFS,
Step-3: In dfs function mark the current cell visited=true, and call recursively for it left, top, right & bottom,
Step-4: return (1+left+top+right+down) i.e if one of them is a part of the current cell/island count will increment,
Step-5: Run a nested for loop to check each cell, if cell is not visited then preform dfs on it. Continue otherwise,
Step-6: Take a variable maxArea that will keep track of maximum area possible till the current cell,
Step-7: return maxArea.

***DFS Solution:***
```
class Solution {
public:
    int dfsForIsland(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited){
        if((i<0||j<0||i>=grid.size()||j>=grid[0].size())||(visited[i][j])||(!grid[i][j]))
            return 0;
        
        // Mark the current cell visited
        visited[i][j]=true;
        // check left cell belongs to water or land
        int left = dfsForIsland(grid,i,j-1,visited);
      
        // check top cell belongs to water or land
        int top = dfsForIsland(grid,i-1,j,visited);
      
        // check right cell belongs to water or land
        int right = dfsForIsland(grid,i,j+1,visited);
      
        // check down cell belongs to water or land
        int down = dfsForIsland(grid,i+1,j,visited);
        
        return(1+left+top+right+down);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols,false));
        int maxArea=0;
        for(int i=0; i<rows); i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] && !visited[i][j])
                    maxArea = max(maxArea, dfsForIsland(grid, i,j,visited));    // do dfs if the cell is not visited already
            }
        }
        return maxArea;
    }
};
```
