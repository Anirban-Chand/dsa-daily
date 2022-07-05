#include<bits/stdc++.h>
using namespace std;


int binarySearchUsingRecursion(int *arr, int start, int end, int key){

    if(start>end)
        return -1;

    int mid = (start+end)/2;
    // base case
    if(arr[mid] == key)
        return mid;
    
    // if key is smaller than arr[mid], then search left part
    else if(arr[mid]>key)
        return binarySearchUsingRecursion(arr, start, mid-1, key);
    // if key is larger then search in right part
    return binarySearchUsingRecursion(arr, mid+1, end, key);
}


int main(){
    int arr[] = {10,31,44,62,81,99,110,122,153,190,212,302};
    int x; 
    cout<<"enter element to search: ";
    cin>>x;
    int n = sizeof(arr)/sizeof(arr[0]);
    int idx = binarySearchUsingRecursion(arr, 0, n, x);
    if(idx != -1)
        cout<<x<<" is present in the array at position "<<idx<<endl;

    else
        cout<<x<<" is not present in the array"<<endl;

    return 0;
}
