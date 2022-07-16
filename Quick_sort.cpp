#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr){
    for(auto e: arr)
        cout<<e<<" ";
}


int partition(vector<int>& arr, int s, int e){

    int pivot = arr[s];
    int count = 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i]<=pivot)
            count++;
    }

    int pivotIndex = s+count;

    // jo element ko pehle pivot mana tha aur uska original position wala element to swap kardo
    // taaki humara pivot element apni actual jagah par jaa sake
    swap(arr[s], arr[pivotIndex]);

    // pivot se chhote elements ko uske left side pe aur bade elements ko uske right side pe leke aao
    int l=s, r=e;
    while(l<pivotIndex  and  r>pivotIndex){
        // in case of duplicates - we are placing them on the left side of the pivot
        while(arr[l] <= arr[pivotIndex])
            l++;
        while(arr[r] > arr[pivotIndex])
            r--;

        if(l<pivotIndex  and  r>pivotIndex)
            swap(arr[l++], arr[r--]);
    }
    cout<<"partition called: ";
    print(arr);
    cout<<"\t";

    return pivotIndex;
}


void quickSort(vector<int>& arr, int s, int e){
    // base case
    if(s>=e)
        return;
    
    int pivotIndex = partition(arr, s, e);
    cout<<"pivot: "<<pivotIndex<<endl;

    // recursion call
    quickSort(arr, s, pivotIndex-1);
    quickSort(arr, pivotIndex+1, e);
}


int main(){
    vector<int> arr = {10,6,5,9,2,3,2,4,5,7,9,3,2,5,2,4,1,8,3,7,6,5,4,3,2,1};
    int size = arr.size();

    cout<<"Before Quick sorting: ";
    print(arr);
    cout<<endl;
    quickSort(arr, 0, size-1);
    cout<<endl;
    cout<<"After Quick sorting: ";
    print(arr);
    return 0;
}
