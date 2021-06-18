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

    // Get size of array:
    int lenght = arr1.size();
    int maxLength = arr1.max_size();

    // Beginning pointer
    arr1.begin();
    // End pointer
    arr1.end();
    // Array empty
    bool isEmpty = arr1.empty();
    // Pushback
    arr1.push_back(10);
    // Pop element from back
    arr1.pop_back(); // this does not return back the element
    // Get the front element
    int element = arr1.front();
    // Get the back element
    element = arr1.back();
    //Size
    arr1.size();
    // Insert at a position
    arr1.insert(arr1.begin()+1, 20);
    // Clear the vector
    arr1.clear();
    // Erase
    arr1.erase(arr1.begin());
    arr1.erase(arr1.begin(), arr1.begin() + 2);


    // 2D vectors
    // Define
    vector<vector<int>> arr2d;
    // initialize array
    vector<vector<int>> arr2d1 = {
        {1,2,3},
        {1,2,3},
        {1,2,3}
    };

    // create vector with size equal to given row
    int row = 5;
    int column = 10;
    vector<vector<int>> arr2d3(row);
    for(int i=0; i<row; i++){
        arr2d3[i] = vector<int>(column);
    }

    // Initialize vector with n rows and m columns
    // with all zeroes.
    int n = 5;
    int m = 10;
    vector<vector<int>> vec(n, vector<int> (m, 0));


    // Create vector with n rows and m columns with initialization
    vector<vector<int>> vec2(n, vector<int> (m));

    



    


    return 0;
}