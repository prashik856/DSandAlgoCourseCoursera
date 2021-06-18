#include<bits/stdc++.h>
using namespace std;
/*
MergeSort(arr[], l,  r)
If r > l
     1. Find the middle point to divide the array into two halves:  
             middle m = (l+r)/2
     2. Call mergeSort for first half:   
             Call mergeSort(arr, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)
*/

void printArray(vector<int> &arr, int begin, int end){
    for(int i=begin; i<=end; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeArray(vector<int> &arr, int start, int mid, int end){
    vector<int> sortedArray;
    int i,j;
    for(i=start, j=mid+1; i<=mid && j<=end; ){
        if(arr[i] < arr[j]){
            // push arr[i]
            // increase i
            sortedArray.push_back(arr[i]);
            i++;
        } else {
            sortedArray.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){
        sortedArray.push_back(arr[i]);
        i++;
    }

    while(j<=end){
        sortedArray.push_back(arr[j]);
        j++;
    }

    // Push sorted array into a
    int index = 0;
    for(i=start; i<=end; i++){
        arr[i] = sortedArray[index];
        index++;
    }
}

void mergeSort(vector<int> &arr, int start, int end){
    if(end > start){
        int mid = (end + start)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        mergeArray(arr, start, mid, end);
    } else {
        return;
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

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array: " << endl;
    printArray(arr, 0, arr.size() - 1);

    return 0;
}


