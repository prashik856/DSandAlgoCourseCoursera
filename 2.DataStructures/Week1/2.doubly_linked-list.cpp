#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int key;
        Node *next;
        Node *prev;
        Node(int keyValue, Node *nextValue, Node *prevValue){
            key = keyValue;
            next = nextValue;
            prev = prevValue;
        }
};

class LinkedList{
    public:
        Node *head;
        Node *tail;
        LinkedList(){
            head = NULL;
            tail = NULL;
        }

        bool isEmpty(){
            if(head == NULL){
                return true;
            }
            return false;
        }

        void raiseEmptyError(){
            if(isEmpty()){
                cout << "Error! Empty List!" << endl;
                exit(1);
            }
        }

        void raiseKeyNotFoundError(){
            cout << "Error! Key not found!" << endl;
            exit(1);
        }

        void printInfo(){
            cout << "head: " << head->key;
            cout << " | tail: " << tail->key << endl;;
        }

        void printForward(){
            Node *node = head;
            cout << "Current Elements are: " << endl;
            while(node != NULL){
                cout << node -> key << " ";
                node = node -> next;
            }
            cout << endl;
        }

        void printBackward(){
            Node *node = tail;
            cout << "Current elements backwards are: " << endl;
            while(node != NULL){
                cout << node -> key << " ";
                node = node -> prev;
            }
            cout << endl;
        }

        void printAll(){
            printInfo();
            printForward();
            printBackward();
        }

        void pushFront(int key){
            Node *node = new Node(key, NULL, NULL);
            
            // empty
            if(isEmpty()){
                head = node;
                tail = node;
                return;
            }

            // Else
            node -> next = head;
            head -> prev = node;
            head = node;
        }

        int topFront(){
            raiseEmptyError();
            return head->key;
        }

        int popFront(){
            raiseEmptyError();

            int key = head->key;
            head = head -> next;
            head -> prev = NULL;
            return key;
        }

        void pushBack(int key){
            Node *node = new Node(key, NULL, NULL);
            if(isEmpty()){
                head = node;
                tail = node;
                return;
            }

            // Else
            node -> prev = tail;
            tail -> next = node;
            tail = node;
        }

        int topBack(){
            raiseEmptyError();

            return tail->key;
        }

        int popBack(){
            raiseEmptyError();
            int key = tail -> key;
            tail = tail -> prev;
            tail -> next = NULL;
            return key;
        }

        bool find(int key){
            raiseEmptyError();

            Node *node = head;
            while(node != NULL){
                if(node -> key == key){
                    return true;
                }
                node = node -> next;
            }
            return false;
        }

        void erase(int key){
            raiseEmptyError();

            // Single element
            if(head -> next == NULL){
                if(head -> key == key){
                    head = NULL;
                    tail = NULL;
                    return;
                }
                raiseKeyNotFoundError();
            }

            // First item?
            if(head -> key == key){
                head = head -> next;
                head -> prev = NULL;
                return;
            }

            // last item?
            if(tail -> key == key){
                tail = tail -> prev;
                tail -> next = NULL;
                return;
            }

            // Else
            Node *node = head;
            while(node -> next != NULL){
                if(node -> key == key){
                    // found it
                    node -> prev -> next = node -> next;
                    node -> next -> prev = node -> prev;
                    return;
                }
                node = node -> next;
            }

            raiseKeyNotFoundError();

        }
};

int main(){
    LinkedList linkedList = LinkedList();
    linkedList.pushFront(10);
    linkedList.pushFront(20);
    linkedList.pushFront(30);
    linkedList.pushFront(40);
    linkedList.printInfo();
    linkedList.printForward();
    cout << "Top element: " << linkedList.topFront() << endl;
    cout << "Popped element; " << linkedList.popFront() << endl;
    linkedList.printForward();
    linkedList.printBackward();
    linkedList.pushBack(40);
    linkedList.pushBack(50);
    linkedList.pushBack(60);
    linkedList.printAll();
    cout << "Top back element: " << linkedList.topBack() << endl;
    cout << "Popping back element: " << linkedList.popBack() << endl;
    linkedList.printAll();
    linkedList.pushBack(70);
    linkedList.pushBack(80);
    linkedList.printAll();
    if(linkedList.find(10)){
        cout << "Found 10" << endl;
    }
    if(!linkedList.find(90)){
        cout << "Not found 90" << endl;
    }
    linkedList.erase(40);
    linkedList.printAll();

    return 0;
}