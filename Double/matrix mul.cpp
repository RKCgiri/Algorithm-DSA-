#include<bits/stdc++.h>
using namespace std;
int p[20],S[10][10];
int N;
void printAns(int i,int j){
	if(i==j){
		cout<<"A"<<i;
		return;
	}
	cout<<"(";
	printAns(i,S[i][j]);
	printAns(S[i][j]+1,j);
	cout<<")";
}
void matrixMul(){
	int n=N;
	int mat[n+1][n+1];
	for(int i=1;i<=n;i++){
		mat[i][i]=0;
	}
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1;
			mat[i][j]=INT_MAX;
			for(int k=i;k<=j-1;k++){
				int cost=mat[i][k]+mat[k+1][j]+p[i-1]*p[k]*p[j];
				if(cost<mat[i][j]){
					mat[i][j]=cost;
					S[i][j]=k;
				}
			}
		}
	}
	cout<<mat[1][n];
	printAns(1,n);
}


int main(){
	cout<<"Enter the the number of matix ";
	cin>>N;
	cout<<endl<<"Enter the P array  = ";
	for(int i=0;i<=N;i++){
		cin>>p[i];
	}
	matrixMul();
}