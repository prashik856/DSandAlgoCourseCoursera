// We have input as Max weight size of bag, MaxWeight
// Seconde input is value array, V
// Third input is value of that element, W.

#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

void GenerateArrays(int arraySize, vector<int>* value, vector<int>* weight){
    for(int i=0; i<arraySize; i++){
        (*value)[i] = rand()%100;
        (*weight)[i] = rand()%10;
    }
}

void MergeSort(vector<float>* valuePerUnit, int left, int right, vector<int>* weight){
    int mid = (right-left)/2;
    if(left < right){
        //don't divide
        cout << "inside if" << endl;
        MergeSort(&(*valuePerUnit), left, mid, &(*weight));
        MergeSort(&(*valuePerUnit), mid+1, right, &(*weight));
    }

    vector<float> leftArray;
    vector<float> rightArray;
    vector<int> leftweightArray;
    vector<int> rightweightArray;

    for(int i=left; i<=mid; i++){
        leftArray.push_back((*valuePerUnit)[i]);
        leftweightArray.push_back((*weight)[i]);
    }
    for(int i=mid+1; i<=right; i++){
        rightArray.push_back((*valuePerUnit)[i]);
        rightweightArray.push_back((*weight)[i]);
    }

    cout << "Left Array: " << endl;
    for(int i=0; i<leftArray.size(); i++){
        cout << leftArray[i] << " ";
    }
    cout << endl;

    cout << "Right Array: " << endl;
    for(int i=0; i<rightArray.size(); i++){
        cout << rightArray[i] << " ";
    }
    cout << endl;

    //Sort here yo
    int i=0,j=0, k=left;
    int size1 = leftArray.size();
    int size2 = rightArray.size();
    while(i<size1 && j<size2){
        if(leftArray[i] < rightArray[j]){
            (*valuePerUnit)[k] = rightArray[j];
            (*weight)[k] = rightweightArray[j];
            j++;
        }
        else{
            (*valuePerUnit)[k] = leftArray[i];
            (*weight)[k] = leftweightArray[i];
            i++;
        }
        k++;
    }

    while(i<size1){
        (*valuePerUnit)[k] = leftArray[i];
        (*weight)[k] = leftweightArray[i];
        i++;
        k++;
    }

    while(j<size2){
        (*valuePerUnit)[k] = rightArray[j];
        (*weight)[k] = rightweightArray[j];
        j++;
        k++;
    }
    cout << endl;
}

void SortFunction(vector<float>* valuePerUnit, vector<int>* weight){
    //Do merge sort
    int left = 0;
    int right = (*valuePerUnit).size()-1;
    MergeSort(&(*valuePerUnit), left, right, &(*weight));
}

void SolveLongHike(int maxWeight, vector<int>* value, vector<int>* weight){
    int size = (*value).size();
    vector<float> valuePerUnit(size);
    for(int i=0; i<size; i++){
        valuePerUnit[i] = ((float)(*value)[i]) / (*weight)[i];
    }
    //Sort the valuePerUnit array. As we are sorting it, sort weight along with it.
    SortFunction(&valuePerUnit, &(*weight));
    // for(int i=0; i<size; i++){
    //     cout << valuePerUnit[i] << " ";
    // }
    // cout << endl;
}

int main(){
    int maxWeight;
    int arraySize;
    cin >> maxWeight;
    cin >> arraySize;
    vector<int> value(arraySize);
    vector<int> weight(arraySize);
    GenerateArrays(arraySize, &value, &weight);
    SolveLongHike(maxWeight, &value, &weight);
    return 0;
}