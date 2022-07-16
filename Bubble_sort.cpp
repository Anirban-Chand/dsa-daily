#include<bits/stdc++.h>
using namespace std;

class BubbleSort{
    private:
        vector<int> arr;

    public:
        BubbleSort(vector<int>& v){
            for(int i=0; i<v.size(); i++)
                arr.push_back(v[i]);
        }

        void bubbleSort(){
            // loop for number of rounds
            int n = arr.size();

            chrono::steady_clock sc;
            auto start = sc.now();
            for(int i=1; i<n; i++){
                for(int j=0; j<n-1; j++){
                    if(arr[j]>arr[j+1])
                        swap(arr[j], arr[j+1]);
                }
            }
            auto end = sc.now();
            auto duration = static_cast<chrono::duration<double>>(end - start);
            cout<<"Bubble Sort - No optimization: "<<duration.count()<<" units of time"<<endl<<endl;
        }

        void bubbleSortSomeOptimization(){
            // loop for number of rounds
            int n = arr.size();

            chrono::steady_clock sc;
            auto start = sc.now();
            for(int i=1; i<n; i++){
                for(int j=0; j<n-i; j++){
                    if(arr[j]>arr[j+1])
                        swap(arr[j], arr[j+1]);
                }
            }
            auto end = sc.now();
            auto duration = static_cast<chrono::duration<double>>(end - start);
            cout<<"Bubble Sort - Some optimization: "<<duration.count()<<" units of time"<<endl<<endl;
        }

        void bubbleSortMaxOptimization(){
            // loop for number of rounds
            int n = arr.size();
            chrono::steady_clock sc;
            auto start = sc.now();
            for(int i=1; i<n; i++){
                bool swapped = false;
                for(int j=0; j<n-i; j++){
                    if(arr[j]>arr[j+1]){
                        swap(arr[j], arr[j+1]);
                        swapped = true;
                    }
                }
                // if at some round there is no swap is done then the array is already sorted, 
                // so come out of the loop
                if(swapped == false)
                    break;
            }
            auto end = sc.now();
            auto duration = static_cast<chrono::duration<double>>(end - start);
            cout<<"Bubble Sort - Max optimization: "<<duration.count()<<" units of time"<<endl<<endl;
        }

        void bubbleSortRecursive(int n){
            // base case
            if(n==0 or n==1)
                return;
            
            for(int i=0; i<n; i++){
                if(arr[i]>arr[i+1])
                    swap(arr[i], arr[i+1]);
            }

            bubbleSortRecursive(n-1);
        }

        void printArr(){
            int i=0;
            cout<<endl;
            while(i<arr.size()){
                cout<<arr[i++]<<" ";
            }
            cout<<endl<<endl;
        }
};


int main(){
    vector<int> arr = {23,96,90,61,82,76,12,56,43,83,19,37,50,36};
    
    int size = arr.size();
    cout<<"before sorting:";

    BubbleSort bs = BubbleSort(arr);

    bs.printArr();
    bs.bubbleSort();
    bs.bubbleSortSomeOptimization();
    bs.bubbleSortMaxOptimization();

    chrono::steady_clock sc;
    auto start = sc.now();
    bs.bubbleSortRecursive(size);
    auto end = sc.now();
    auto duration = static_cast<chrono::duration<double>>(end - start);
    cout<<"Bubble Sort - Recursive: "<<duration.count()<<" units of time"<<endl<<endl;

    cout<<"after sorting:";
    bs.printArr();
    return 0;
}
