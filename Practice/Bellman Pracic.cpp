#include<bits/stdc++.h>
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

void path(int P[],int s,int d){
	if(s==d){
//		cout<<s<<" ->";
		return;
	}
	path(P,s,P[d]);
	cout<<d<<" ->";
}


bool bellman(int source){
	int P[V];
	int dist[V];
	for(int i=0;i<V;i++){
		dist[i]=INT_MAX;
		P[i]=-1;
	}	
	dist[source]=0;
	// Loop for V-1 times 
	for(int i=0;i<V-1;i++){
		for(int j=0;j<V;j++){
			for(int k=0;k<V;k++){
				if(dist[j]!=INT_MAX && dist[j]+graph[j][k]<dist[k]){
					dist[k]=dist[j]+graph[j][k];
					P[k]=j;
				}
			}
		}
	}
	
	//Printing all the answers 
	
	cout<<"The single source shortest path  is "<<endl;
	for(int i=0;i<V;i++){
		cout<<"cost of the path is "<<dist[i]<<"===>>";
		path(P,source,i);
		cout<<endl;
	}
	
	//checking for negative edge cycles 
	
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			if(dist[i]!=100 && dist[i]+graph[i][j]<dist[j]){
				return true;
			}
		}
	}
	return false;
	
	
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
	cout<<"The Graph has negative chycle "<<bellman(0);
	return 0;
}