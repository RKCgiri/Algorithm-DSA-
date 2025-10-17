#include<bits/stdc++.h>
using namespace std;
int graph[100][100];
int V;

void printGraph(){
	cout<<"The Graph is "<<endl;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
}

int minKey(int key[],int mstSet[]){
	int min=INT_MAX,minInd=-1;
	for(int v=0;v<V;v++){
		if(mstSet[v]==0 && key[v]<min){
			min=key[v];
			minInd=v;
		}
	}
	return minInd;
}
void printMST(int parent[],int key[]){
	cout<<"The MST tree is "<<endl;
	for(int i=1;i<V;i++){
		cout<<parent[i]<<"->"<<i<<"==>>weight= "<<key[i]<<",    ";
	}
	cout<<endl;
}

void P(int parent[],int source,int dest){
	if(source==dest){
		cout<<source;
		return;
	}
	cout<<dest<<"<-- ";
	dest=parent[dest];
	P(parent,source,dest);
}
int Prims(int source){
 int parent[V];
    int key[V];
    int mstSet[V];

    for(int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int c = 0; c < V-1; c++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;
        for(int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && graph[u][v] != INT_MAX && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    
    printMST(parent, key);
    cout<<"Printing all the paths "<<endl;
    for(int i=0;i<V;i++){
    	cout<<"cost="<<key[i];
    	cout<<"path=>";
    	P(parent,source,i);
    	cout<<endl;
	}
	return 0;
}



int main(){
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
	Prims(0);
	file.close();
	return 0;
}