class Solution{
    int mod = 1e9+7;
public:
    int nCr(int n, int r){
        // Space Optimized
        return space_optimize(n, r);
        
        // Tabulated       
        return tabulation(n, r);
        
        // Memoized
        vector<vector<int>> dp(n+1, vector<int>(r+1, -1));
        return memoization(n, r, dp);
        
        // Recursive
        return recursion(n, r);
    }
    
    int space_optimize(int n, int r){
        if(n<r) return 0;
        vector<int> prev(r+1, 0), cur(r+1, 0);
        prev[0] = cur[0] = 1;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=r; j++){
                cur[j] = (prev[j-1]+prev[j])%mod;
            }
            prev = cur;
        }
        return prev[r];
    }
    
    int tabulation(int n, int r){
        if(n<r) return 0;
        vector<vector<int>> dp(n+1, vector<int>(r+1, 0));
        for(int i=0; i<=n; i++) dp[i][0] = 1;
        for(int i=0; i<=r; i++) dp[i][i] = 1;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=r; j++){
                dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%mod;
            }
        }
        return dp[n][r];
    }
    
    int memoization(int n, int r, vector<vector<int>> &dp){
        if(n<r) return 0;
        if(r==0 or n==r) return 1;
        if(dp[n][r] != -1) return dp[n][r];
        
        int ans = memoization(n-1,r-1, dp)%mod + memoization(n-1, r, dp)%mod;
        return dp[n][r] = ans%mod;
    }
    
    int recursion(int n ,int r){
        if(n<r) return 0;
        if(r==0 or n==r) return 1;
        int ans = recursion(n-1,r-1)%mod + recursion(n-1, r)%mod;
        return ans%mod;
    }
};
