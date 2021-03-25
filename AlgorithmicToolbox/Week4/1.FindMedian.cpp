#include<bits/stdc++.h>
using namespace std;
/*
Program to find median in linear time!

if number of elements are odd: 
    find N/2 th element using nth_element() function 
    And then value at index N/2 is median of given array
    nth_element(arr.begin(), arr.begin() + N/2, arr.end())
else:
    Find N/2 th and (N-1)/2 th element, and return their average.

*/

void printArray(vector<int> &arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

double getMedian(vector<int> &arr){
    int N = arr.size();
    if(N%2 == 0){
        nth_element(arr.begin(), arr.begin() + N/2, arr.end());
        nth_element(arr.begin(), arr.begin() + (N-1)/2, arr.end());
        double element1 = arr[N/2];
        double element2 = arr[(N-1)/2];
        double median = (element1 + element2)/2;
        return median;
    } else {
        nth_element(arr.begin(), arr.begin() + N/2, arr.end());
        double element = arr[N/2];
        return element;
    }
}

int main(){
    vector<int> arr;
    vector<int> sortedArray;
    int maxSize = 10;
    srand(time(0));
    for(int i=0; i<maxSize; i++){
        int val = rand() % 100;
        arr.push_back(val);
        sortedArray.push_back(val);
    }
    cout << "Array: " << endl;
    printArray(arr);
    cout << endl;
    sort(sortedArray.begin(), sortedArray.end());
    cout << "Sorted Array: " << endl;
    printArray(sortedArray);
    cout << endl;

    double medianValue = getMedian(arr);
    cout << "Median Value: " << endl;
    cout << medianValue << endl;

    cout << "Expected Median Value: " << endl;
    if(maxSize % 2 == 0){
        double element1 = sortedArray[maxSize/2];
        double element2 = sortedArray[(maxSize - 1)/2];
        double median = (element1 + element2)/2;
        cout << median << endl;
    } else {
        double element1 = sortedArray[maxSize/2];
        cout << element1 << endl;
    }

    return 0;
}