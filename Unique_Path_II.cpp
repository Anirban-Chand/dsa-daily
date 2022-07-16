long int mod = 1000000007;

int recursion(int i, int j, vector<vector<int>> &mat){
    // base case
    if(i==0 and j==0) return 1;
    if(i<0 or j<0 or mat[i][j]==-1) return 0;
    
    // processing
    int left = recursion(i, j-1, mat)%mod;
    int top = recursion(i-1, j, mat)%mod;
    
    return (left+top)%mod;
}

int memoization(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
    // base case
    if(i==0 and j==0) return 1;
    if(i<0 or j<0 or mat[i][j]==-1) return 0;
    
    if(dp[i][j] != -2) return dp[i][j];
    
    // processing
    int left = memoization(i, j-1, mat, dp)%mod;
    int top = memoization(i-1, j, mat, dp)%mod;
    
    return dp[i][j] = (left+top)%mod;
}

int tabulation(vector<vector<int>> &mat){
    int row=mat.size();
    int col=mat[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(mat[i][j] == -1) dp[i][j]=0;
            else if(i==0 and j==0) dp[i][j]=1;
            else{
                int left=0;
                if(j>0) left = dp[i][j-1]%mod;
                int top=0;
                if(i>0) top = dp[i-1][j]%mod;
                dp[i][j] = (left+top)%mod;
            }
        }
    }
    return dp[row-1][col-1];
}

int mazeObstacles(int rows, int cols, vector<vector<int>> &mat) {
	// return recursion(rows-1, cols-1, mat);
	// vector<vector<int>> dp(rows, vector<int>(cols, -2));
	// return memoization(rows-1, cols-1, mat, dp);
	return tabulation(mat);
}
