#include <bits/stdc++.h>
using namespace std;
int graph[100][100];
int V;
int P[10][10];
 
void APSP(int P[][10],int i,int j){
	if(i==j){
		cout<<i<<"-> ";
		return;
	}
	else if(P[i][j]==-1){
		cout<<"There is no path"<<endl;
		return;
	}else{
		APSP(P,i,P[j][i]);
		cout<<j<<"-> ";
	}
}

void printGraph(){
	cout<<"The graph is="<<endl;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
}

void shortest_distance() {

		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (i == j) graph[i][j] = 0;
			}
		}

		for (int k = 0; k < V; k++){
			for (int i = 0; i < V; i++) {
				for (int j = 0; j < V; j++) {
					graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
					P[i][j]=P[k][j];
				}
			}
		}
	
	cout<<"The answer Graph is "<<endl;
	printGraph();
	cout<<"The Shortest distance are "<<endl;
	for(int i=0;i<V-1;i++){
		APSP(P,0,i+1);
		cout<<endl;
	}

		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (graph[i][j] == 100) {
					graph[i][j] = -1;
				}
			}
		}
}



int main() {
	fstream file;
	file.open("Graph.txt");
	if(!file){
		cout<<"Error to open the file"<<endl;
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
	shortest_distance();
	file.close();
	return 0;
}
