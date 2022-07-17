int recursion(int r, int c, vector<vector<int>> &arr){
    if(c<0 or c>=arr[0].size()) return -1e9;
    if(r==0) return arr[0][c];
        
    int top = arr[r][c]+recursion(r-1, c, arr);
    int ld = arr[r][c]+recursion(r-1, c-1, arr);
    int rd = arr[r][c]+recursion(r-1, c+1, arr);
    
    return max(top, max(ld,rd));
}

int memoization(int r, int c, vector<vector<int>> &arr, vector<vector<int>> &dp){
    if(c<0 or c>=arr[0].size()) return -1e9;
    if(r==0) return arr[0][c];
    
    if(dp[r][c] != -1) return dp[r][c];
    
    int top = arr[r][c]+memoization(r-1, c, arr, dp);
    int ld = arr[r][c]+memoization(r-1, c-1, arr, dp);
    int rd = arr[r][c]+memoization(r-1, c+1, arr, dp);
    
    return dp[r][c] = max(top, max(ld,rd));
}

int tabulation(vector<vector<int>> &arr){
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    // base case -> first row
    for(int c=0; c<m; c++)
        dp[0][c] = arr[0][c];
    
    for(int r=1; r<n; r++){
        for(int c=0; c<m; c++){
            int top = arr[r][c]+dp[r-1][c];
            int ld = arr[r][c];
            if(c-1>=0) ld+=dp[r-1][c-1];
            else ld = -1e9;
            int rd = arr[r][c];
            if(c+1<m) rd+=dp[r-1][c+1];
            else rd=-1e9;
            
            dp[r][c] = max(top, max(ld,rd));
        }
    }
    
    
    int ans=-1e9;
    for(int c=0; c<m; c++)
        ans = max(ans, dp[n-1][c]);
    return ans;
}

int getMaxPathSum(vector<vector<int>> &arr)
{
//     int n = arr.size();
//     int m = arr[0].size();
//     vector<vector<int>> dp(n, vector<int>(m, -1));
    
//     int ans=-1e9;
//     for(int c=0; c<m; c++)
//         ans = max(ans, memoization(n-1, c, arr, dp));
    
    return tabulation(arr);
}
