#include<bits/stdc++.h>
using namespace std;
int V,n=0;
int graph[30][30];
struct edge{
	int u,v,wt;
};
struct edge  e[20]={0};
class DSU{
	private:
		int p[30];
	public:
		DSU(){
			for(int i=0;i<V;i++){
				p[i]=-1;
			}
		}
		void Union(int i,int j){
			int a=find(i);
			int b=find(j);
			int cnt=p[a]+p[b];
			if(a!=b){
				if(a>b){
					p[a]=b;
					p[b]=cnt;
				}else{
					p[b]=a;
					p[a]=cnt;
				}
			}
		}
		int find(int i){
			if(p[i]<0){
				return i; 
			}
			return p[i]=find(p[i]);
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
	int ans;
	for(int i=0;i<n;i++){
		if(d.find(e[i].u)!=d.find(e[i].v)){
			d.Union(e[i].u,e[i].v);
			ans+=e[i].wt;
			cout<<char(e[i].u+65)<<","<<char(e[i].v+65)<<"->";
		}
	}
	cout<<"Ans= "<<ans;
	
}

int main(){
	fstream file;
	file.open("RadheKrishna.txt");
	if(!file){
		cout<<"Error to open the file "<<endl;
		exit(0);
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
			if(i !=j && graph[i][j] !=100){
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

