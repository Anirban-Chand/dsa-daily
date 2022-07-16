#include<bits/stdc++.h>
using namespace std;

void findAllSubsequences(string s, int idx, string subsequence, vector<string>& ans){
    // base case
    if(idx >= s.size()){
        ans.push_back(subsequence);
        return;
    }

    // dont take
    findAllSubsequences(s, idx+1, subsequence, ans);

    // take
    int ch = s[idx];
    subsequence+=ch;
    findAllSubsequences(s, idx+1, subsequence, ans);
}

int main(){
    string s = "abcde";
    vector<string> ans;
    int idx = 0;
    string subsequence = "";
    findAllSubsequences(s, idx, subsequence, ans);
    for(int i=0; i<ans.size(); i++)
        cout<<"subsequence #"<<i+1<<":  "<<ans[i]<<endl;
    

    return 0;
}
