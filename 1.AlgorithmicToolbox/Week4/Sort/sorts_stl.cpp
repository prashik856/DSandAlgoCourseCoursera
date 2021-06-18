#include<bits/stdc++.h>
using namespace std;

int main(){
    int size = 100;
    vector<int> arr(size);
    for(int i=0; i<size; i++){
        arr[i] = i;
    }

    // Sorts in ascending order
    sort(arr.begin(), arr.end());

    // Sorting in descending order
    sort(arr.begin(), arr.end(), greater<int>());

    return 0;
}