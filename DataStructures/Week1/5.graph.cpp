#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        string key;
        int index;
        Node(string keyValue, int indexValue){
            key = keyValue;
            index = indexValue;
        }
};

class Map{
    public:
        vector<Node *> keyMapping;
        void addMap(string key){
            for(int i=0; i<keyMapping.size(); i++){
                int compareValue = keyMapping[i]->key.compare(key);
                if(compareValue == 0){
                    // No need to add node
                    cout << "Key already exists" << endl;
                    return;
                }
            }
            // create new node and add it to the vector
            Node *node = new Node(key, keyMapping.size());
            keyMapping.push_back(node);
        }

        int getIndex(string key){
            for(int i=0; i<keyMapping.size(); i++){
                int compareValue = keyMapping[i]->key.compare(key);
                if(compareValue == 0){
                    // Found the key, return index
                    return keyMapping[i]->index;
                }
            }
            // Not found
            cout << key << " key is not present in the Graph." << endl;
            // Adding key
            cout << "Adding key." << endl;
            addMap(key);
            return keyMapping.size() - 1;
        }

        string getKey(int index){
            if(index >= keyMapping.size()){
                cout << "Error. No such index present!" << endl;
                exit(1);
            }
            return keyMapping[index]->key;
        }

        int getGraphSize(){
            return keyMapping.size();
        }
};

class Graph{
    public:
        vector< vector<int> > neighbours;
        Map *map;
        Graph(int maxSize){
            neighbours.resize(maxSize);
            for(int i=0; i<neighbours.size(); i++){
                neighbours[i] = vector<int>();
            }
            map = new Map();
        }

        void addPath(string key1, string key2){
            int index1 = map->getIndex(key1);
            int index2 = map->getIndex(key2);
            neighbours[index1].push_back(index2);
            //neighbours[index2].push_back(index1);
        }

        void printGraph(){
            int currentGraphSize = map->getGraphSize();
            cout << "There are " << currentGraphSize << " nodes in the graph." << endl;
            cout << "Connection is as follows: " << endl;
            for(int i=0; i<currentGraphSize; i++){
                cout << map->getKey(i) << " -> ";
                for(int j=0; j<neighbours[i].size(); j++){
                    cout << map->getKey(neighbours[i][j]) << "  ";
                }
                cout << endl;
            }
        }

        void searchWhileStackIsEmpty(stack<int> &dfsStack, vector<bool> &visited){
            while(!dfsStack.empty()){
                // Visit the current node
                int popped = dfsStack.top();

                visited[popped] = true;
                cout << "Node visited : " << map->getKey(popped) << endl;
                dfsStack.pop();

                // Visit popped all neighbours
                for(int i=0; i<neighbours[popped].size(); i++){
                    int currentNeighbour = neighbours[popped][i];
                    if(!visited[currentNeighbour]){
                        dfsStack.push(neighbours[popped][i]);
                    }
                }
            }
        }

        void depthFirstSearch(string key){
            int currentGraphSize = map->getGraphSize();
            vector<bool> visited(currentGraphSize, false);
            stack<int> dfsStack;
            int node = map->getIndex(key);
            dfsStack.push(node);
            searchWhileStackIsEmpty(dfsStack, visited);
        }

        void depthFirstSearch(){
            int currentGraphSize = map -> getGraphSize();
            vector<bool> visited(currentGraphSize, false);
            for(int i=0; i<currentGraphSize; i++){
                if(!visited[i]){
                    // do dfs here
                    cout << "Root: " << map->getKey(i) << endl;;
                    stack<int> dfsStack;
                    int node = i;
                    dfsStack.push(node);
                    searchWhileStackIsEmpty(dfsStack, visited);
                }
            }
        }

        void searchWhileQueueIsEmpty(queue<int> &bfsQueue, vector<bool> &visited){
            while(!bfsQueue.empty()){
                int popped = bfsQueue.front();
                bfsQueue.pop();
                visited[popped] = true;
                cout << "Node Visited: " << map -> getKey(popped) << endl;
                for(int i=0; i<neighbours[popped].size(); i++){
                    int currentNeighbour = neighbours[popped][i];
                    if(!visited[currentNeighbour]){
                        bfsQueue.push(currentNeighbour);
                    }
                }
            }
        }

        void breadthFirstSearch(string key){
            int currentGraphSize = map -> getGraphSize();
            vector<bool> visited(currentGraphSize, false);
            queue<int> bfsQueue;
            int node = map -> getIndex(key);
            bfsQueue.push(node);
            searchWhileQueueIsEmpty(bfsQueue, visited);
        }
}; 

int main(){
    int maxSize = 100;
    Graph graph(100);
    graph.addPath("1", "2");
    graph.addPath("1", "3");
    graph.addPath("2", "4");
    graph.addPath("2", "5");
    graph.addPath("3", "6");
    graph.addPath("3", "7");
    graph.printGraph();

    cout << endl;
    string key = "1";
    cout << "Doing BFS from Node: " << key << endl;
    graph.breadthFirstSearch(key);
    return 0;
}