#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>& v){
    for(auto i: v){
        for(auto j: i)
            cout<<j<<" ";
        cout<<endl;
    }
}

int main(){
    string s1 = "abcde";
    string s2 = "ade";
    
    int n1 = s1.size();
    int n2 = s2.size();
    
    string lcs="";
    int lcsLen=0;

    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    int ans=0;
    // bottom-up approach
    for(int i=n1-1; i>=0; i--){
        for(int j=n2-1; j>=0; j--){
            if(s1[i] == s2[j]){
                dp[i][j] = 1+dp[i+1][j+1];
                ans = max(ans, dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    print(dp);

    cout<<"Longest Common Subsequence: "<<lcs<<"\t Length: "<<ans<<endl;
    
    return 0;
}
