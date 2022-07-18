bool recursion(int i, int k, vector<int> &arr){
    if(k==0) return true;
    if(i==0) return arr[0]==k;
    
    bool dontTake = recursion(i-1, k, arr);
    bool take = false;
    if(arr[i]<=k) take = recursion(i-1, k-arr[i], arr);
    
    return take or dontTake;
}

bool memoization(int i, int k, vector<int> &arr, vector<vector<int>> &dp){
    if(k==0) return true;
    if(i==0) return arr[0]==k;
    
    if(dp[i][k] != -1) return dp[i][k];
    
    bool dontTake = memoization(i-1, k, arr, dp);
    bool take = false;
    if(arr[i]<=k) take = memoization(i-1, k-arr[i], arr, dp);
    
    return dp[i][k] = take or dontTake;
}

bool tabulation(int n, int k, vector<int> &arr){
    vector<vector<bool>> dp(n, vector<bool>(k+1, false));
    for(int i=0; i<n; i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
    
    for(int i=1; i<n; i++){
        for(int t=1; t<=k; t++){
            bool dontTake = dp[i-1][t];
            bool take = false;
            if(arr[i]<=t) take = dp[i-1][t-arr[i]];

            dp[i][t] = take or dontTake;
        }
    }
    return dp[n-1][k];
}

bool space_optimized(int n, int k, vector<int> &arr){
    vector<bool> prev(k+1, 0), cur(k+1, 0);
    prev[0] = cur[0] = true;
    prev[arr[0]] = true;
    
    for(int i=1; i<n; i++){
        for(int t=1; t<=k; t++){
            bool dontTake = prev[t];
            bool take = false;
            if(arr[i]<=t) take = prev[t-arr[i]];

            cur[t] = take or dontTake;
        }
        prev = cur;
    }
    return prev[k];
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    
    return space_optimized(n,k,arr);
    
//     return tabulation(n, k, arr);
    
//     vector<vector<int>> dp(n, vector<int>(k+1, -1));
//     return memoization(n-1, k, arr, dp);
    
//     return recursion(n-1, k, arr);
}
