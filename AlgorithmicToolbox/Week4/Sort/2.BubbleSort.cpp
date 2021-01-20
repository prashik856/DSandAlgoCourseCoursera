#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr, int begin, int end){
    for(int i=begin; i<=end; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
}

void bubbleSort(vector<int> &arr){
    int sizeOfArray = arr.size();
    
    for(int i=0; i<sizeOfArray; i++){
        for(int j=0; j<sizeOfArray - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    vector<int> arr;
    int maxSizeOfArray = 10;
    //srand();
    for(int i=0; i<maxSizeOfArray; i++){
        arr.push_back(rand() % 100);
    }
    cout << "Value of whole Array: " << endl;
    printArray(arr, 0, arr.size() - 1);

    bubbleSort(arr);

    cout << "Sorted array: " << endl;
    printArray(arr, 0, arr.size() - 1);

    return 0;
}