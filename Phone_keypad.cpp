#include<bits/stdc++.h>
using namespace std;

vector<string> keypad = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void findAllSubsequences(string s, int idx, string temp, vector<string>& ans){
    // base case - if index out of range
    if(idx>=s.size()){
        ans.push_back(temp);    // include the string and backtrack
        return; 
    }

    int num = s[idx] - '0';
    string val = keypad[num];

    for(int i=0; i<val.size(); i++){
        temp.push_back(val[i]);

        // recursive call
        findAllSubsequences(s,idx+1,temp,ans);

        // backtrack
        temp.pop_back();
    }
}

int main(){
    string s;
    cout<<"Enter a number: ";
    cin>>s;
    int idx=0;
    vector<string> ans;
    string temp="";
    findAllSubsequences(s,idx,temp,ans);
    for(auto e: ans)
        cout<<e<<" ";
    return 0;
}
