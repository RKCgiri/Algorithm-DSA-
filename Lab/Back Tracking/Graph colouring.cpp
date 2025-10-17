#include<bits/stdc++.h>
using namespace std;
int V;
int graph[30][30];
int m=2;
int x[30]={0};
void nextVal(int k){
	while(true){
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0) return ;
		int i=0;
		for(;i<=k-1;i++){
			if(graph[i][k]==1 && x[i]==x[k])
				break;
		}
		if(i==k) return;
	}
}

void mColour(int k){
	while(true){
		nextVal(k);
		if(x[k]==0){
			return ;
		}
		if(k==V-1){
			cout<<endl<<"The colour array is = ";
			for(int i=0;i<V;i++)
				cout<<x[i]<<" ";
			return ;
		}else{
			mColour(k+1);
		}
	}
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
		
	mColour(0);
	return 0;
}