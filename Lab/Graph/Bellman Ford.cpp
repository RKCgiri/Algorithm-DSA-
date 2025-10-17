#include<bits/stdc++.h>
using namespace std;
int V;
int graph[30][30];
int P[30],D[30];

void Paths(int source,int dest){
	if(source==dest){
		cout<<dest<<" ";
		return ;
	}
	cout<<source<<" -> ";
	Paths(P[source],dest);
	
}
bool BellmanFord(int dest){
	for(int i=0;i<V;i++){
		D[i]=INT_MAX;
	}
	P[dest]=-1;
	D[dest]=0;
	for(int v=0;v<V-1;v++){
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				if(D[i]+graph[i][j]<D[j]){
					D[j]=D[i]+graph[i][j];
					P[j]=i;
				}
			}
		}
	}
	
	
	cout<<"All the shortest paths are = "<<endl;
	for(int i=0;i<V;i++){
		if(i!=dest){
			Paths(i,dest);
		}
		cout<<endl;
	}
	
	// negative cycle checking 
	for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				if(D[i]+graph[i][j]<D[j]){
					return true;
				}
			}
		}
	return false;
	
}

int main(){
	fstream file;
	file.open("RadheKrishna.txt");
	file>>V;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			file>>graph[i][j];
		}
	}
	bool ans= BellmanFord(0);
	if(ans==true){
		cout<<"The graph has negative cycle"<<endl;
	}
	
	return 0;
}