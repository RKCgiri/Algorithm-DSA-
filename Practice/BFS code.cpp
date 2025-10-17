#include<bits/stdc++.h>
using  namespace std;
int V;
int graph[30][30];

class Stack{
	private:
		int top;
		int arr[30];
	public:
		Stack(){
			top=-1;
		}
		void push(int val){
			arr[++top]=val;
		}
		int Top(){
			return top>=0 ? arr[top]:-1;
		}
		bool isEmpty(){
			return top==-1;
		}
		void Pop(){
			 top--;
		}
};


void DFS(int start){
	Stack st;
	int vis[V]={0};
	st.push(start);
	vis[start]=1;
	while(!st.isEmpty()){
		int v=st.Top();
		st.Pop();
		cout<<char(v+65)<<"-> ";
		for(int i=0;i<V;i++){
			if(graph[i][v]==1 && vis[i]==0){
				st.push(i);
				vis[i]=1;
			}
		}
	}
}
int main(){
	fstream file;
	file.open("Graph.txt");
	file>>V;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			file>>graph[i][j];	
		}
	}
	DFS(0);
	return 0;
}

