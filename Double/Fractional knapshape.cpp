#include<bits/stdc++.h>
using namespace std;
int n,W;
struct Item{
	int wt,pf;
	double rt;
}arr[30];

void sortItem(){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j].rt<arr[j+1].rt){
				struct Item temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
void printAns(double x[]){
	double ans=0.0;
	for(int i=0;i<n;i++){
		cout<<x[i]<<" ";
		ans+=x[i]*arr[i].pf;
	}
	cout<<endl<<"The total profit is = "<<ans;
}

void knapshape(){
	sortItem();
	double x[n];
	for(int i=0;i<n;i++){
		x[i]=0.0;
	}
	int u=W;
	for(int i=0;i<n;i++){
		if(arr[i].wt>u){
			x[i]=u/(1.0* arr[i].wt);
			u=0;
		}else{
			x[i]=1.0;
			u-=arr[i].wt;
		}
	}
	printAns(x);
}




int main(){
	cout<<"Enter the number of items = ";
	cin>>n;
	cout<<endl<<"Enter the item's weight and profit "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i].wt;
		cin>>arr[i].pf;
		arr[i].rt=arr[i].pf/(1.0* arr[i].wt);
	}
	cout<<"Weight of the bag alowed = ";
	cin>>W;
	cout<<endl;
	knapshape();
	return 0;
}