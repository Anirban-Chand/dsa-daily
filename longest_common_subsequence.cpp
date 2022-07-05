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

    // bottom-up approach
    // for(int i=n1-1; i>=0; i--){
    //     for(int j=n2-1; j>=0; j--){
    //         if(s1[i] == s2[j]){
    //             dp[i][j] = 1+dp[i+1][j+1];
    //             lcs+=s1[i];
    //             lcsLen++;
    //         }
    //         else{
    //             dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
    //         }
    //     }
    // }
    // dp[0][0] will store the final result



    // top-down approach
    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
                lcs+=s1[i-1];
                lcsLen++;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    // dp[n1][n2] will store the final result


    print(dp);

    cout<<"Longest Common Subsequence: "<<lcs<<"\t Length: "<<dp[n1][n2]<<endl;
    
    return 0;
}
