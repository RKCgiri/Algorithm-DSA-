#include<bits/stdc++.h>
using namespace std;
int V;
int graph[30][30];
class Queue{
	private:
		int front,rear;
		int arr[30];
	public:
		Queue(){
			front=rear=-1;
		}
		void push(int x){
			if(front==-1){
				front=rear=1;
				arr[rear]=x;
			}else arr[++rear]=x;
		}
		void pop(){
			if(!isEmpty()){
				front++;
//				if(front==rear+1){
//					front=rear=-1;
//				}
			}
		}
		int Front(){
			if(!isEmpty())
				return arr[front];
			return -1;
		}
		bool isEmpty(){
			return front==-1 || front==rear+1;
		}
		int size(){
			if(!isEmpty())
				return rear-front+1;
			return 0;
		}
};

void BFS(){
	Queue q;
	int vis[V]={0};
	q.push(0);
	vis[0]=1;
	while(!q.isEmpty()){
		int x=q.Front();
		cout<<char(x+65)<<"->";
		q.pop();
		for(int i=0;i<V;i++){
			if(graph[x][i]==1 && !vis[i]){
				q.push(i);
				vis[i]=1;
			}
		}
	}
	
}



int main(){
	fstream file;
	file.open("Graph.txt");
	if(!file){
		cout<<"Error to oprn the file"<<endl;
		exit(1);
	}
	file>>V;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			file>>graph[i][j];
		}
	}
	BFS();
	return 0;
}