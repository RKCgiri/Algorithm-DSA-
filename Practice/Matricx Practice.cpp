#include<bits/stdc++.h>
using namespace std;
int n;
int s[10][10];
void print(int i,int j){
	if(i==j){
		cout<<"A"<<i<<" ";
		return;
	}
	cout<<"("<<" ";
	print(i,s[i][j]);
	print(s[i][j]+1,j);
	cout<<")"<<" ";
}



int matrix(int p[]){
	int m[n+1][n+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==j) m[i][j]=0;
		}
	}
	
	for(int len=2;len<n;len++){
		for(int i=1;i<n-len+1;i++){
			int j=i+len-1;
			m[i][j]=INT_MAX;
			for(int k=i;k<=j-1;k++){
				if(m[i][j]>m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]){
					m[i][j]=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
					s[i][j]=k;
				}
			}
		}
	}
	print(1,4);
	cout<<endl;
	return m[1][n-1];
	
	
}



int main(){
	cout<<"Enter the numer of matrix prsent in mmultiplication  = ";
	cin>>n;
	int p[n];
	cout<<"Enter the order of the matrix's in the array "<<endl;
	for(int i=0;i<n;i++){
		cin>>p[i];	
	}
	
	cout<<"The maximum cost of sclar multiplications are required are = "<<matrix(p)<<endl;
	
	
	return 0;
}