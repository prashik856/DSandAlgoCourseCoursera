#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr, int begin, int end){
    for(int i=begin; i<=end; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
}

void printAllInfo(vector<int> &arr, int startOfArray, int mid, int endOfArray, int subArray1Size, int subArray2Size){
    cout << "Start: " << startOfArray << endl;
    cout << "Mid: " << mid << endl;
    cout << "End: " << endOfArray << endl;

    cout << "Sub array 1 size: " << subArray1Size << endl;
    cout << "Sub array 1: " << endl;
    printArray(arr, startOfArray, mid);
    
    cout << "Sub array 2 size: " << subArray2Size << endl;
    cout << "Sub array 2: " << endl;
    printArray(arr, mid+1, endOfArray);
}

void sortSubArray(vector<int> &arr, int startOfArrary, int mid, int endOfArray){
    cout << "Sorting subarray" << endl;
    // now, we have two sub arrays
    vector<int> sortedArray;
    int i,j;
    for(i=startOfArrary, j=mid+1; i<=mid && j<=endOfArray;){
        if(arr[i] >= arr[j]){
            sortedArray.push_back(arr[j]);
            j++;
        } else {
            sortedArray.push_back(arr[i]);
            i++;
        }
    }
    cout << "Value of i: " << i << endl;
    cout << "Value of j: " << j << endl;

    while(i<=mid){
        sortedArray.push_back(arr[i]);
        i++;
    }

    while(j<=endOfArray){
        sortedArray.push_back(arr[j]);
        j++;
    }

    // Print sorted array before merge
    cout << "Value of sorted array before merge is: " << endl;
    printArray(sortedArray, 0, sortedArray.size() - 1);

    // Now, assign sorted array to original array
    int index = 0;
    for(int i=startOfArrary; i<=endOfArray; i++){
        arr[i] = sortedArray[index];
        index++;
    }

    cout << "Sorted subarrays" << endl;
}

void mergeSubarray(vector<int> &arr, int startOfArray, int endOfArray){
    int mid = (endOfArray - startOfArray)/2;
    int subArray1Size = mid - startOfArray + 1;
    int subArray2Size = endOfArray - mid;
    if(endOfArray <= startOfArray){
        return;
    }
    mergeSubarray(arr, startOfArray, mid);
    mergeSubarray(arr, mid + 1, endOfArray);

    cout << "Printing All Information" << endl;
    printAllInfo(arr, startOfArray, mid, endOfArray, subArray1Size, subArray2Size);

    // Call merge function
    cout << "Sorting subarrays" << endl;
    sortSubArray(arr, startOfArray, mid, endOfArray);

    cout << "Merged sorted subarrays: " << endl;
    printArray(arr, startOfArray, endOfArray);
    cout << endl;
}

void mergeSort(vector<int> &arr){
    int endOfArray = arr.size() - 1;
    int startOfArray = 0;
    mergeSubarray(arr, startOfArray, endOfArray);
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

    mergeSort(arr);

    return 0;
}


