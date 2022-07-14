***Solution 1 - Recursion:***
```
class Solution {
public:
    int rob(vector<int>& arr) {
        int n = arr.size();
            
        // TLE
        return recursion(arr, n-1);    
    }
    
    // Solution 1 -> Recursion
    int recursion(vector<int> &arr, int i){
        if(i>=arr.size()) return 0;
        
        int take = arr[i]+recursion(arr, i-2);
        int dontTake = recursion(arr, i-1);
        
        return max(take, dontTake);
    }
};
```

***Solution 2 - Memoization:***
```
class Solution {
public:
    int rob(vector<int>& arr) {
        int n = arr.size();
        // Memoization
        vector<int> dp(n, -1);
        return memoization(arr, n-1, dp);
    }

    int memoization(vector<int> &arr, int i, vector<int> &dp){
        if(i>=arr.size()) return 0;
        if(dp[i] != -1) return dp[i];
        
        int take = arr[i];
        if(i>1) take += memoization(arr, i-2, dp);
        
        int dontTake = memoization(arr, i-1, dp);
        
        return dp[i] = max(take, dontTake);
    }
};
```

***Solution 3 - Tabulation:***
```
class Solution {
public:
    int rob(vector<int>& arr) {
        // Tabulation
        return tabulation(arr);
    }

    int tabulation(vector<int> &arr){
        vector<int> dp(arr.size(), -1);
        dp[0]=arr[0];
        for(int i=1; i<arr.size(); i++){
            int take = arr[i];
            if(i>1) take+=dp[i-2];
            int dontTake = dp[i-1];
            
            dp[i] = max(take, dontTake);
        }
        return dp.back();
    }
};
```    

***Solution 4 - Space Optimal:***
```
class Solution {
public:
    int rob(vector<int>& arr) {
        // Space Optimal
        return space_optimal(arr);
    }

    int space_optimal(vector<int> &arr){
        int prev=arr[0], prev2=0;
        for(int i=1; i<arr.size(); i++){
            int cur = max(arr[i]+prev2, prev);
            prev2 = prev;
            prev=cur;
        }
        return prev;
    }
};
```
