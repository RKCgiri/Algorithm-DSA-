#include<bits/stdc++.h>
using namespace std;


void topologicalSort(int indeg[],vector<int>adj[],int V,int E){
	queue<int>q;
	for(int i=0;i<V;i++){
		if(indeg[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		cout<<char(u+65)<<" ";
		for(auto it:adj[u]){
			indeg[it]--;
			if(indeg[it]==0){
				q.push(it);
			}
		}
	}
}



int main(){
	int V,E;
	cout<<"Enter the number of vertices = ";
	cin>>V;
	cout<<endl<<"Enter the number of Edges = ";
	cin>>E;
	cout<<endl<<"Enter the adjacent nodes "<<endl;
	vector<int>adj[V];
	int indeg[V]={0};
	for(int i=0;i<E;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		indeg[v]++;
	}
	topologicalSort(indeg,adj,V,E);
	
	return 0;
}