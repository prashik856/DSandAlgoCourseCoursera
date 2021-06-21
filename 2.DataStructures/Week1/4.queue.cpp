#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
        int head;
        int tail;
        int size;
        int *arr;
        Queue(int sizeValue){
            arr = new int[sizeValue];
            head = 0;
            tail = 0;
            size = 0;
        }

        // empty
        bool empty(){
            if(size == 0){
                return true;
            }
            return false;
        }

        // size
        bool getSize(){
            return size;
        }

        // push
        void push(int key){
            arr[head] = key;
            head++;
            size++;
        }

        // pop
        int pop(){
            size--;
            int value = arr[tail];
            tail++;
            return value;
        }
};

int main(){
    // Enqueue, dequeue, empty?

    // Queue using module
    queue<int> q;
    // Empty
    bool emptyVariable = q.empty();
    // enqueue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    // dequeue
    q.pop();
    q.pop();
    int temp = q.front();
    temp = q.back();

    // Queue using array
    // head, tail, size, push, pop, empty

    return 0;
}