#include <bits/stdc++.h>
using namespace std;

list <int> *adj; //adjacency list array pointer
int *edgeTo; //edgeTo array pointer
bool *marked; // pointer to marked array
int counter; // counter for the components
int *component; // pointer to array which stores the components

void addEdge(int u, int v); //function to add edge between two vertices
void dfs(int s, bool marked[]); // function for dfs
bool connected(int u, int v); // function to check if two vertices are connected

int main(){
	int V = 9;
	adj = new list <int> [V];
	edgeTo = new int [V];
	marked = new bool [V];
	component = new int [V];

	for(int i = 0; i < V; i++){
		edgeTo[i] = i; //all vertex have initially no path
		marked[i] = false; // no vertices have been visited
		component[i] = i; //initially assuming all components are disconnected
	}
	
	counter = 0;

	addEdge(0,1);
	addEdge(2,1);
	addEdge(2,4);
	addEdge(3,7);
	addEdge(3,5);

	for(int i = 0; i < V; i++){
		if(!marked[i]){
			dfs(i,marked);
			counter++;
		}
	}

	cout << connected(0,4);
	cout << connected(4,3);
	cout << connected(7,5);
	cout << connected(6,8);

	cout << "\n";
	for (int i = 0; i < V; ++i)
	{
		cout << i << " has component " << component[i] << "\n";
	}

}

void addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void dfs(int s, bool marked[]){
	marked[s] = true;
	component[s] = counter;
	list <int> :: iterator j;
	for(j = adj[s].begin();j != adj[s].end(); j++){
		if(!marked[*j]){
			dfs(*j,marked);
			edgeTo[*j] = s;
		}
	}
}

bool connected(int u, int v){
	return (component[u] == component[v]);
}