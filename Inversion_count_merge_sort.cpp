#include<bits/stdc++.h>
using namespace std;

int mergeSortedArrays(vector<int> &arr, int s, int e){

    int inverse=0;


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
        if(first[idx1] <= second[idx2]){
            arr[mainArrayIndex] = first[idx1];
            mainArrayIndex++;
            idx1++;
        }
        else{
            arr[mainArrayIndex] = second[idx2];
            inverse+=(len1-idx1);
            mainArrayIndex++;
            idx2++;
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

    return inverse;
}


int mergeSort(vector<int>& arr, int s, int e){
    // base case
    if(s>=e)
        return 0;
    // In case of mid = (s+e)/2, it may happen that the sum will exceed the limit of integer
    // so we should use mid = s+(e-s)/2
    int mid = s+(e-s)/2;

    int inverse = 0;

    // sort left part - recursively
    inverse += mergeSort(arr, s, mid);
    //sort right part - recursively
    inverse += mergeSort(arr, mid+1, e);
    //merge both part
    inverse += mergeSortedArrays(arr, s, e);

    return inverse;
}

int findInversions(vector<int> arr){
    int invsersions=0;
    int n = arr.size();
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(arr[i]>arr[j]){
                invsersions++;
                // cout<<'('<<arr[i]<<", "<<arr[j]<<')'<<endl;
            }
    
    return invsersions;
}

int main(){
    vector<int> arr = {3,5,6,9,1,2,7,8};
    int size = arr.size();

    // cout<<"Before sorting: ";
    // for(auto e: arr) cout<<e<<" ";

    cout<<"Inversion Count normally: "<<findInversions(arr)<<endl<<endl;

    int inverse = mergeSort(arr, 0, size-1);
    cout<<"After sorting: ";
    for(auto e: arr) cout<<e<<" ";

    cout<<endl<<endl<<"Inversion Count using merge sort: "<<inverse<<endl;
    return 0;
}
