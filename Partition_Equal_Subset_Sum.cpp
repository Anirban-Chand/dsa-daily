class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int total = 0;
        for(int i=0; i<N; i++) total+=arr[i];
        if(total%2 != 0) return 0;
        
        
        // Space optimized
        return space_optimized(N, total/2, arr);
        
        
        // Tabulated
        return tabulation(N, total/2, arr);
        
        
        // Memoized
        vector<vector<int>> dp(N, vector<int>(total/2+1, -1));
        return memoization(N-1, total/2, arr, dp);
        
        
        // Brute Force
        return recursion(N-1, total/2, arr);
    }
    
    int space_optimized(int n, int k, int arr[]){
        vector<int> prev(k+1, 0), cur(k+1, 0);
        prev[0] = cur[0] = true;
        if(arr[0]<=k) prev[arr[0]] = true;
        
        for(int i=1; i<n; i++){
            for(int j=0; j<=k; j++){
                int dontTake = prev[j];
                int take = 0;
                if(arr[i] <= j) take = prev[j-arr[i]];
                
                cur[j] = take or dontTake;
            }
            prev = cur;
        }
        
        return prev[k];
    }
    
    int tabulation(int n, int k, int arr[]){
        vector<vector<int>> dp(n, vector<int>(k+1, 0));
        for(int i=0; i<n; i++) dp[i][0] = true;
        if(arr[0] <= k) dp[0][arr[0]] = true;
        
        for(int i=1; i<n; i++){
            for(int j=0; j<=k; j++){
                int dontTake = dp[i-1][j];
                int take = 0;
                if(arr[i] <= j) take = dp[i-1][j-arr[i]];
                
                dp[i][j] = take or dontTake;
            }
        }
        
        return dp[n-1][k];
    }
    
    int memoization(int ind, int k, int arr[], vector<vector<int>> &dp){
        if(k == 0) return 1;
        if(ind == 0) return arr[0]==k;
        
        if(dp[ind][k] != -1) return dp[ind][k];
        
        int dontTake = memoization(ind-1, k, arr, dp);
        int take = 0;
        if(arr[ind] <= k) take = memoization(ind-1, k-arr[ind], arr, dp);
        
        return dp[ind][k] = take or dontTake;
    }
    
    int recursion(int ind, int k, int arr[]){
        if(k == 0) return 1;
        if(ind == 0) return arr[0]==k;
        
        int dontTake = recursion(ind-1, k, arr);
        int take = 0;
        if(arr[ind] <= k) take = recursion(ind-1, k-arr[ind], arr);
        
        return take or dontTake;
    }
};
