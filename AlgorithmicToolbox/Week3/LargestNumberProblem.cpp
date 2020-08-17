//Given an array, sort it mate, that's the highest number made
#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

void StressTest(){
    int n = rand() % 100000;
    vector<int> numbers(n);
    for(int i=0; i<n; ){
        int val = rand()%1000000;
        numbers[i] = val;
        i++;
    }
}

void SetInput(vector<int>* numbers){
    int n = (*numbers).size();
    for(int i=0; i<n; ){
        int val = rand()%1000000;
        (*numbers)[i] = val;
        i++;
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

//Part of Merger Sort
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

//Part of Merger Sort
void DivideArrayMergeSort(vector<int>* numbers, int left, int right){
    if(left < right){
        int mid = (left + right)/2;
        DivideArrayMergeSort(&(* numbers), left, mid);
        DivideArrayMergeSort(&(* numbers), mid+1, right);
        MergeArray(&(*numbers), left, mid, right);
    }
}

//Part of Merge sort.
void MergeSort(vector<int>* numbers){
    int size = (*numbers).size();
    int left = 0;
    int right = size - 1;
    DivideArrayMergeSort(&(*numbers), left, right);
}

//Part of Bucket Sort
void PrintBucket(vector< vector<int> >& bucket){
    for(int i=0; i<bucket.size();i++){
        cout << "Bucket " << i << " ";
        for(int j=0; j<bucket[i].size();j++){
            cout << bucket[i][j] << " ";
        }
        cout << endl;
    }
}

//Mainly used when the input is bound or concentrated between some numbers
// e.g. The input is only between 100000 to 999999
// we need to sort the bucket here.
void BucketSort(vector<int>* numbers){
    vector< vector<int> > bucket(10);
    int divider = 100000;
    int remover = 1000000;
    int size = (*numbers).size();
    for(int i=0; i<size; i++){
        int val = (*numbers)[i] % remover;
        val = val / divider;
        bucket[val].push_back((*numbers)[i]);
    }

    int index = 0;
    for(int i=0; i<bucket.size(); i++){
        MergeSort(&bucket[i]);
        for(int j=0; j<bucket[i].size(); j++){
            (*numbers)[index] = bucket[i][j];
            index++;
        }
    }
}


//Radix Sort
//When elements are in the range of 1 to n^2
void RadixSort(vector<int>* numbers){
    vector< vector<int> > bucket(10);
    long long divisor = 10;
    long long remover = 1;
    int size = (*numbers).size();
    while(bucket[0].size() != size){
        for(int i=0; i<bucket.size(); i++){
            bucket[i].clear();
        }
        //Fill the bucket
        for(int i=0; i<size; i++){
            int val = (*numbers)[i];
            val = val % divisor;
            val = val / remover;
            bucket[val].push_back((*numbers)[i]);
        }
        int index = 0;
        for(int i=0; i<bucket.size(); i++){
            for(int j=0; j<bucket[i].size(); j++){
                (*numbers)[index] = bucket[i][j];
                index++;
            }
        }
        divisor = divisor * 10;
        remover = remover * 10;
    }
}

//Counting Sort
//Based on key between a specific range
// if numbers are only between 0 to 9
//Linear in time.
void CountingSort(vector<int>* numbers){
    
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
    //MergeSort(&numbers);
    //BucketSort(&numbers);
    //RadixSort(&numbers);
    //CountingSort(&numbers);
    PrintArray(&numbers);
    return 0;
}