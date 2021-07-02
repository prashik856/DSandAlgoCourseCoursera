#include<bits/stdc++.h>
using namespace std;

class DirectedGraph{
private:
	int vertices;
	vector< vector<int> > neighbours;
	vector< vector<int> > reverseNeighbours;
	vector<bool> visited;
	stack<int> postStack;
	stack<int> preStack;
	vector< vector<int> > SCC;

	void resetVisted(){
		visited = vector<bool>(vertices, false);
		return;
	}

	void resetGraph(){
		visited = vector<bool>(vertices, false);
		postStack = stack<int>();
		preStack = stack<int>();
		return;
	}

public:
	DirectedGraph(int verticesValue){
		vertices = verticesValue;
		neighbours = vector< vector<int> >(vertices);
		reverseNeighbours = vector< vector<int> >(vertices);
		for(int i=0; i<neighbours.size(); i++){
			neighbours[i] = vector<int>();
			reverseNeighbours[i] = vector<int>();
		}
		preStack = stack<int>();
		postStack = stack<int>();
		visited = vector<bool>(vertices, false);
	}

	void addEdge(int from, int to){
		neighbours[from].push_back(to);
		reverseNeighbours[to].push_back(from);
		return;
	}

	void explore(int vertex, bool noStack=false){
		
		if(!noStack){
			// visited current vertex
			visited[vertex] = true;

			// put it in pre Stack
			preStack.push(vertex);

			// Go to neighbours
			for(int i=0; i<neighbours[vertex].size(); i++){
				if(!visited[ neighbours[vertex][i] ]){
					explore(neighbours[vertex][i]);
				}
			}

			// put it in post Stack
			postStack.push(vertex);

			return;
		} else {
			// visit current vertex
			visited[vertex] = true;

			// Put it inside SCC
			SCC[SCC.size() - 1].push_back(vertex);

			// Explore neighbours
			for(int i=0; i<reverseNeighbours[vertex].size(); i++){
				if(!visited[ reverseNeighbours[vertex][i] ]){
					explore(reverseNeighbours[vertex][i], true);
				}
			}

		}
		
	}

	void depthFirstSearch() {
		for(int i=0; i<vertices; i++){
			if(!visited[i]){
				// This is not visited
				explore(i);
			}
		}
	}

	vector< vector<int> > getSCC(){
		// reset visited
		resetVisted();

		while(!postStack.empty()){
			// all of the explored vertices will come into SCC
			if(!visited[postStack.top()]){
				// cout << "Vertex: " << postStack.top() << endl;
				SCC.push_back(vector<int>());
				explore(postStack.top(), true);
			}
			postStack.pop();
		}
		return SCC;
	}

	void printAllSCC(){
		cout << "Number of SCCs: " << SCC.size() << endl;
		for(int i=0; i<SCC.size(); i++){
			cout << "SCC " << i + 1 << " : " ;
			for(int j=0; j<SCC[i].size(); j++){
				cout << SCC[i][j] << " ";
			}
			cout << endl;
		}
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

	void printPreStack(){
		cout << "Pre Stack Values: " << endl;
		vector<int> temp;
		while(!preStack.empty()){
			temp.push_back(preStack.top());
			cout << preStack.top() << endl;
			preStack.pop();
		}
		// push it back in preStack
		for(int i=temp.size()-1; i>=0; i--){
			preStack.push(temp[i]);
		}
		cout << endl;
		return;
	}

	void printPostStack(){
		cout << "Post values" << endl;
		vector<int> temp;
		while(!postStack.empty()){
			temp.push_back(postStack.top());
			cout << postStack.top() << endl;
			postStack.pop();
		}

		// push it tack in postStack
		for(int i=temp.size()-1; i>=0; i--){
			postStack.push(temp[i]);
		}
		cout << endl;
		return;
	}

	vector< vector<int> > getGraph(){
		return neighbours;
	}

	vector< vector<int> > getReverseGraph(){
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
	directedGraph.depthFirstSearch();
	directedGraph.printPreStack();
	directedGraph.printPostStack();
	directedGraph.getSCC();
	directedGraph.printAllSCC();

	return 0;
}