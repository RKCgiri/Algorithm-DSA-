#include<bits/stdc++.h>
using namespace std;
int V;
int graph[30][30];
int P[30][30];

void Paths(int i,int j){
	if(i==j){
		cout<<i<<" ->";
		return;
	}else if(P[i][j]==-1){
		cout<<"No paths exits "<<endl;
		return ;
	}
	else{
		Paths(i,P[i][j]);
		cout<<j<<"->";
	}
}

void Floyed(){
	cout<<"Joy Siya Ram Joy Sri Radhe Krishna";
	int d[V][V];
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			if(i==j){
				d[i][j]=0;
				P[i][j]=i;
			}else {
				d[i][j]=graph[i][j];
				P[i][j]=i;	
			}
		}
	}
	
	for(int k=0;k<V;k++){
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				if(d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k]+d[k][j];
					P[i][j]=P[k][j];
				}
			}
		}
	}
	
	
	cout<<"The result graph is = "<<endl;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			cout<<d[i][j]<<"  ";
		}
		cout<<endl;
	}
	
	
	cout<<"All paths from source to distance "<<endl;
	for(int i=0;i<V;i++){
		Paths(0,i);
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
	Floyed();	
	
	return 0;
}