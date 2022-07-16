
int recursion(int i, int j, int  m, int n, int movesleft){
    if(((i<0 or j<0) or (i>=m or j>=n)) and movesleft>=0) return 1;
    if(movesleft<0) return 0;

    int left = recursion(i, j-1, m, n, movesleft-1);
    int top = recursion(i-1, j, m, n, movesleft-1);
    int right = recursion(i, j+1, m, n, movesleft-1);
    int bottom = recursion(i+1, j, m, n, movesleft-1);

    return (left+top+right+bottom)%(1000000007);
}

int dp[50][50][51];
int mod = 1000000007;
int memoization(int i, int j, int  m, int n, int movesleft){
    if(((i<0 or j<0) or (i>=m or j>=n)) and movesleft>=0) return 1;
    if(movesleft<0) return 0;

    if(dp[i][j][movesleft] != -1) return dp[i][j][movesleft];

    int ans=0;
    ans = (ans + memoization(i, j-1, m, n, movesleft-1))%mod;
    ans = (ans + memoization(i-1, j, m, n, movesleft-1))%mod;
    ans = (ans + memoization(i, j+1, m, n, movesleft-1))%mod;
    ans = (ans + memoization(i+1, j, m, n, movesleft-1))%mod;

    return dp[i][j][movesleft] = ans;
}

int findPaths(int m, int n, int moves, int sr, int sc) {
    // return recursion(sr, sc, m, n, moves);

    memset(dp, -1, sizeof(dp));
    return memoization(sr, sc, m, n, moves);
}
