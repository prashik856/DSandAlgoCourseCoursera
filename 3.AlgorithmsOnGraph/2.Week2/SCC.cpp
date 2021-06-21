#include<bits/stdc++.h>
using namespace std;

class DirectedGraph{
private:
	int vertices;
	vector<vector<int>> neighbours;
	vector<vector<int>> preValue;
	vector<vector<int>> postValue;
	vector<bool> visited;
	vector<vector<int>> reverseNeighbours;

	void explore(int vertex, int* clock, bool reverse = false){
		if(!reverse){
			visited[vertex] = true;
			*clock = *clock + 1;
			preValue[vertex] = *clock;
			for(int i=0; i<neighbours[vertex].size(); i++){
				if(!visited[neighbours[vertex][i]]){
					explore(neighbours[vertex][i], clock);
				}
			}
			*clock = *clock + 1;
			postValue[vertex] = *clock;
		} else {
			visited[vertex] = true;
			*clock = *clock + 1;
			preValue[vertex] = *clock;
			for(int i=0; i<reverseNeighbours[vertex].size(); i++){
				if(!visited[reverseNeighbours[vertex][i]]){
					explore(reverseNeighbours[vertex][i], clock, true);
				}
			}
			*clock = *clock + 1;
			postValue[vertex] = *clock;
		}
		
		return;
	}

	void resetGraph(){
		preValue = vector<int>(vertices, 0);
		postValue = vector<int>(vertices, 0);
		visited = vector<bool>(vertices, false);
		return;
	}

public:
	DirectedGraph(int verticesValue){
		vertices = verticesValue;
		neighbours = vector<vector<int>>(vertices);
		reverseNeighbours = vector<vector<int>>(vertices);
		for(int i=0; i<neighbours.size(); i++){
			neighbours[i] = vector<int>();
			reverseNeighbours[i] = vector<int>();
		}
		preValue = vector<int>(vertices, 0);
		postValue = vector<int>(vertices, 0);
		visited = vector<bool>(vertices, false);
	}

	void addEdge(int from, int to){
		neighbours[from].push_back(to);
		reverseNeighbours[to].push_back(from);
		return;
	}

	void printDirectedGraph(){
		cout << "Graph: " << endl;
		for(int i=0; i<vertices; i++){
			cout <<  i << " -> ";
			for(int j=0; j<neighbours[i].size(); j++){
				cout << neighbours[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return;
	}

	void depthFirstSearch(){
		cout << "Running on Graph" << endl;
		resetGraph();
		int clock = 0;
		for(int i=0; i<vertices; i++){
			if(!visited[i]){
				explore(i, &clock);
			}
		}
		return;
	}

	void depthFirstSearchOnReverse(){
		cout << "Running on Reverse Graph" << endl;
		resetGraph();
		int clock = 0;
		for(int i=0; i<vertices; i++){
			if(!visited[i]){
				explore(i, &clock, true);
			}
		}
		return;
	}

	vector<vector<int>> getSCC(){
		// get max value of post

	}

	void printPreValues(){
		cout << "Pre Values" << endl;
		for(int i=0; i<vertices; i++){
			cout << "Vertex: " << i << " -> " << preValue[i] << endl;
		}
		cout << endl;
		return;
	}

	void printPostValues(){
		cout << "Post values" << endl;
		for(int i=0; i<vertices; i++){
			cout << "Vertex: " << i << " -> " << postValue[i] << endl;
		}
		cout << endl;
		return;
	}


	vector<vector<int>> getGraph(){
		return neighbours;
	}

	vector<vector<int>> getReverseGraph(){
		return reverseNeighbours;
	}

};

int main(){
	// 0-1, 1-0, 0-2, 0-3, 0-4, 2-3, 3-4, 1-2, 3-2, 3-4, 4-0
	DirectedGraph directedGraph(4);
	directedGraph.addEdge(0, 1);
	directedGraph.addEdge(1, 2);
	directedGraph.addEdge(2, 1);
	directedGraph.addEdge(2, 3);
	directedGraph.printDirectedGraph();
	directedGraph.depthFirstSearchOnReverse();
	directedGraph.printPreValues();
	directedGraph.printPostValues();

	return 0;
}