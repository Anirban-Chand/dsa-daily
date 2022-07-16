#include<bits/stdc++.h>
using namespace std;

void mergeSortedArrays(vector<int> &arr, int s, int e){
    int mid = s+(e-s)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy values from old array to new arrays
    int mainArrayIndex=s;
    for(int i=0; i<len1; i++){
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++){
        second[i] = arr[mainArrayIndex++];
    }

    // time to merge
    int idx1,idx2;
    idx1=idx2=0;
    mainArrayIndex=s;
    while(idx1<len1 and idx2<len2){
        if(first[idx1] < second[idx2]){
            arr[mainArrayIndex++] = first[idx1++];
        }
        else{
            arr[mainArrayIndex++] = second[idx2++];
        }
    }

    while(idx1<len1){
        arr[mainArrayIndex++] = first[idx1++];
    }

    while(idx2<len2){
        arr[mainArrayIndex++] = second[idx2++];
    }


    delete []first;
    delete []second;
}
void mergeSort(vector<int>& arr, int s, int e){
    // base case
    if(s>=e)
        return;
    // In case of mid = (s+e)/2, it may happen that the sum will exceed the limit of integer
    // so we should use mid = s+(e-s)/2
    int mid = s+(e-s)/2;

    // sort left part - recursively
    mergeSort(arr, s, mid);
    //sort right part - recursively
    mergeSort(arr, mid+1, e);
    //merge both part
    mergeSortedArrays(arr, s, e);
}

int main(){
    // vector<int> arr = {8,4,87,49,15,12,47,587,164,1,128,874,954,412,34};
    vector<int> arr = {10,6,5,9,2,3,2,4,5,7,9,3,2,5,2,4,1,8,3,7,6,5,4,3,2,1};
    int size = arr.size();

    cout<<"Before Merge sorting: ";
    for(auto e: arr) cout<<e<<" ";
    mergeSort(arr, 0, size-1);
    cout<<endl<<endl;
    cout<<"After Merge sorting: ";
    for(auto e: arr) cout<<e<<" ";
    return 0;
}
