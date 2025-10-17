#include<bits/stdc++.h>
using namespace std;
int n;
int x[10]={0};
bool canPlace(int k,int i){
	for(int j=1;j<=k-1;j++){
		if(x[j]==i || abs(j-k)==abs(x[j]-i)){
			return false;
		}
	}
	return true;
}
void nQueen(int k,int n){
	for(int i=1;i<=n;i++){
		if(canPlace(k,i)){
			x[k]=i;
			if(k==n){
				cout<<"Ans =";
				for(int i=1;i<=n;i++)
					cout<<x[i]<<" ";
				cout<<endl;				
			}
			else nQueen(k+1,n);
		}
	}
}


int main(){
	cout<<"Enter the number  of queen to be palced = ";
	cin>>n;
	nQueen(1,n);
}