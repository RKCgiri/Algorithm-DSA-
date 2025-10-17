#include<bits/stdc++.h>
using namespace std;

class DSU{
	vector<int>p;
	public:
		DSU(int n){
			p.resize(n+1,-1);
		}
		void WeightedUnion(int i,int j){
			int pi = Collapsefind(i);
			int pj = Collapsefind(j);
			int cnt=p[pi]+p[pj];
			if(pi != pj){
				if(p[pi] < p[pj]){
					p[pi] =cnt;
					p[pj] = i;
				} else {
					p[pj] =cnt;
					p[pi] = j;
				}
			}
		}
		int Collapsefind(int i){
			int r=i;
			while(p[r]>0){
				r=p[r];
			}
			while(i!=r){
				int s=p[i];
				p[i]=r;
				i=s;
			}
			return r; // Return the root of the set
		}
};
int main(){
	cout<<"Enter the total no of edges and vertex =";
	int v;
	cin>>v;
	DSU d(v);                                               
	d.WeightedUnion(1,2);
	d.WeightedUnion(3,4);
	d.WeightedUnion(5,6);
	d.WeightedUnion(7,8);
	d.WeightedUnion(4,2);
	d.WeightedUnion(4,6);
	cout<<d.Collapsefind(1)<<endl;
	cout<<d.Collapsefind(2)<<endl;
	cout<<d.Collapsefind(3)<<endl;
	cout<<d.Collapsefind(4)<<endl;
	cout<<d.Collapsefind(5)<<endl;
	cout<<d.Collapsefind(8)<<endl;
	cout<<d.Collapsefind(7)<<endl;
	return 0;
}
