#include<bits/stdc++.h>
using namespace std;
int V;
int graph[30][30];

class Stack{
	private:
		int arr[30];
		int top;
	public:
		Stack(){
			top=-1;
		}
		void Push(int val){
			arr[++top]=val;
		}
		void Pop(){
			top--;
		}
		bool isEmpty(){
			return top==-1;
		}
		int Top(){
			return arr[top];
		}
};
class Queue{
	private:
		int arr[30];
		int front,rear;
	public:
		Queue(){
			front=0;
			rear=-1;
		}
		void Push(int  val){
			arr[++rear]=val;
		}
		void Pop(){
			front++;
		}
		bool isEmpty(){
			return front>=rear+1 || rear==-1;		
		}
		int Front(){
			return arr[front];
		}
};
void DFS(){
	Stack st;
	int vis[V];
	for(int i=0;i<V;i++){
		vis[i]=0;
	}
	st.Push(0);
	vis[0]=1;
	while(!st.isEmpty()){
		int t=st.Top();
		st.Pop();
		cout<<t<<" ->";
		for(int i=0;i<V;i++){
			if(vis[i]==0 && graph[t][i]!=0){
				st.Push(i);
				vis[i]=1;
			}
		}
	}
}
void BFS(){
	Queue q;
	int vis[V];
	for(int i=0;i<V;i++){
		vis[i]=0;
	}
	q.Push(0);
	vis[0]=1;
	while(!q.isEmpty()){
		int t=q.Front();
		q.Pop();
		cout<<t<<" ->";
		for(int i=0;i<V;i++){
			if(vis[i]==0 && graph[i][t]!=0){
				q.Push(i);
				vis[i]=1;
			}
		}
	}
}

int main(){
	fstream file;
	file.open("RadheKrishna.txt");
	file>>V;
	int data;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			file>>graph[i][j];
		}
	}
	
	DFS();
	cout<<endl;
	BFS();	
	return 0;
}