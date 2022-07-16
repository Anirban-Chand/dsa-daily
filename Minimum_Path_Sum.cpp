class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        
        // return recursion(m-1, n-1, grid);
        
        
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return memoization(m-1, n-1, grid, dp);
        
        
        // return tabulation(grid);
        
        
        return space_optimized(grid);
    }
    
    int recursion(int i, int j, vector<vector<int>>& grid){
        // base cases
        if(i==0 and j==0) return grid[0][0];
        if(i<0 or j<0) return 1e9;
        
        int left = grid[i][j]+recursion(i, j-1, grid);
        int top = grid[i][j]+recursion(i-1, j, grid);
        
        return min(left, top);
    }
    
    int memoization(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i==0 and j==0) return grid[0][0];
        if(i<0 or j<0) return 1e9;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int left = grid[i][j]+memoization(i, j-1, grid, dp);
        int top = grid[i][j]+memoization(i-1, j, grid, dp);
        
        return dp[i][j] = min(left, top);
    }
    
    int tabulation(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 and j==0) dp[i][j] = grid[i][j];
                else{
                    int left=grid[i][j], top=grid[i][j];
                    if(i>0) top+=dp[i-1][j];
                    else top = 1e9;
                    if(j>0) left+=dp[i][j-1];
                    else left=1e9;
                    
                    dp[i][j] = min(left, top);
                }
            }
        }
        return dp[m-1][n-1];
    }
    
    int space_optimized(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);
        for(int i=0; i<m; i++){
            vector<int> cur(n, 0);
            for(int j=0; j<n; j++){
                if(i==0 and j==0) cur[j] = grid[i][j];
                else{
                    int left=grid[i][j], top=grid[i][j];
                    if(i>0) top+=prev[j];
                    else top = 1e9;
                    if(j>0) left+=cur[j-1];
                    else left=1e9;
                    
                    cur[j] = min(left, top);
                }
            }
            prev = cur;
        }
        return prev[n-1];
    }
};
