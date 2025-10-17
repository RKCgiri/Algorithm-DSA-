#include<bits/stdc++.h>
using namespace std;
int graph[30][30];
int V;
bool mst[20];
int key[20],P[20];
void Paths(int s,int d){
	if(s==d){
		cout<<s<<"->";
		return;
	} 	
	cout<<s<<"->";
	Paths(P[s],d);
	
 }
 int minInd(){
 	int m=INT_MAX,ind=-1;
 	for(int i=0;i<V;i++){
 		if(mst[i]==false && key[i]<m){
 			m=key[i];
 			ind=i;
		 }
	 }
	 return ind;
 }
void Dijkstras(int dest){
	for(int i=0;i<V;i++){
		key[i]=INT_MAX;
		mst[i]=false;
	}
	P[dest]=-1;
	key[dest]=0;
	int ans=0;
	for(int i=0;i<V;i++){
		int u=minInd();
		ans+=key[u];
		mst[u]=true;
		for(int v=0;v<V;v++){
			if(mst[v]==false && graph[u][v]+key[u]<key[v]){
				key[v]=graph[u][v]+key[u];
				P[v]=u;
			}
		}
	}
	cout<<"Ans="<<ans<<endl;
	for(int i=0;i<V;i++){
		Paths(i,dest);
		cout<<endl;
	}
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
	Dijkstras(0);
	
	return 0;
}