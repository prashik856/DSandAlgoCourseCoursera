//Given an array, sort it mate, that's the highest number made
#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

void StressTest(){
    int n = rand() % 100000;
    vector<int> numbers(n);
    for(int i=0; i<n; i++){
        numbers[i] = rand()%100000;
    }
}

void SetInput(vector<int>* numbers){
    int n = (*numbers).size();
    for(int i=0; i<n; i++){
        (*numbers)[i]=rand()%100000;
    }
}

void PrintArray(vector<int>* numbers){
    int size = (*numbers).size();
    for(int i=0; i<size; i++){
        cout << (*numbers)[i] << " ";
    }
    cout << "\n";
}

//Selecting max/min value and then swapping
void SelectionSort(vector<int>* numbers){
    int n = (*numbers).size();
    for(int i=0; i<n-1; i++){
        int maxValue=i;
        for(int j=i+1; j<n; j++){
            if((*numbers)[maxValue] < (*numbers)[j]){
                maxValue = j;
            }
        }
        int temp = (*numbers)[i];
        (*numbers)[i] = (*numbers)[maxValue];
        (*numbers)[maxValue] = temp;
    }
}

//Comparing i and i+1 in each iteration
void BubbleSort(vector<int>* numbers){
    int size = (*numbers).size();
    for(int i=0; i<size; i++){
        for(int j=0; j<size-i-1; j++){
            if((*numbers)[j] < (*numbers)[j+1]){
                //swap i and j
                int temp = (*numbers)[j];
                (*numbers)[j] = (*numbers)[j+1];
                (*numbers)[j+1]= temp;
            }
        }
    }
}

// Start with element 0, end up till last element
// While moving forward, insert the element in it's proper sorted order
void InsertionSort(vector<int>* numbers){
    int size = (*numbers).size();
    for(int i=1; i<size; i++){
        //Find min value from i+1 to size
        int val = (*numbers)[i];
        for(int j=0; j<i; j++){
            if((*numbers)[j] < val){
                int temp = (*numbers)[j];
                (*numbers)[j] = (*numbers)[i];
                (*numbers)[i] = temp;
            }
        }
    }
}

void MergeArray(vector<int>* numbers, int left, int mid, int right){

    vector<int> leftArray;
    vector<int> rightArray;

    //Copy contents
    for(int i=left; i<=mid; i++){
        leftArray.push_back((*numbers)[i]);
    }
    for(int i=mid+1; i<=right; i++){
        rightArray.push_back((*numbers)[i]);
    }

    //Get size of left and right array
    int size1 = leftArray.size();
    int size2 = rightArray.size();

    //Sort here
    int i=0,j=0,k=left;
    while(i < size1 && j < size2){
        if(leftArray[i] <= rightArray[j]){
            (*numbers)[k] = leftArray[i];
            i++;
        }
        else{
            (*numbers)[k] = rightArray[j];
            j++;
        }
        k++;
    }

    //Copy remaining contents from leftarray
    while(i<size1){
        (*numbers)[k] = leftArray[i];
        i++;
        k++;
    }

    //Copy remaining contents from rightarray
    while(j<size2){
        (*numbers)[k] = rightArray[j];
        j++;
        k++;
    }
}

void DivideArrayMergeSort(vector<int>* numbers, int left, int right){
    if(left < right){
        int mid = (left + right)/2;
        DivideArrayMergeSort(&(* numbers), left, mid);
        DivideArrayMergeSort(&(* numbers), mid+1, right);
        MergeArray(&(*numbers), left, mid, right);
    }
    cout << "Array received: " ;
    for(int i=left; i<=right; i++){
        cout << (*numbers)[i] << " ";
    }
    cout << endl;
}

void MergeSort(vector<int>* numbers){
    int size = (*numbers).size();
    int left = 0;
    int right = size - 1;
    DivideArrayMergeSort(&(*numbers), left, right);
}

int main(){
    //StressTest();
    int n;
    cin >> n;
    vector<int> numbers(n);
    SetInput(&numbers);
    //SelectionSort(&numbers);
    //BubbleSort(&numbers);
    //InsertionSort(&numbers);
    MergeSort(&numbers);
    PrintArray(&numbers);
    return 0;
}