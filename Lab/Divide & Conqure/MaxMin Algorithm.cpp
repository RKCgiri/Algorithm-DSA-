#include<bits/stdc++.h>
using namespace std;

void MaxMin(int arr[],int i,int j,int& max,int& min){
	if(i==j){
		max=arr[i];
		min=arr[i];
		return ;
	}
	if(i==j-1){
		if(arr[i]>arr[j]){
			max=arr[i];
			min=arr[j];
		}else{
			max=arr[j];
			min=arr[i];
		}
	}else{
		int mid=(i+j)/2;
		MaxMin(arr,i,mid,max,min);
		int max1=max;
		int min1=min;
		MaxMin(arr,mid+1,j,max,min);
		max= max>max1? max:max1;
		min=min<min1? min:min1;
	}
}



int main(){
	int n;
	cout<<"Enter the number of elements = ";
	cin>>n;
	cout<<endl<<"Enter the elements of the array "<<endl;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int max=INT_MIN,min=INT_MAX;
	MaxMin(arr,0,n,max,min);
	cout<<"The maximum is = "<<max<<" The minimum is = "<<min;
	return 0;
}