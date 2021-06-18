#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr, int begin, int end){
    for(int i=begin; i<=end; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
}

void insertionSort(vector<int> &arr){
    int sizeOfArray = arr.size();
    for(int i=1; i<sizeOfArray; i++){
        for(int j=i; j>0; j--){
            if(arr[j] < arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}

int main(){
    vector<int> arr;
    int maxSizeOfArray = 10;
    srand(100);
    for(int i=0; i<maxSizeOfArray; i++){
        arr.push_back(rand() % 100);
    }
    cout << "Value of whole Array: " << endl;
    printArray(arr, 0, arr.size() - 1);

    insertionSort(arr);

    cout << "Sorted array: " << endl;
    printArray(arr, 0, arr.size() - 1);
    return 0;
}