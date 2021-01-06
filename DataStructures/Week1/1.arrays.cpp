#include<bits/stdc++.h>
using namespace std;

int main(){
    // Vector initialization
    int size = 10;
    // Empty vector
    vector<int> arr1;

    // Vector with size and initialization
    vector<int> arr2(size,10);

    // Initializations like array
    vector<int> arr3{10,20,30};

    // Initialization from array
    int arr[] = {10,20,30};
    int sizeOfArray = sizeof(arr)/sizeof(int);
    vector<int> arr4(arr, arr + sizeOfArray);

    // Initialization from another vector
    vector<int> arr5{10,20,30};
    vector<int> arr6(arr5.begin(), arr5.end());

    // Initialization all elements with particular value
    vector<int> arr7(size);
    fill(arr7.begin(), arr7.end(), 99);

    return 0;
}