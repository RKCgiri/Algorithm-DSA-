#include<bits/stdc++.h>
using namespace std;

void adjHeap(int arr[],int i,int n){
	int key =arr[i];
	int j=i*2;
	while(j<=n){
		if(j<n && arr[j]<arr[j+1]){
			j=j+1;
		}
		if(key>=arr[j]) break;
		arr[j/2]=arr[j];
		j=j*2;
	}
	arr[j/2]=key;
}
void makeHeap(int arr[],int n){
	for(int i=n/2;i>=1;i--){
		adjHeap(arr,i,n);
	}
}

void HeapSort(int arr[],int n){
	makeHeap(arr,n);
	for(int i=n;i>=2;i--){
		int temp=arr[1];
		arr[1]=arr[i];
		arr[i]=temp;
		adjHeap(arr,1,i-1);
	}
}


int main(){
	int n;
	cout<<"Enter the number of elements of the array = ";
	cin>>n;
	int arr[n+1];
	cout<<endl<<"Enter the element of the array "<<endl;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}	
	HeapSort(arr,n);
	cout<<"After sorting the elements of the array are = "<<endl;
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}