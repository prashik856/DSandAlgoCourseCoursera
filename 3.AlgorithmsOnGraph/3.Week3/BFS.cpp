#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
	int vertices;
	vector< vector<int> > neighbours;
	vector<int> distance;
	vector<int> parent;
	queue<int> que;

	void resetGraph(){
		distance = vector<int>(vertices, -1);
		parent = vector<int>(vertices, -1);
	}

public:
	Graph(int verticesValue){
		vertices = verticesValue;
		neighbours = vector< vector<int> >(vertices, vector<int>());
		distance = vector<int>(vertices, -1);
		parent = vector<int>(vertices, -1);
	}

	void addEdge(int from, int to){
		neighbours[from].push_back(to);
	}

	void printGraph(){
		cout << "Graph Details: " << endl;
		cout << "Number of vertices: " << vertices << endl;
		for(int i=0; i<vertices; i++){
			cout << i << " -> ";
			for(int j=0; j<neighbours[i].size(); j++){
				cout << neighbours[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	void breadthFirstSearch(int vertex){
		resetGraph();
		// Start from vertex 
		cout << "Starting BFS" << endl;
		cout << "Root: " << vertex << endl;
		distance[vertex] = 0;
		parent[vertex] = vertex;
		que.push(vertex);
		while(!que.empty()){
			int currentVertex = que.front();
			for(int i=0; i<neighbours[currentVertex].size(); i++){
				int currentNeighbour = neighbours[currentVertex][i];
				// not visited
				if(distance[currentNeighbour] == -1){
					cout << "Visited: " << currentNeighbour << " ";
					que.push(currentNeighbour);
					distance[currentNeighbour] = distance[currentVertex] + 1;
					parent[currentNeighbour] = currentVertex;
				}
			}
			cout << endl;
			que.pop();
		}
	}

	void printShortestDistance(int vertex){
		breadthFirstSearch(vertex);
		cout << "Minimum distances from vertex " << vertex << " : " << endl;
		for(int i=0; i<vertices; i++){
			if(distance[i] == -1){
				cout << "Vertex: " << i << " | Distance: " << "Unreachable" << endl;	
			} else {
				cout << "Vertex: " << i << " | Distance: " << distance[i] << endl;	
			}
		}
		cout << endl;
	}

	void printShortestPath(int from, int to){
		// Run bfs
		breadthFirstSearch(from);
		if(parent[to] == -1){
			cout << "Vertex " << to << " is Unreachable from vertex " << from << endl;
		} else {
			int currentVertex = to;
			vector<int> path;
			while(currentVertex != from){
				path.push_back(currentVertex);
				currentVertex = parent[currentVertex];
			}
			cout << "Shortest Path is: " << endl;
			for(int i=path.size() - 1; i>=0; i--){
				cout << path[i] << " -> ";
			}
			cout << from;
			cout << endl;
		}
	}
};

int main(){
	Graph graph(4);
	graph.addEdge(0, 1);
	graph.addEdge(1, 2);
	graph.addEdge(2, 1);
	graph.addEdge(2, 3);
	graph.printGraph();
	graph.printShortestDistance(3);
	graph.printShortestPath(3,0);
	return 0;
}