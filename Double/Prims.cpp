#include<bits/stdc++.h>
using namespace std;
int V;
int graph[30][30];
int mst[30];
int key[30];
int P[30];
void printAns(){
	for(int i=0;i<V;i++){
		cout<<P[i]<<","<<i <<"wt = "<<key[i]<<"->";
	}
}
int minInd(){
	int ind=-1;
	int min=INT_MAX;
	for(int i=0;i<V;i++){
		if(mst[i]!=1 && key[i]<min){
			min=key[i];
			ind=i;
		}
	}
	return ind;
}
void Prims(){
	for(int i=0;i<V;i++){
		mst[i]=-1;
		key[i]=INT_MAX;
	}
	P[0]=-1;
	key[0]=0;
	for(int i=0;i<V-1;i++){
		int u=minInd();
		mst[u]=1;
		for(int v=0;v<V;v++){
			if(graph[u][v]+key[u]<key[v]){
				key[v]=graph[u][v]+key[u];
				P[v]=u;
			}
		}
	}
	
	cout<<"The minimum Spanning Tree is  "<<endl;
	printAns();
			
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
	Prims();	
	
	return 0;
}