#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr, int begin, int end){
    for(int i=begin; i<=end; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
}

void selectionSort(vector<int> &arr){
    int minValue;
    int minIndex;
    int sizeOfArray = arr.size();
    for(int i=0; i<sizeOfArray; i++){
        minIndex = i;
        minValue = arr[i];
        for(int j=i+1; j<sizeOfArray; j++){
            if(arr[j] < minValue){
                minValue = arr[j];
                minIndex = j;
            }
        }
        // swap arr[i] and arr[minIndex]
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
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

    selectionSort(arr);

    cout << "Sorted Array: " << endl;
    printArray(arr, 0, arr.size() - 1);

    return 0;
}