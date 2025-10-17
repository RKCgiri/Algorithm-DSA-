#include <bits/stdc++.h>
using namespace std;
int V;
int graph[100][100];


void printGraph(){
	cout<<"The graph is="<<endl;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
}
void printSol(int dest[]){
	cout<<"The vertex and distance from source "<<endl;
	for(int i=0;i<V;i++){
		cout<<i<<" cost = "<<dest[i]<<endl;
	}
}
void path(int parent[],int source,int dest){
	if(source==dest){
		cout<<source<<" ";
		return;
	}
	cout<<dest<<" ->";
	dest=parent[dest];
	path(parent,source,dest);
}

bool bellman(int source){
	int dist[V];
	int parent[V];
	for(int i=0;i<V;i++){
		dist[i]=INT_MAX;
		parent[i]=-1;
	}
	dist[source]=0;
	for(int i=0;i<V-1;i++){
		for(int j=0;j<V;j++){
			for(int k=0;k<V;k++){
				if(dist[j]!=INT_MAX && dist[j]+graph[j][k]<dist[k]){
					dist[k]=dist[j]+graph[j][k];
					parent[k]=j;
				}
			}
		}
	}
	
	//check for negative cycle
		for(int j=0;j<V;j++){
			for(int k=0;k<V;k++){
				if(dist[j]!=INT_MAX && dist[j]+graph[j][k]<dist[k]){
					return false;
				}
			}
		}
		
		
		cout<<"All paths from any vertex to source vertex ="<<endl;
		for(int i=0;i<V;i++){
			cout<<"Total distance = "<<dist[i]<<"==>>   ";
			path(parent,source,i);
			cout<<endl;
		}
		printSol(dist);
		
	return true;	
		
		
}



int main() {
	fstream file;
	file.open("Graph.txt");
	if(!file){
		cout<<"Error to open the file "<<endl;
		exit(1);
	}
	file>>V;
	cout<<V;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			file>>graph[i][j];
		}
	}
	printGraph();
	bellman(0);
	return 0;
}
