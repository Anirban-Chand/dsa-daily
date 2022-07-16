#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr){
    int n = arr.size();

    for(int i=0; i<n-1; i++){
        int smallestIdx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[smallestIdx])
                smallestIdx = j;
        }
        swap(arr[i], arr[smallestIdx]);
    }
}

int main(){
    vector<int> arr = {6,2,8,4,10};
    int size = arr.size();
    cout<<"Array before sorting:: ";
    for(auto e:arr) cout<<e<<" ";
    selectionSort(arr);
    cout<<endl;
    cout<<"Array after sorting:: ";
    for(auto e:arr) cout<<e<<" ";
    
}
