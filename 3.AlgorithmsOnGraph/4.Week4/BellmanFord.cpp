#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
	int nodes;
	vector< vector<int> > neighbours;
	vector<int> distance;
	vector<int> parent;
	vector<int> weight;

	void resetGraph(){
		distance = vector<int> (nodes, 99999999);
		parent = vector<int> (nodes, -1);
	}

public:
	Graph(int nodesValue){
		nodes = nodesValue;
		neighbours = vector< vector<int> >(nodes, vector<int>());
		distance = vector<int> (nodes, 99999999);
		parent = vector<int> (nodes, -1);
		weight = vector<int> (nodes*nodes, 99999999);
	}

	void addEdge(int from, int to, int weightValue){
		neighbours[from].push_back(to);
		weight[nodes*from + to] = weightValue;
	}

	void printGraph(){
		cout << "Graph is: " << endl;
		for(int i=0; i<nodes; i++){
			cout << i << " -> ";
			for(int j=0; j<neighbours[i].size(); j++){
				cout << neighbours[i][j] << "|" << weight[i*nodes + neighbours[i][j]] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	void bellmanford(int node){
		// Update distance
		distance[node] = 0;
		// update parent
		parent[node] = node;
		// Run v-1 times
		for(int i=1; i<nodes; i++){
			// For all edges
			bool distanceArrayChanged = false;
			for(int j=0; j<nodes; j++){
				for(int k=0; k<neighbours[j].size(); k++){
					int node = j;
					int edge = neighbours[j][k];
					int distanceNode = distance[node];
					int distanceEdge = distance[edge];
					int weightValue = weight[node * nodes + edge];
					// Rest for edge
					if(distanceEdge > distanceNode + weightValue) {
						distance[edge] = distanceNode + weightValue;
						parent[edge] = node;
						distanceArrayChanged = true;
					} 
				}
			}
			if(!distanceArrayChanged){
				//cout << "Distance Array unchanged. Breaking." << endl;
				break;
			}
		}
	}

	vector<int> detectNegativeCycle(){
		vector<int> negativeCycle;
		// Fun bellmanford for one more cycle
		bool distanceChanged = false;
		int nodeReachable = -1;
		for(int j=0; j<nodes; j++){
			for(int k=0; k<neighbours[j].size(); k++){
				int node = j;
				int edge = neighbours[j][k];
				int distanceNode = distance[node];
				int distanceEdge = distance[edge];
				int weightValue = weight[node * nodes + edge];
				// Rest for edge
				if(distanceEdge > distanceNode + weightValue) {
					distance[edge] = distanceNode + weightValue;
					// edge is changed.
					// This edge is reachabled from negative cycle.
					// cout << "Distance array changed" << endl;
					distanceChanged = true;
					// negative cycle exists;
					nodeReachable = edge;
					parent[edge] = node;
				} 
			}
		}

		// If negative cycle exists
		if(distanceChanged){
			int temp = nodeReachable;
			for(int i=0; i<nodes; i++){
				temp = parent[temp];
			}
			// cout << "Node inside negative cycle: " << temp << endl;

			// Now, we have a temp value which is inside the negative cycle
			// Now store the cycle
			negativeCycle.push_back(temp);
			int parentTemp = parent[temp];
			while(parentTemp != temp){
				negativeCycle.push_back(parentTemp);
				parentTemp = parent[parentTemp];
			}
			// We got our negative cycle
		}
		
		return negativeCycle;
	}

	vector<int> getInfiniteArbitrageNodes(){
		vector<bool> visited(nodes, false);
		bool distanceChanged = false;
		queue<int> q;
		vector<int> infiniteArbitrageNodes;
		for(int j=0; j<nodes; j++){
			for(int k=0; k<neighbours[j].size(); k++){
				int node = j;
				int edge = neighbours[j][k];
				int distanceNode = distance[node];
				int distanceEdge = distance[edge];
				int weightValue = weight[node * nodes + edge];
				// Rest for edge
				if(distanceEdge > distanceNode + weightValue) {
					distance[edge] = distanceNode + weightValue;
					// edge is changed.
					distanceChanged = true;
					// Push all the edges whose values were changed
					q.push(edge);
				} 
			}
		}

		if(!distanceChanged){
			return infiniteArbitrageNodes;
		} else {
			// distance changed
			// Do bfs with q
			while(!q.empty()){
				int node = q.front();
				if(!visited[node]){
					visited[node] = true;
					// cout << "Node visited: " << node << endl;
					infiniteArbitrageNodes.push_back(node);
					for(int i=0; i<neighbours[node].size(); i++){
						int neighbour = neighbours[node][i];
						if(!visited[neighbour]){
							q.push(neighbour);
						}
					}
				}
				q.pop();
			}
		}
	}

	void printDistances(){
		cout << "Distance Array is: " << endl; 
		for(int i=0; i<nodes; i++){
			cout << distance[i] << " ";
		}
		cout << endl;
	}

	void printParents(){
		cout << "Parent Array is: " << endl;
		for(int i=0; i<nodes; i++){
			cout << parent[i] << " ";
		}
		cout << endl;
	}

	void printNegativeCycle(vector<int> array){
		if(array.size() > 0){
			cout << "Negative cycle exists in the graph: " << endl;
			for(int i=0; i<array.size(); i++){
				cout << array[i] << " -> ";
			}
			cout << array[0] << endl;
		} else {
			cout << "Negative cycle does not exists in the graph" << endl;
			return;
		}
	}

	void printInfiniteArbitrageNodes(vector<int> array) {
		if(array.size() > 0){
			cout << "These are the nodes where infinite arbitrage is possible: " << endl;
			for(int i=0; i<array.size(); i++){
				cout << array[i] << " ";
			}
			cout << endl;
		} else {
			cout << "There are no nodes with infinite arbitrage" << endl;
		}
	}
};

int main(){
	Graph graph(6);
	graph.addEdge(0, 1, 1);
	graph.addEdge(1, 2, -2);
	graph.addEdge(2, 3, -3);
	graph.addEdge(3, 4, -4);
	graph.addEdge(4, 1, -5);
	graph.addEdge(3, 5, 6);
	graph.printGraph();
	graph.bellmanford(0);
	graph.printDistances();
	graph.printParents();
	vector<int> negativeCycle = graph.detectNegativeCycle();
	graph.printNegativeCycle(negativeCycle);
	vector<int> infiniteArbitrageNodes = graph.getInfiniteArbitrageNodes();
	graph.printInfiniteArbitrageNodes(infiniteArbitrageNodes);
	return 0;
}