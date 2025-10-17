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
void printMST(int P[],int key[]){
	cout<<"The mst tree is = "<<endl;
	for(int i=1;i<V;i++){
		cout<<"<"<<char(65+P[i])<<","<<char(65+i)<<">"<<" = "<<key[i]<<endl;
	}
	cout<<"==================="<<endl;
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

void Prims(){
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
			if(mst[j]==false && graph[u][j]<key[j]){
				P[j]=u;
				key[j]=graph[u][j];
			}
		}	
	}
	printMST(P,key);
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
	Prims();
	file.close();
	return 0;
}


