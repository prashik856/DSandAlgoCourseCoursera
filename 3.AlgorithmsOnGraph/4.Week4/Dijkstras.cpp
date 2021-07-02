#include<bits/stdc++.h>
using namespace std;

class Graph{
	private:
		int nodes;
		vector< vector<int> > neighbours;
		vector<int> distance;
		vector<int> parent;
		vector<int> weight;
		vector<bool> visited;

		void resetGraph(){
			distance = vector<int>(nodes, -1);
			parent = vector<int>(nodes, -1);
			visited = vector<bool>(nodes, false);
		}

		int getMinimumValue(){
			int minValueIndex = -1;
			int minValue = 99999999;
			for(int i=0; i<distance.size(); i++){
				if(distance[i] != -1 && distance[i] < minValue && !visited[i]){
					minValueIndex = i;
				}
			}
			return minValueIndex;
		}
	public:
		Graph(int nodesValue){
			nodes = nodesValue;
			neighbours = vector< vector<int> >(nodes, vector<int>());
			distance = vector<int>(nodes, 99999999);
			parent = vector<int>(nodes, -1);
			weight = vector<int>(nodes*nodes, -1);
			visited = vector<bool>(nodes, false);
		}

		void addEdge(int from, int to, int weightValue){
			neighbours[from].push_back(to);
			weight[nodes*from + to] = weightValue;
		}

		void printGraph(){
			cout << "Graph representation: " << endl;
			for(int i=0; i<nodes; i++){
				for(int j=0; j<neighbours[i].size(); j++){
					cout << "("<< i << ", " << neighbours[i][j] << " )" << "->" << weight[nodes*i + neighbours[i][j]] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}

		void dijkstras(int node){
			// make distance root as 0
			int minValueIndex = 0;
			int minValue = 0;
			distance[node] = 0;
			for(int i=0; i<nodes; i++){
				minValueIndex = getMinimumValue();
				if(minValueIndex == -1){
					break;
				}
				visited[minValueIndex] = true;
				minValue = distance[minValueIndex];
				for(int j=0; j<neighbours[minValueIndex].size(); j++){
					int currentNeighbour = neighbours[minValueIndex][j];
					if(distance[currentNeighbour] > 
						minValue + 
						weight[nodes * minValueIndex + currentNeighbour]){
						distance[currentNeighbour] = minValue + weight[nodes * minValueIndex + currentNeighbour];
					}
				}

			}

		}

		void printDistance(){
			for(int i=0; i<distance.size(); i++){
				cout << distance[i] << " ";
			}
			cout << endl;
		}
};

int main(){
	Graph graph(4);
	graph.addEdge(0,1,5);
	graph.addEdge(1,2,10);
	graph.addEdge(2,1,7);
	graph.addEdge(2,3,15);
	graph.printGraph();
	graph.dijkstras(3);
	graph.printDistance();
	return 0;
}