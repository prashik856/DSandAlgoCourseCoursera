#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr, int begin, int end){
    for(int i=begin; i<=end; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int randomSelect(int sizeOfArray, int start, int end){
    srand(time(0));
    bool gotRand = false;
    int returnValue = 0;
    while(!gotRand){
        int randomNumber = rand() % sizeOfArray;
        if(randomNumber >= start && randomNumber <= end){
            gotRand = true;
            returnValue = randomNumber;
        }
    }
    return returnValue;
}

void swapElements(vector<int> &arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int qsPartition(vector<int> &arr, int start, int end){
    // Select pivot
    int pivot = arr[start];
    int finalPosition;
    int j = start;
    for(int i= start + 1; i<=end; i++){
        cout << "For i: " << i << endl;
        printArray(arr, start, end);
        cout << endl;
        if(arr[i] > pivot){
            // increase i, happening
            continue;
        }

        if(arr[i] <= pivot){
            if(i - j > 1){
                // increase j
                j++;
                // swap j and i
                swapElements(arr, j, i);
                // increase i, which is already happening.
            }

            else if(i -j == 1){
                // increase j
                j++;
                // increase i, happening
            }
        }
    }
    finalPosition = j;
    swapElements(arr, start, finalPosition);
    return finalPosition;
}

void randomizedQuickSort(vector<int> &arr, int start, int end){
    if(end <= start){
        return;
    }
    // Get random pivot
    int randomIndex = randomSelect(arr.size(), start, end);
    cout << "Random Index is: " << randomIndex << endl;
    // Swap pivot and first position
    swapElements(arr, randomIndex, start);
    // Perform partition.
    int finalPosition = qsPartition(arr, start, end);
    cout << "Final Position " << finalPosition << endl;
    randomizedQuickSort(arr, start, finalPosition - 1);
    randomizedQuickSort(arr, finalPosition + 1, end);
}

void quickSort(vector<int> &arr){
    int sizeOfArray = arr.size();
    int start = 0;
    int end = sizeOfArray - 1;
    randomizedQuickSort(arr, start, end);
}

int main(){
    vector<int> arr;
    int maxSizeOfArray = 10;
    srand(time(0));
    for(int i=0; i<maxSizeOfArray; i++){
        arr.push_back(rand() % 100);
    }
    cout << "Value of whole Array: " << endl;
    printArray(arr, 0, arr.size() - 1);

    quickSort(arr);

    cout << "Sorted Array: " << endl;
    printArray(arr, 0, arr.size() - 1);

    return 0;
}