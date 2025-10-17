#include<bits/stdc++.h>
using namespace std;

class DSU{
	vector<int>p;
	public:
		DSU(int n){
			p.resize(n+1,-1);
		}
		void simpleUnion(int i,int j){
			p[j]=i;
		}
		int find(int i){
			while(p[i]>0){
				i=p[i];
			}
		return i;
		}
		void printParent(){
			for(int i=1;i<p.size();i++){
				cout<<p[i]<<" ";
			}
			cout<<endl;
		}
};

int main(){
	cout<<"Enter the total no of edges and vertex =";
	int e,v;
	cin>>e>>v;
	DSU d(v);                                               
	cout<<endl<<"Enter the the adjacent nodes";
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		d.simpleUnion(u,v);
	}
	cout<<"Parent of these elements are"<<endl;
	for(int i=1;i<=v;i++){
		cout<<d.find(i)<<" ";
	}
	cout<<"The parent Array looks like "<<endl;
	d.printParent();
	
return 0;
}