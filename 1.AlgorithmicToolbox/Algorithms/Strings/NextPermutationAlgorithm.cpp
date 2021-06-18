#include<bits/stdc++.h>
using namespace std;

string NextPermutationAlgorithmDetails(string s){
    // Finding longest non-increasing sequence
    cout << "Input: " << s << endl;
    int pivot = 0;
    int n = s.size();
    
    for(int i=n-1; i>0; i--){
        if(s[i] > s[i-1]){
            // Found the pivot
            // pivot is i
            pivot = i - 1;
            break;
        }
    }
    cout << "Pivot: " << pivot << " | Value: " << s[pivot] << endl;

    // Find Rightmost successor to pivot
    int successor = n-1;
    for(int i=pivot+1; i<n; i++){
        if(s[pivot] >= s[i]){
            successor = i-1;
            break;
        }
    }
    cout << "Successor: " << successor << " | Value: " << s[successor] << endl;

    // Swap successor and pivot
    char temp = s[pivot];
    s[pivot] = s[successor];
    s[successor] = temp;
    cout << "String after swapping pivot and rightmost successor: " << s << endl;

    // Reverse the suffix
    string reverseSuffix;
    for(int i=pivot+1; i<n; i++){
        reverseSuffix.push_back(s[i]);
    }
    int index = pivot + 1;
    for(int i=reverseSuffix.size()-1; i>=0; i--){
        s[index] = reverseSuffix[i];
        index++;
    }

    cout << "String after reversing the suffix: " << s << endl;

    return s;
}

string NextPermutationAlgorithm(string s){
    // Finding longest non-increasing sequence
    //cout << "Input: " << s << endl;
    int pivot = 0;
    int n = s.size();
    
    for(int i=n-1; i>0; i--){
        if(s[i] > s[i-1]){
            // Found the pivot
            // pivot is i
            pivot = i - 1;
            break;
        }
    }
    //cout << "Pivot: " << pivot << " | Value: " << s[pivot] << endl;

    // Find Rightmost successor to pivot
    int successor = n-1;
    for(int i=pivot+1; i<n; i++){
        if(s[pivot] >= s[i]){
            successor = i-1;
            break;
        }
    }
    //cout << "Successor: " << successor << " | Value: " << s[successor] << endl;

    // Swap successor and pivot
    char temp = s[pivot];
    s[pivot] = s[successor];
    s[successor] = temp;
    // cout << "String after swapping pivot and rightmost successor: " << s << endl;

    // Reverse the suffix
    string reverseSuffix;
    for(int i=pivot+1; i<n; i++){
        reverseSuffix.push_back(s[i]);
    }
    int index = pivot + 1;
    for(int i=reverseSuffix.size()-1; i>=0; i--){
        s[index] = reverseSuffix[i];
        index++;
    }

    //cout << "String after reversing the suffix: " << s << endl;

    return s;
}

int main(){
    int t;
    cin >> t;
    vector<string> inputs(t);
    vector<string> expectedOutputs(t);
    vector<string> outputs(t);
    for(int i=0; i<t; i++){
        string s;
        cin >> s;
        inputs[i] = s;
        string result;
        result = NextPermutationAlgorithm(s);
        outputs[i] = result;
    }
    
    for(int i=0; i<t; i++){
        string s;
        cin >> s;
        expectedOutputs[i] = s;
        int value = expectedOutputs[i].compare(outputs[i]);
        cout << "Test Case: " << i + 1 << endl;
        if(value != 0){
            cout << "Result: Error!" << endl;
            cout << "Input: " << inputs[i] << endl;
            cout << "Expected Output: " << expectedOutputs[i] << endl;
            cout << "Output Obtained: " << outputs[i] << endl;
            NextPermutationAlgorithmDetails(inputs[i]);
            cout << endl;
            break;
        } else {
            cout << "Result: Passed!" << endl;
            cout << endl;
            continue;
        }
    }

}