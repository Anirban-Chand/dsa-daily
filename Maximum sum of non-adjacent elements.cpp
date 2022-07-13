int memoization(vector<int> &arr, int i, vector<int> &dp){
    if(i==0) return arr[0];
    if(i<0) return 0;
    
    if(dp[i] != -1) return dp[i];
    
    int take = arr[i] + memoization(arr, i-2, dp);
    int dontTake = memoization(arr, i-1, dp);
    
    return dp[i] = max(take, dontTake);
}

int tabulation(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n , -1);
    dp[0] = arr[0];
    for(int i=1; i<n; i++){
        int take = arr[i];
        if(i>1) take += dp[i-2];
        int dontTake = dp[i-1];
    
        dp[i] = max(take, dontTake);
    }
    return dp[n-1];
}

int space_optimized(vector<int> &arr){
    int n = arr.size();
    if(n==1) return arr[0];
    if(n==2) return max(arr[0], arr[1]);
    
    int prev1 = arr[0], prev2=0;
    for(int i=1; i<n; i++){
        int cur = max(arr[i]+prev2, prev1);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &arr){
	// 	Solution 1
	//	return tabulation(arr);  
	
	// 	Solution 2
	// 	return memoization(arr, n-1, dp);
    
    return space_optimized(arr);
}
