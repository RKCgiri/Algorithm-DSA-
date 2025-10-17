#include<bits/stdc++.h>
using namespace std;
int V,k=0;
int graph[100][100];
struct edge{
	int u,v;
	int wt;	
};
struct edge e[10]={0};
void printGraph(){
	cout<<"The graph is "<<endl;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"=========================="<<endl;
}
void printAdj(){
	cout<<"u"<<"   "<<"v"<<"    "<<"wt"<<endl;
	for(int i=0;i<k;i++){
		cout<<e[i].u<<"  "<<e[i].v<<"  "<<e[i].wt<<endl;
	}
	cout<<"================================="<<endl;
}

class DSU{
	private:
		int parent[100];
	public:
		DSU(){
			for(int i=0;i<V;i++){
				parent[i]=-1;
			}	
		}
		void SimpleUnion(int i,int j){
			parent[j]=i;
		}
		int find(int i){
			int r=i;
			while(parent[r]>=0){
				r=parent[r];
			}
			while(i!=r){
				int n=parent[i];
				parent[i]=r;
				i=n;
				
			}
			return r;
		}
		
};
void bubbleSort(){
	for(int i=0;i<k-1;i++){
		for(int j=0;j<k-i-1;j++){
			if(e[j].wt>e[j+1].wt){
				struct edge temp=e[j];
				e[j]=e[j+1];
				e[j+1]=temp;
			}
		}
	}
	printAdj();
}
void Khuskal(){
	bubbleSort();
	DSU ds;
	
	for(int i=0;i<k;i++){
		if(ds.find(e[i].u)!=ds.find(e[i].v)){
			cout<<char(e[i].u+65)<<" "<<char(e[i].v+65)<<" ->";
			ds.SimpleUnion(e[i].u,e[i].v);
		}
	}
	
}


int main(){
	fstream file;
	file.open("Graph.txt");
	if(!file){
		cout<<"Error in open the file"<<endl;
		exit(1);
	}
	file>>V;
	cout<<V;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			file>>graph[i][j];
		}
	}
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			if(graph[i][j]!=100){
				e[k].u=i;
				e[k].v=j;
				e[k++].wt=graph[i][j];
				graph[j][i]=100;
			}
		}
	}
	printGraph();
	printAdj();
	 Khuskal();
	return 0;
}