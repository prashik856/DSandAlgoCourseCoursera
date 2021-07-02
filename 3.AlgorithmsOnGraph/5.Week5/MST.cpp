#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    private:
        vector<int> parent;
        vector<int> rank;
        int nodes;
    public:
        DisjointSet(int nodesValue){
            nodes = nodesValue;
            parent = vector<int>(nodes, -1);
            rank = vector<int>(nodes, 0);
            for(int i=0; i<nodes; i++){
                parent[i] = i;
            }
        }

        int Find(int x){
            // Find should return the parent of i
            int temp = parent[x];
            while(temp != parent[temp]) {
                temp = parent[temp];
            }

            return temp;
        }

        void Union(int x, int y){
            int xset = Find(x); // get root of x
            int yset = Find(y); // get root of y

            // if in the same set, return
            if(xset == yset){
                return;
            }

            // If rank of x is greater than that of y
            // put y below x
            if(rank[xset] > rank[yset]){
                parent[yset] = xset;
            } 
            // Else put x below y
            else {
                parent[xset] = yset;
                if(rank[xset] == rank[yset]){
                    rank[yset]++;
                }
            }
        }
};

class Graph{
    private:
        int nodes;
        vector< vector<int> > weights;
        vector< vector<int> > neighbours;
        vector<int> distance;
        vector<int> parent;
        vector< vector<int> > sortedWeights;
        int edges;
        vector<bool> visited;
    
    public:
        Graph(int nodesValue) {
            nodes = nodesValue;
            neighbours = vector< vector<int> >(nodes, vector<int>());
            weights = vector< vector<int> >(nodes,vector<int>(nodes, 99999999));
            edges = 0;
            sortedWeights = vector< vector<int> >();
            visited = vector<bool>(nodes, false);
            distance = vector<int>(nodes, 99999999);
            parent = vector<int>(nodes, -1);
        }

        void addEdge(int from, int to, int weight){
            neighbours[from].push_back(to);
            neighbours[to].push_back(from);
            weights[from][to] = weight;
            weights[to][from] = weight;
            sortedWeights.push_back(vector<int>());
            sortedWeights[edges].push_back(weight);
            sortedWeights[edges].push_back(from);
            sortedWeights[edges].push_back(to);
            edges++;
        }

        void printGraph(){
            cout << "Graph is: " << endl;
            for(int i=0; i<nodes; i++){
                cout << i << " -> ";
                for(int j=0; j<neighbours[i].size(); j++){
                    cout << neighbours[i][j] << "|" << weights[i][neighbours[i][j]] << " ";
                }
                cout << endl;
            }
        }

        void resetGraph(){
        	distance = vector<int>(nodes, 99999999);
            parent = vector<int>(nodes, -1);
            visited = vector<bool>(nodes, false);
        }

        vector< vector<int> > Kruskal(){
            DisjointSet disjointSet(nodes);
            vector< vector<int> > X;
            int sizeOfX = 0;
            sort(sortedWeights.begin(), sortedWeights.end());
            for(int i=0; i<sortedWeights.size(); i++){
                int from = sortedWeights[i][1];
                int to = sortedWeights[i][2];
                int findFrom = disjointSet.Find(from);
                int findTo = disjointSet.Find(to);
                if(findFrom != findTo){
                    disjointSet.Union(from, to);
                    X.push_back(vector<int>());
                    X[sizeOfX].push_back(sortedWeights[i][0]);
                    X[sizeOfX].push_back(sortedWeights[i][1]);
                    X[sizeOfX].push_back(sortedWeights[i][2]);
                    sizeOfX++;
                }
            }
            return X;
        }

        int getMinimum(){
        	int minimumValue = 99999999;
        	int minimumIndex = -1;
        	for(int i=0; i<nodes; i++){
        		if(distance[i] < minimumValue && !visited[i]){
        			minimumIndex = i;
        			minimumValue = distance[i];
        		}
        	}
        	return minimumIndex;
        }

        void Prims(){
        	resetGraph();
        	cout << "Using Prims Algorithm" << endl;
        	// pick any vertex - we select 0
        	distance[0] = 0;
        	
        	// Get minimum distance
        	int minimumIndex = 0;
        	int minimumDistance = distance[minimumIndex];

        	// Set parent of minimumindex as itself
        	parent[minimumIndex] = minimumIndex;

        	// While we keep getting minimum value
        	while(minimumIndex != -1){
        		// visited index
        		visited[minimumIndex] = true;
        		int node = minimumIndex;

        		// visited all edges and rest them
        		for(int i=0; i<neighbours[node].size(); i++){
        			int neighbour = neighbours[node][i];
        			if(distance[neighbour] > weights[node][neighbour] && !visited[neighbour]) {
        				distance[neighbour] = weights[node][neighbour];
        				parent[neighbour] = node;
        			}
        		}

        		// Get the next minimum index
        		minimumIndex = getMinimum();

        		// To get edge, we need this: weights[node][parent[node]]// this is the edge which is inside mst
        	}
        }

        void printDistance(){
        	cout << "Nodes in mst: " << endl;
        	for(int i=0; i<nodes; i++){
        		if(distance[i] == 0){
        			cout << "Root: " << i << endl;
        		} else {
        			cout << "Node: " << i << " | Parent: " << parent[i] << " | EdgeWeight: " << distance[i] << endl; 	
        		}        		
        	}
        	cout << endl;
        }
};

int main(){
    Graph graph(5);
    graph.addEdge(0,1,1);
    graph.addEdge(1,2,2);
    graph.addEdge(2,3,3);
    graph.addEdge(3,1,4);
    graph.addEdge(1,4,5);
    graph.addEdge(0,4,2);
    graph.printGraph();

    // Got our graph
    cout << endl;
    cout << "Creating disjoint set" << endl;
    DisjointSet disjointSet(6);
    for(int i=0; i<5; i++){
        cout << i << " -> " << disjointSet.Find(i) << endl;
    }
    cout << endl;
    disjointSet.Union(0,1);
    disjointSet.Union(1,2);
    disjointSet.Union(3,4);
    disjointSet.Union(4,5);
    for(int i=0; i<6; i++){
        cout << i << " -> " << disjointSet.Find(i) << endl;
    }
    cout << endl;
    disjointSet.Union(2,3);
    for(int i=0; i<6; i++){
        cout << i << " -> " << disjointSet.Find(i) << endl;
    }
    cout << endl;


    // graph
    vector< vector<int> > MST = graph.Kruskal();
    cout << "MST Obtained is: " << endl;
    for(int i=0; i<MST.size(); i++){
        cout << MST[i][1] << " -> " << MST[i][2] << "| " << MST[i][0] << endl;
    }
    cout << endl;


    graph.Prims();
    graph.printDistance();

    return 0;
}