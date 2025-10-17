#include<bits/stdc++.h>
using namespace std;
struct knap{
	int weight;
	int profit;
	double ratio;
};

int n;
struct knap arr[10]={0};
void shortItem(){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j].ratio<arr[j+1].ratio){
				struct knap temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

void printAns(double ans[]){
	cout<<"The result array is = ";
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	double res=0.0;
	for(int i=0;i<n;i++){
		res+=ans[i]*arr[i].profit;
	}
	cout<<"The maximum profit is = "<<res<<endl;
}
void knapShake(int W){
	shortItem();
	double ans[n];
	for(int i=0;i<n;i++){
		ans[i]=0.0;
	}
	int U=W;
	for(int i=0;i<n;i++){
		if(arr[i].weight>U){
			ans[i]=(1.0 * U)/(arr[i].weight);
			U=0;
		}else{
			ans[i]=1.0;
			U=U-arr[i].weight;
		}
	}
	printAns(ans);
}

int main(){
	cout<<"Enter the total items = ";
	cin>>n;
	cout<<endl;
	cout<<"Enter the number of items with its weight and prfit "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i].weight;
		cin>>arr[i].profit;
		arr[i].ratio=arr[i].profit/arr[i].weight;
	}
	cout<<"Enter the maximum weight allowed in the knapshake = ";
	int W;
	cin>>W;
	
	knapShake(W);
	
	
	return 0;
}