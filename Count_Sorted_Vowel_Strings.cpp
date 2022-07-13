class Solution {
public:
    int countVowelStrings(int n) {
        /*
                    a   e   i   o   u
            n=1 ->  1   1   1   1   1
            n=2 ->  5   4   3   2   1
            n=3 ->  15  10  6   3   1
            n=4 ->  35  20  10  4   1
            .
            .
            .
            
            // Ref - https://www.youtube.com/watch?v=gdt7HQF56OI
        */
        
        vector<vector<int>> dp(n, vector<int>(5, 1));
        for(int i=1; i<n; i++){
            for(int j=3; j>=0; j--){
                dp[i][j] = dp[i-1][j]+dp[i][j+1];
            }
        }
        return accumulate(dp[n-1].begin(), dp[n-1].end(), 0);
    }
};
