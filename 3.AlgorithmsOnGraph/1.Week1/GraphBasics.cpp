#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
	int vertices;
	vector< vector<int>> neighbours;
	vector<bool> visited;
public:
	// Constructor
	Graph(int verticesValue){
		vertices = verticesValue;
		neighbours = vector<vector<int>>(vertices);
		visited = vector<bool>(vertices, false);
		for(int i=0; i<vertices; i++){
			neighbours[i] = vector<int>();
		}
	}

	void addEdge(int from, int to){
		neighbours[to].push_back(from);
		neighbours[from].push_back(to);
	}

	void printGraph(){
		cout << "Graph: " << endl;
		for(int i=0; i<vertices; i++){
			cout << i << " -> ";
			for(int j=0; j<neighbours[i].size(); j++){
				cout << neighbours[i][j] << " ";
			}
			cout << endl;
		}
	}

	int getVertices() {
		return vertices;
	}

	void depthFirstSearch(){
		cout << "Normal Depth First Search" << endl;
		for(int i=0; i<vertices; i++){
			int currentVertex = i;
			if(!visited[currentVertex]){
				explore(currentVertex);
			}
		}
		resetVisited();
	}

	// Connected components
	int depthFirstSearchComponents(){
		cout << "Finding Connected Components" << endl;
		int connectedComponents = 0;
		for(int i=0; i<vertices; i++){
			int currentVertex = i;
			if(!visited[currentVertex]){
				explore(currentVertex, false);
				connectedComponents++;
			}
		}
		resetVisited();
		return connectedComponents;
	}

	void depthFirstSearchWithClock(){
		cout << "Depth First Search with Clock" << endl;
		int clock = 0;
		for(int i=0; i<vertices; i++){
			int currentVertex = i;
			if(!visited[currentVertex]){
				exploreWithClock(currentVertex, &clock);
			}
		}
		resetVisited();
	}

	void preVisit(int vertex, int *clock) {
		*clock = *clock + 1;
		cout << "Previsit vertex: " << vertex << " -> " << *clock << endl;
	}

	void postVisit(int vertex, int *clock) {
		*clock = *clock + 1;
		cout << "Postvisit vertex: " << vertex << " -> " << *clock << endl;	
	}

	void exploreWithClock(int vertex, int *clock){
		visited[vertex] = true;
		preVisit(vertex, clock);
		for(int i=0; i<neighbours[vertex].size(); i++){
			int neighbour = neighbours[vertex][i];
			if(!visited[neighbour]){
				exploreWithClock(neighbour, clock);
			}
		}
		postVisit(vertex, clock);
	}

	void explore(int vertex, int printInformation = true) {
		if(printInformation){
			cout << "Vertex Visited: " << vertex << endl;
			visited[vertex] = true;
			for(int i=0; i<neighbours[vertex].size(); i++){
				int neighbour = neighbours[vertex][i];
				if(!visited[neighbour]){
					if(printInformation){
						explore(neighbour);	
					} else {
						explore(neighbour, false);
					}
				}
			}
		} else {
			visited[vertex] = true;
			for(int i=0; i<neighbours[vertex].size(); i++){
				int neighbour = neighbours[vertex][i];
				if(!visited[neighbour]){
						explore(neighbour, false);
				}
			}
		}
	}

	void resetVisited(){
		visited = vector<bool>(vertices, false);
	}

};


int main(){
	// simple graph 0-1-2-3-4
	Graph graph(10);
	graph.addEdge(0,1);
	graph.addEdge(1,2);
	graph.addEdge(2,3);
	graph.addEdge(3,4);
	graph.printGraph();
	cout << endl;

	graph.explore(0);
	cout << endl;
	graph.resetVisited();

	graph.depthFirstSearch();
	cout << endl;

	int connectedComponents = graph.depthFirstSearchComponents();
	cout << "Number of Connected Components are: " << connectedComponents << endl;

	graph.depthFirstSearchWithClock();
	cout << endl;
}