#include<bits/stdc++.h>
using namespace std;

int main(){
    // Using stack inbuilt
    stack<int> st;
    // Push
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    //Pop
    st.pop();
    st.pop();
    // top
    st.top();
    if(st.empty()){
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty";
    }
    //Size
    cout << "Size of stack is: " << st.size();


    // Stack using vector?
    vector<int> arr;
    // push
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    // pop
    arr.pop_back();
    arr.pop_back();
    // empty?
    arr.empty();
    // Size
    arr.size();
    // top
    cout << "top: " << arr[arr.size() - 1] << endl;


    return 0;
}