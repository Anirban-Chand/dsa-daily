#include<bits/stdc++.h>
using namespace std;

int ans=-1;

int findFirstOccurence(int *arr, int start, int end, int key){

    if(start>end)
        return ans;

    int mid = (start+end)/2;

    // base case
    if(arr[mid] == key){
        ans = mid;
        return findFirstOccurence(arr, start, mid-1, key);
    }
    
    // if key is smaller than arr[mid], then search left part
    else if(arr[mid]>key)
        return findFirstOccurence(arr, start, mid-1, key);
    // if key is larger then search in right part
    return findFirstOccurence(arr, mid+1, end, key);
}

int findLastOccurence(int *arr, int start, int end, int key){

    if(start>end)
        return ans;

    int mid = (start+end)/2;

    // base case
    if(arr[mid] == key){
        ans = mid;
        return findLastOccurence(arr, mid+1, end, key);
    }
    
    // if key is smaller than arr[mid], then search left part
    else if(arr[mid]>key)
        return findLastOccurence(arr, start, mid-1, key);
    // if key is larger then search in right part
    return findLastOccurence(arr, mid+1, end, key);
}


int main(){
    int arr[] = {1,3,5,5,5,6,9,9,9,9,9,9,9,9,10};
    int x; 
    cout<<"enter element to search: ";
    cin>>x;
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int firstOccur = findFirstOccurence(arr, 0, n, x);
    int lastOccur = findLastOccurence(arr, 0, n, x);

    if(firstOccur != -1 and lastOccur != -1){
        int occurences = lastOccur-firstOccur+1;
        cout<<x<<" occurred in array "<<occurences<<" times"<<endl;
    }

    else
        cout<<x<<" is not present in the array"<<endl;

    return 0;
}
