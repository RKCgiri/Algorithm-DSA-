#include<bits/stdc++.h>
using namespace std;
int n;
struct Item{
	char id;
	int pf,d;
}arr[30];
void sortItem(){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j].pf<arr[j+1].pf){
				struct Item temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
void JSD(){
	sortItem();
	int x[n],slot[n];
	for(int i=0;i<n;i++){
		x[i]=0;
		slot[i]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=min(arr[i].d,n)-1;i>=0;j--){
			if(slot[j]==0){
				slot[j]=1;
				x[j]=arr[i].pf;
				break;
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=x[i];
	}
	cout<<"The total profit is = "<<ans;
}


int main(){
	cout<<"Enter the number of Jobs = ";
	cin>>n;
	cout<<endl<<"Enter the Job id , pf , dadeline "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i].id>>arr[i].pf>>arr[i].d;
	}
	JSD();
	return 0;
}