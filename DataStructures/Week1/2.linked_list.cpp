#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int key;
        Node *next;
        Node(int keyValue, Node* nextValue){
            key = keyValue;
            next = nextValue;
        }
};

class LinkedList{
    public:
        Node *head;
        LinkedList(){
            head = NULL;
        }

        bool emptyList(){
            if(head == NULL){
                return true;
            }
            return false;
        }

        void raiseEmptyListError(){
            if(emptyList()){
                cout << "Error! Empty List" << endl;
                exit(1); 
            }
        }

        void printAll(){
            cout << "Elements in Linked list: " << endl;
            Node *temp = head;
            while(temp != NULL){
                cout << temp->key << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        // push to front of linked list
        void pushFront(int key){
            // Create a new node
            Node *node = new Node(key, head);
            // head should point to new node
            head = node;
        }

        // get the first item
        int topFront(){
            // If linked list is empty
            raiseEmptyListError();
            
            // Else return head's key
            return head->key;
        }

        // Remove the front item
        int popFront(){
            raiseEmptyListError();

            // store key value
            int keyValue = head->key;
            head = head->next;
            return keyValue;
        }

        // Add item to the back
        void pushBack(int key){
            // Create new node
            Node *node = new Node(key, NULL);
            // If list is empty
            if(head == NULL){
                head = node;
                return;   
            }

            Node *temp = head;
            // Go to the end of the linked list.
            while(temp->next != NULL){
                temp = temp -> next;
            }
            temp->next = node;
            return;
        }

        // Return the last element
        int topBack(){
            // If list is empty
            raiseEmptyListError();

            Node *temp = head;
            while(temp->next != NULL){
                temp = temp -> next;
            }
            return temp->key;
        }

        // popBack
        int popBack(){
            int key;
            // If empty list
            raiseEmptyListError();
            
            // If only one element
            if(head->next == NULL){
                key = head->key;
                head = NULL;
                return key;
            }

            // Else
            Node *temp = head;
            while(temp->next->next != NULL){
                temp = temp -> next;
            }

            key = temp->next->key;
            temp->next = NULL;
            return key;
        }

        bool findKey(int keyValue){
            // empty list
            if(emptyList()){
                return false;
            }

            Node *temp = head;
            while(temp != NULL){
                if(temp->key == keyValue){
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }

        void eraseKey(int keyValue){
            // empty list
            raiseEmptyListError();

            if(head -> next == NULL){
                if(head -> key == keyValue){
                    head = NULL;
                    return;
                }
                else{
                    cout << "Error! Key not found." << endl;
                    exit(1); 
                }
            }   

            // Else
            Node *temp = head;
            while(temp -> next != NULL){
                if(temp -> next -> key == keyValue){
                    // key found
                    temp->next = temp->next->next;
                    return;
                }
                temp = temp -> next;
            }

            // Key not found
            cout << "Error! Key not found" << endl;
            exit(1);
        }

        // Add before given node
        void addBefore(int nodeValue, int keyValue){
            // empty
            raiseEmptyListError();

            // single element
            if(head -> next == NULL){
                if(head -> key == nodeValue){
                    // Found.
                    pushFront(keyValue);
                    return;
                }
                else{
                    cout << "Error! Key not found!" << endl;
                    exit(1);
                }
            }

            // Else
            Node *temp = head;
            while(temp -> next != NULL){
                if(temp -> next -> key == nodeValue){
                    Node *node = new Node(keyValue, temp->next);
                    temp->next = node;
                    return;
                }
                temp = temp -> next;
            }

            cout << "Error! Key not found!" << endl;
            exit(1);
        }

        // Add after given node.
        void addAfter(int nodeValue, int keyValue){
            // empty
            raiseEmptyListError();

            Node *temp = head;
            while(temp != NULL ){
                if(temp->key == nodeValue){
                    // found it
                    Node *node = new Node(keyValue, temp->next);
                    temp->next = node;
                    return;
                }
                temp = temp -> next;
            }

            cout << "Error! Key not found!" << endl;
            exit(1);
        }
};

/**
 * Functions to implement
 * pushFront(key)
*/
int main(){
    // Starting our linked list
    LinkedList linkedList = LinkedList();
    linkedList.pushFront(10);
    linkedList.pushFront(100);
    linkedList.pushFront(1000);
    linkedList.printAll();
    int popped = linkedList.popFront();
    cout << "Popped element is: " << popped << endl;
    linkedList.printAll();
    linkedList.pushBack(1000);
    linkedList.pushBack(10000);
    linkedList.printAll();
    cout << "last element is: " << linkedList.topBack() << endl;
    cout << "Popped out last element is : " << linkedList.popBack() << endl;
    linkedList.printAll();
    if(linkedList.findKey(100)){
        cout << "Found key " << 100 << endl;
    }
    if(!linkedList.findKey(10000)){
        cout << "Not found: " << 10000 << endl;
    }
    linkedList.pushBack(148);
    linkedList.pushBack(150);
    linkedList.pushBack(200);
    linkedList.printAll();
    cout << "Erasing Key 200" << endl;
    linkedList.eraseKey(200);
    linkedList.printAll();
    cout << "Adding before 150" << endl;
    linkedList.addBefore(150, 200);
    cout << "Adding before 200" << endl;
    linkedList.addBefore(200, 250);
    linkedList.printAll();
    cout << "Adding after 150" << endl;
    linkedList.addAfter(150, 300);
    cout << "Adding after 200" << endl;
    linkedList.addAfter(200, 350);
    linkedList.printAll();

    return 0;
}