#include <bits/stdc++.h>
using namespace std;

void findPowerSet(vector<int>& arr, int index,vector<int> output, vector<vector<int>>& powerset){
    // base case
    if(index>=arr.size()){
        powerset.push_back(output);
        return;
    }

    // exclude current element
    findPowerSet(arr, index+1, output, powerset);

    // include current element
    int element = arr[index];
    output.push_back(element);
    findPowerSet(arr, index+1, output, powerset);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    vector<vector<int>> powerset = {};
    vector<int> output;
    int idx=0;
    findPowerSet(arr, idx, output, powerset);

    for(int i=0; i<powerset.size(); i++){
        cout<<"subset #"<<i+1<<": "<<"{";
        for(int j=0; j<powerset[i].size(); j++){
            cout<<powerset[i][j]<<",";
        }
        cout<<"}"<<endl;
    }

    return 0;
}
