#include<bits/stdc++.h>
using namespace std;
int V;
int graph[30][30];
int P[30],key[30];
bool mst[30];
void printAns(int start){
	for(int i=0;i<V;i++){
		if(i!=start){
			cout<<"  < "<<char(P[i]+65)<<","<<char(i+65)<<" wt = "<<key[i]<<" >  ";
		}
	}
}
void Paths(int source,int dest){
	if(source==dest){
		cout<<dest<<" ";
		return ;
	}
	cout<<source<<" -> ";
	Paths(P[source],dest);
	
}
int minKey(){
	int minInd=-1,min=INT_MAX;
	for(int i=0;i<V;i++){
		if(mst[i]==false && key[i]<min){
			min=key[i];
			minInd=i;
		}
	}
	return minInd;
}
void Dijkstras(int dest){
	for(int i=0;i<V;i++){
		key[i]=INT_MAX;
		mst[i]=false;
	}
	P[dest]=-1;
	key[dest]=0;
	int ans=0;
	for(int i=0;i<V-1;i++){
		int u=minKey();
		ans+=key[u];
		mst[u]=true;
		for(int v=0;v<V;v++){
			if(graph[u][v]!=100 && mst[v]==false && graph[u][v]<key[v]){
				key[v]=graph[u][v];
				P[v]=u;
			}
		}
	}
	cout<<"The weight of mst is = "<<ans<<endl;
	cout<<"All the shortest paths are = "<<endl;
	for(int i=0;i<V;i++){
		if(i!=dest){
			Paths(i,dest);
		}
		cout<<endl;
	}
	printAns(dest);
}




int main(){
	fstream file;
	file.open("SiyaRam.txt");
	file>>V;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			file>>graph[i][j];
		}
	}
	Dijkstras(0);
	
	return 0;
}