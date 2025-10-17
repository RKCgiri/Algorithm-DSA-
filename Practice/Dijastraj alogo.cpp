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

void path(int P[],int s,int d){
	if(s==d){
		cout<<d<<" ";
		return;
	}
	path(P,s,P[d]);
	cout<<d<<" ";
}


int minInd(int key[],bool mst[]){
	int min=INT_MAX,ind=-1;
	for(int i=0;i<V;i++){
		if(mst[i]==false && key[i]<min){
			ind=i;
			min=key[i];
		}
	}
	return ind;
}

void Distraj(){
	int P[V];
	bool mst[V];
	int key[V];
	for(int i=0;i<V;i++){
		P[i]=-1;
		mst[i]=false;
		key[i]=100;
	}
	key[0]=0;
	P[0]=-1;
	
	for(int i=0;i<V;i++){
		int u=minInd(key,mst);
		mst[u]=true;
		for(int j=0;j<V;j++){
			if(mst[j]==false && key[u]+graph[u][j]<key[j]){
				P[j]=u;
				key[j]=key[u]+graph[u][j];
			}
		}	
	}
	cout<<"Printing all paths = "<<endl;
	for(int i=0;i<V;i++){
		cout<<endl<<"The path weight is "<<key[i]<<"===>>>";
		path(P,0,i);
	}
	
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
	Distraj();
	file.close();
	return 0;
}


