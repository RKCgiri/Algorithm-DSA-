#include<bits/stdc++.h>
using namespace std;
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
		void push(int x){
			arr[++top]=x;
		}
		void pop(){
			if(!isEmpty()){
				top--;
			}
		}
		int Top(){
			if(!isEmpty())
				return arr[top];
			return -1;
		}
		bool isEmpty(){
			return top==-1;
		}
		int size(){
			if(!isEmpty())
				return top+1;
			return 0;
		}
};

void DFS(){
	Stack s;
	int vis[V]={0};
	s.push(0);
	vis[0]=1;
	while(!s.isEmpty()){
		int x=s.Top();
		cout<<char(x+65)<<"->";
		s.pop();
		for(int i=0;i<V;i++){
			if(graph[x][i]==1 && !vis[i]){
				s.push(i);
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
	DFS();
	return 0;
}