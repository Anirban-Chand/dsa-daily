class Solution {
public:
    int dfsForIsland(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited){
        if((i<0||j<0||i>=grid.size()||j>=grid[0].size())||(visited[i][j])||(!grid[i][j]))
            return 0;
        
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
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                // do dfs if the cell is not visited already
                if(grid[i][j] && !visited[i][j])
                    maxArea = max(maxArea, dfsForIsland(grid,i,j,visited));
            }
        }
        return maxArea;
    }
};
