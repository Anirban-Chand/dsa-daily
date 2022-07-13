// BRUTE FORCE APPROACH
class Solution {
public:
    int tribonacci(int n) {
        return solve(n);
    }
    
    int solve(int i){
        if(i == 0) return 0;
        if(i == 1) return 1;
        if(i == 2) return 1;
        return solve(i-3)+solve(i-2)+solve(i-1);
    }
};



// TIME OPTIMIZED SOLUTION
class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
    
    int solve(int i, vector<int> &dp){
        if(i == 0) return 0;
        if(i == 1) return 1;
        if(i == 2) return 1;
        
        if(dp[i] != -1) return dp[i];
        
        return dp[i] = solve(i-3, dp)+solve(i-2, dp)+solve(i-1, dp);
    }
};



// MOST TIME OPTIMIZED SOLUTION
class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        else if(n==1) return 1;
        else if(n==2) return 1;
        vector<int> v(n+1,0);
        v[0]=0,v[1]=1,v[2]=1;
        for(int i=3; i<=n; i++)
            v[i]=v[i-3]+v[i-2]+v[i-1];
        return v[n];
    }
};



// MOST SPACE & TIME OPTIMIZED SOLUTION
class Solution {
public:
    int tribonacci(int n) {
        int prev1=1, prev2=1, prev3=0;
        if(n==0) return prev3;
        if(n==1) return prev2;
        if(n==2) return prev1;
        
        for(int i=3; i<=n; i++){
            int cur = prev1+prev2+prev3;
            
            prev3 = prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};
