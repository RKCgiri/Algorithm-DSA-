#include<bits/stdc++.h>
using namespace std;
int P[10]={0};
int N;
int M[10][10],S[10][10];
void printAns(int i,int j){
	if(i==j){
		 cout<<"A"<<i;
		 return ;
	}
	cout<<"(";
	printAns(i,S[i][j]);
	printAns(S[i][j]+1,j);
	cout<<")";
}
void matrixMul(){
	int n=N;
	for(int i=1;i<=n;i++){
		M[i][i]=0;
	}
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1;
			M[i][j]=INT_MAX;
			for(int k=i;k<=j-1;k++){
				int cost=M[i][k]+M[k+1][j]+P[i-1]*P[k]*P[j];
				if(cost<M[i][j]){
					M[i][j]=cost;
					S[i][j]=k;
				}
			}
		}
	}
	cout<<"Ans = "<<M[1][n]<<endl;
	printAns(1,n);
}


int main(){
	cout<<"Enter the number of matrix to multiply = ";
	cin>>N;
	cout<<endl<<"Enter the dimention of the matrix "<<endl;
	for(int i=0;i<=N;i++){
		cin>>P[i];
	}
	matrixMul();
	
	return 0;
}