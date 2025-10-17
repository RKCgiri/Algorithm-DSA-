#include<bits/stdc++.h>
using namespace std;
void marge(int arr[],int low,int mid,int high){
	int i=low,j=mid+1,k=low;
	int b[100];
	while(i<=mid && j<=high){
		if(arr[i]<arr[j]){
			b[k++]=arr[i++];
		}else b[k++]=arr[j++];
	}
	while(i<=mid) b[k++]=arr[i++];
	while(j<=high) b[k++]=arr[j++];
	for(int i=low;i<=high;i++){
		arr[i]=b[i];
	}
}
void margeSort(int arr[],int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		margeSort(arr,low,mid);
		margeSort(arr,mid+1,high);
		marge(arr,low,mid,high);
	}
}


int main(){
	int n;
	cout<<"Enter the array size = ";
	cin>>n;
	int arr[n];
	cout<<endl<<"Enter array elemets = "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	margeSort(arr,0,n-1);
	cout<<"After sorting the result is = "<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
	
	return 0;
}