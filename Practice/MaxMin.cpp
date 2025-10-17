#include<bits/stdc++.h>
using namespace std;
void maxmin(int arr[],int i,int j,int& max,int& min){
	if(i==j){
		max=arr[i];
		min=arr[i];
	}
	else if(i==j-1){
		if(arr[i]>arr[j]){
			max=arr[i];
			min=arr[j];
		}else{
			max=arr[j];
			max=arr[i];
		}
	}else{
		int mid=(i+j)/2;
		maxmin(arr,i,mid,max,min);
		int max1=max;
		int min1=min;
		maxmin(arr,mid+1,j,max,min);
		max= max>max1 ? max:max1;
		min= min<min1 ? min:min1;
	}
}


int main(){
	int n;
	cout<<"Enter the array size=";
	cin>>n;
	cout<<endl;
	int arr[n];
	cout<<"Enter the array elements "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int max,min;
	maxmin(arr,0,n-1,max,min);
	
	cout<<"Maximum value is "<<max<<endl;
	cout<<"Minimum  Value is "<<min;
	
	
	return 0;
}