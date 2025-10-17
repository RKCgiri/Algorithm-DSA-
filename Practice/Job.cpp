#include<bits/stdc++.h>
using namespace std;

struct Job{
	char id;
	int profit;
	int dead;
};
int n;
struct Job arr[10]={0};
void sortItem(){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j].profit<arr[j+1].profit){
				struct Job temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
void printAns(struct Job ans[]){
	cout<<"Selected Jobs are "<<endl;
	cout<<"Job "<<"			"<<"proffit"<<"			"<<"deadline"<<"			"<<endl; 
	for(int i=0;i<n;i++){
		cout<<ans[i].id<<"			"<<ans[i].profit<<"			"<<ans[i].dead<<endl;
	}
	int res=0;
	for(int i=0;i<n;i++){
		res+=ans[i].profit;
	}
	cout<<"Total Profit is = "<<res<<endl;
}
void JSD(){
	sortItem();
	struct Job ans[n]={0};
	int slot[n]={0};
	for(int i=0;i<n;i++){
		for(int j=min(arr[i].dead,n)-1;j>=0;j--){
			if(slot[j]==0){
				slot[j]=1;
				ans[j].profit=arr[i].profit;
				ans[j].id=arr[i].id;
				ans[j].dead=arr[i].dead;
				break;
			}
		}
	}
	
	printAns(ans);
	
	
}



int main(){
	cout<<"Enter the Numbers of Job=";
	cin>>n;
	cout<<endl<<"Enter the job with its id,profit ans dateline"<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i].id;
		cin>>arr[i].profit;
		cin>>arr[i].dead;
	}
	
	JSD();
	return 0;
}