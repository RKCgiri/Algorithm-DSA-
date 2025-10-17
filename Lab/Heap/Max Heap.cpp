  #include<bits/stdc++.h>
using namespace std;
class MaxHeap{
	int heapcapacity=0,curr=0;
	public:
		MaxHeap(int size){
			heapcapacity=size;
		}
		void AdjustHeap(int arr[],int i,int n){
			int j=i*2;
			int key=arr[i];
			while(j<=n){
				if(j<n && arr[j+1]>arr[j]){
					j=j+1;
				}
				if(arr[j]<=key)
					break;
				arr[j/2]=arr[j];
				j=j*2;
			}
			arr[j/2]=key;
		}
		void MakeHeap(int arr[],int n){
			curr=n;
			for(int i=floor(n/2);i>=1;i--){
				AdjustHeap(arr,i,n);
			}
		}
		int parent(int i){
			return i/2;
		}
		void InsertKey(int arr[],int key){
			if(heapcapacity==curr){
				cout<<"Overflow";
			}
			curr=curr+1;
			arr[curr]=key;
			int i=curr;
			while(i>1 && arr[i]>arr[parent(i)]){
				swap(arr[i],arr[parent(i)]);
				i=parent(i);
			}
		}
		void DeleteKey(int arr[],int i){
			if(i<1 && i>curr){
				cout<<"Such no index is exits "<<endl;
				return ;
			}
		IncreaseKey(arr,i,INT_MAX);
		ExtractMax(arr);
		}
		void IncreaseKey(int arr[],int i,int newVal){
			if(i<1 && i>curr){
				cout<<"Such index is not exits "<<endl;
				return ;
			}
			arr[i]=newVal;
			while(i>1 && arr[i]>arr[parent(i)]){
				swap(arr[i],arr[parent(i)]);
				i=parent(i);
			}
		}
		int getMax(int arr[]){
			if(curr<=0){
				return INT_MIN;
			}
			return arr[1];
		}
		int ExtractMax(int arr[]){
			if(curr==1){
				curr=curr-1;
				return arr[1];
			}
			int max=arr[1];
			arr[1]=arr[curr];
			curr=curr-1;
			AdjustHeap(arr,1,curr);
			return max;
		}
};

int main(){
	int currsize;
	cout<<"Enter the array size =";
	cin>>currsize;
	int arr[currsize];
	cout<<endl<<"Enter the array elements "<<endl;
	for(int i=1;i<=currsize;i++){
		cin>>arr[i];
	}
	MaxHeap pq(10);
	pq.MakeHeap(arr,currsize);
	cout<<"heap elemets are "<<endl;
	for(int i=1;i<=currsize;i++){
		cout<<arr[i]<<" ";
	}	
	pq.InsertKey(arr,20);
	pq.InsertKey(arr,10);
	pq.InsertKey(arr,0);
	
	cout<<"Updated heap elemets are "<<endl;
	for(int i=1;i<=currsize+3;i++){
		cout<<arr[i]<<" ";
	}	
	pq.DeleteKey(arr,3);
	cout<<"Updated heap elemets are "<<endl;
	for(int i=1;i<=currsize+2;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl<<"Minimum element = "<<pq.getMax(arr);
	cout<<endl<<"Minimum element = "<<pq.ExtractMax(arr);
	cout<<"Updated heap elemets are "<<endl;
	for(int i=1;i<=currsize+1;i++){
		cout<<arr[i]<<" ";
	}
	pq.IncreaseKey(arr,3,100);
	cout<<"Updated heap elemets are "<<endl;
	for(int i=1;i<=currsize+1;i++){
		cout<<arr[i]<<" ";
	}

return 0;
}