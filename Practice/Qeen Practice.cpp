#include<bits/stdc++.h>
using namespace std;
bool canPlace(int k,int i,int x[]){
	for(int j=1;j<=k-1;j++){
		if(x[j]==i || abs(j-k)==abs(x[j]-i)){
			return false;
		}
	}
	return true;
}



void nQueen(int k,int n,int x[]){
	for(int i=1;i<=n;i++){
		if(canPlace(k,i,x)){
			x[k]=i;
			if(k==n){
				cout<<"The one combination is = ";
				for(int i=1;i<=n;i++){
					cout<<x[i]<<" ";
				}
				cout<<endl;
			}else
				nQueen(k+1,n,x);
		}
	}
}


int main(){
	int n;
	cout<<"Enter the total numbe rof queens to place in n* n matrix = ";
	cin>>n;
	int x[n+1]={0};
	nQueen(1,n,x);
	
	return 0;
}