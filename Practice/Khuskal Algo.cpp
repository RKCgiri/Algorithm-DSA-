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
			while(p[i]>=0){
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

class Solution{
	public:
	 int spanningTree(int v, vector<vector<int>>& edges) {
        vector<pair<int,pair<int,int>>> adj;
        string s="";
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj.push_back({wt, {u, v}});
        } 
        DSU ds(v);
        sort(adj.begin(), adj.end());
        int mstwt = 0;
        for (auto it : adj) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (ds.find(u) != ds.find(v)) {
            	cout<<u<<" "<<v<<endl;
                mstwt += wt;
                ds.simpleUnion(u, v);
                s+=u+'a';
                s+=v+'a';
                cout<<s<<endl;
                s="";
            }
        }
        cout<<"Joy Siya Ram"<<endl;
        return mstwt;
    }
};

int main(){
	int e,v;
	cout<<"enter the vertice =";
	cin>>v;
	cout<<"Enter the edges =";
	cin>>e;
	vector<vector<int>>edges(e);
	cout<<"Enter the edges and wt"<<endl;
	for(int i=0;i<e;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		edges[i]={u,v,wt};
	}
	Solution obj;
	cout<<"The weigth of the minimuum spanning tree is "<<obj.spanningTree(v,edges)<<endl;
	return 0;
}