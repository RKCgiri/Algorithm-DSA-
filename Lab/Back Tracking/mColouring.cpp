#include<bits/stdc++.h>
using namespace std;
int G[4][4]={{0,1,0,1},
		     {1,0,1,0},
			 {0,1,0,1},
			 {1,0,1,0}};



void nextValue(int k,int x[],int m){
	while(true){
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0) return ;
		int j=0;
		for(j=0;j<=k-1;j++){
			if(G[k][j]==1 && x[j]==x[k]){
				break;
			}
		}
		if(j==k) return ;
	}
}
 void printAns(int x[]){
 	cout<<endl<<"The colours are used to colour the vertices are "<<endl;
 	for(int i=0;i<4;i++){
 		cout<<x[i]<<" ";
	 }
 }
void mColuring(int k,int x[],int m){
	while(true){
		nextValue(k,x,m);
		if(x[k]==0) return ;
		if(k==3){
			printAns(x);
			return ;
		}else{
			mColuring(k+1,x,m);
		}
	}
}

int main(){
	int colurs;
	cout<<"Enter the total colours allowed=";
	cin>>colurs;
	
	int *x=new int[4];
	for(int i=0;i<4;i++){
		x[i]=0;
	}
	cout<<"The graph coloring is "<<endl;
	mColuring(0,x,colurs);
	cout<<"SiyaRam"<<endl;
	return 0;
}