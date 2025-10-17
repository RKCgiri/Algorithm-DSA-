#include<bits/stdc++.h>
using  namespace std;
int V;
int graph[30][30];


class Queue{
	private:
		int front,rear;
		int arr[30];
	public:
		Queue(){
			front=0;
			rear=-1;
		}
		void Push(int val){
			arr[++rear]=val;
		}
		int Front(){
			return arr[front];
		}
		void Pop(){
			front++;
		}
		bool isEmpty(){
			return rear==-1 || front==rear+1;
		}
};


void BFS(int start){
	Queue st;
	int vis[V]={0};
	st.Push(start);
	vis[start]=1;
	while(!st.isEmpty()){
		int v=st.Front();
		st.Pop();
		cout<<char(v+65)<<"-> ";
		for(int i=0;i<V;i++){
			if(graph[i][v]==1 && vis[i]==0){
				st.Push(i);
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
	BFS(0);
	return 0;
}
