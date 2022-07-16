#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr){
    int n=arr.size();
    for(int i=1; i<n; i++){
        int curr = arr[i];
        int j=i-1;
        while(curr<arr[j] and j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }
}

int main(){
    vector<int> arr = {10,9,8,7,6,5,5,5,4,3,3,2,1,0};
    int size = arr.size();

    cout<<"Before sorting: ";
    for(auto e: arr) cout<<e<<" ";
    insertionSort(arr);
    cout<<endl<<endl;
    cout<<"After sorting: ";
    for(auto e: arr) cout<<e<<" ";

    return 0;
}
