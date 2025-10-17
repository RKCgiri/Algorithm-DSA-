#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int vis[],stack<int>& st,vector<int>adj[]){
	vis[node]=1;
	for(auto it:adj[node]){
		if(!vis[it]){
			dfs(it,vis,st,adj);
		}
	}
	st.push(node);
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
	}
	int vis[V]={0};
	stack<int>st;
	for(int i=0;i<V;i++){
		if(!vis[i]){
			dfs(i,vis,st,adj);
		}
	}
	vector<int>ans;
	while(!st.empty()){
		ans.push_back(st.top());
		st.pop();
	}
	cout<<"The answer is = "<<endl;
	for(int i=0;i<V;i++){
		cout<<char(ans[i]+65)<<" ";
	}
	
	return 0;
}