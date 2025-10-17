#include<bits/stdc++.h>
using namespace std;
int V,n=0;
int graph[30][30];
struct edge{
	int u,v,wt;	
} e[30];
class DSU{
	private:
		int p[30];
	public:
		DSU(){
			for(int i=0;i<V;i++){
				p[i]=-1;
			}
		}
		void sUnion(int i,int j){
	    	 int a = find(i);
           	int b = find(j);
        	if (a != b) {
          	  int cnt = p[a] + p[b];
           	   if (p[a] < p[b]) {
             	   p[a] = cnt;
             	   p[b] = a;
          	  } else {
                p[b] = cnt;
                p[a] = b;
           	 }
       	 }
		}
		int find(int i){
			int r=i;
			while(p[r]>=0){
				r=p[r];
			}
			while(i!=r){
				int n=p[i];
				p[i]=r;
				i=n;
				
			}
			return r;
		}
		
};
void sortEdge(){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(e[j].wt>e[j+1].wt){
				struct edge temp=e[j];
				e[j]=e[j+1];
				e[j+1]=temp;
			}
		}
	}
}
void khuskal(){
	sortEdge();
	DSU d;
	for(int i=0;i<n;i++){
		if(d.find(e[i].u)!=d.find(e[i].v)){
			cout<<char(e[i].u+65)<<" "<<char(e[i].v+65)<<"->";
			d.sUnion(e[i].u,e[i].v);
		}
	}
	
}

int main(){
	fstream file;
	file.open("Graph.txt");
	if(!file){
		cout<<"Error to open the file "<<endl;
		exit(0);
	} 
	file>>V;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			file>>graph[i][j];
		}
	}
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			if(i !=j && graph[i][j] !=-1){
				e[n].u=i;
				e[n].v=j;
				e[n++].wt=graph[i][j];
				graph[j][i]=-1;
			}
		}
	}
	khuskal();
	return 0;
}