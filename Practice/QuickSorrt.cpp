#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int low,int high){
	int pivot=arr[high];
	int j=low-1;
	for(int i=low;i<high;i++){
		if(arr[i]<pivot){
			j++;
			swap(arr[j],arr[i]);
		}
	}
	j++;
	swap(arr[j],arr[high]);
	return j;
}
void quickSort(int arr[],int low,int high){
	if(low<high){
		int j=partition(arr,low,high);
		quickSort(arr,low,j-1);
		quickSort(arr,j+1,high);
	}
}

void marge(int arr[],int low,int mid,int high){
	int i=low,j=mid+1,k=low;
	int b[low+high+1];
	while(i<=mid && j<=high){
		if(arr[i]>arr[j]){
			b[k++]=arr[j++];
		}else{
			b[k++]=arr[i++];
		}
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

void adjHeap(int arr[],int i,int n){
	int j=2*i;
	int ele=arr[i];
	while(j<=n){
		if(j<n && arr[j]<arr[j+1]){
			j=j+1;
		}
		if(arr[j]<ele) break;
		arr[j/2]=arr[j];
		j=j*2;
	}
	arr[j/2]=ele;
}

void makeHeap(int arr[],int n){
	for(int i=n/2;i>=1;i--){
		adjHeap(arr,i,n);
	}
}
void heapSort(int arr[],int n){
	makeHeap(arr,n);
	for(int i=n;i>=1;i--){
		int temp=arr[1];
		arr[1]=arr[i];
		arr[i]=temp;
		adjHeap(arr,1,i-1);
	}
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int n;
	cout<<"Enter the size of the array = ";
	cin>>n;
	int *arr= new int[n];
	cout<<"Enter the array elements "<<endl;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	cout<<"Before sorting the array elements are "<<endl;
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<"  ";
	}
	cout<<endl;
	//quickSort(arr,0,n-1);
	//margeSort(arr,0,n-1);
	heapSort(arr,n);
	cout<<"After sorting then result array is "<<endl;
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
	
	
	return 0;
}