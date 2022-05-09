#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
        int size;
        int *stack;
        int head;
        Stack(int sizeValue){
            stack = new int[sizeValue];
            head = 0;
            size = 0;
        }

        void printAll(){
            cout << "Current elements in the stack" << endl;
            for(int i=0; i<size; i++){
                cout << stack[i] << " ";
            }
            cout << endl;
        }

        void push(int key){
            stack[head] = key;
            head++;
            size++;
        }

        int pop(){
            head--;
            size--;
            return stack[head];
        }

        int size(){
            return size;
        }

        bool empty(){
            if(size == 0){
                return true;
            }
            return false;
        }    
};

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
    

    // Stack using array
    Stack mystack = Stack(100);
    mystack.push(10);
    mystack.push(20);
    mystack.push(30);
    mystack.push(40);
    mystack.push(50);
    mystack.pop();
    mystack.pop();
    mystack.size();
    mystack.empty();


    // Stack using stack stl
    stack<int> stlStack;
    stlStack.empty(); // Returns if stack is empty (bool value)
    stlStack.push(10); // Push into stack
    stlStack.push(20); 
    stlStack.top(); // Returns the top element of the stack
    stlStack.pop(); // pops the top element
    stlStack.size(); // Returns the current size of the stack


    return 0;
}