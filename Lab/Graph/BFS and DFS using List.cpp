#include<bits/stdc++.h>
using namespace std;
int V;
int graph[30][30];
struct Node{
	int data;
	Node* next;
	Node(int val){
		data=val;
		next=NULL;
	}
};
struct Node* arr[30]={0};
void makeList(int i,int j){
	Node* curr =new Node(j);
	if(arr[i]==NULL){
		arr[i]= curr;
		return;
	}
	Node* temp=arr[i];
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=curr;
}
void printList(){
	for(int i=0;i<V;i++){
		cout<<endl<<i<<"==";
		Node* temp=arr[i];
		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL"<<endl;
	}
}
class Stack{
	private:
		Node* arr[30];
		int top;
	public:
		Stack(){
			top=-1;
		}
		void Push(Node* val){
			arr[++top]=val;
		}
		void Pop(){
			top--;
		}
		bool isEmpty(){
			return top==-1;
		}
		Node* Top(){
			return arr[top];
		}
};
class Queue{
	private:
		Node* arr[30];
		int front,rear;
	public:
		Queue(){
			front=0;
			rear=-1;
		}
		void Push(Node* val){
			arr[++rear]=val;
		}
		void Pop(){
			front++;
		}
		bool isEmpty(){
			return front>=rear+1 || rear==-1;		
		}
		Node* Front(){
			return arr[front];
		}
};
void DFS(){
	Stack st;
	int vis[V];
	for(int i=0;i<V;i++){
		vis[i]=0;
	}
	st.Push(new Node(0));
	vis[0]=1;
	while(!st.isEmpty()){
		Node* t=st.Top();
		st.Pop();
		cout<<t->data<<" ->";
		Node* temp=arr[t->data];
		while(temp!=NULL){
			if(vis[temp->data]==0){
				st.Push(temp);
				vis[temp->data]=1;
			}
			temp=temp->next;
		}
	}
}
void BFS(){
	Queue q;
	int vis[V];
	for(int i=0;i<V;i++){
		vis[i]=0;
	}
	q.Push(new Node(0));
	vis[0]=1;
	while(!q.isEmpty()){
		Node* t=q.Front();
		q.Pop();
		cout<<t->data<<" ->";
		Node* temp=arr[t->data];
		while(temp!=NULL){
			if(vis[temp->data]==0){
				q.Push(temp);
				vis[temp->data]=1;
			}
			temp=temp->next;
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
			file>>data;
			if(data!=0){
				makeList(i,j);
			}
		}
	}
	printList();
	DFS();
	cout<<endl;
	BFS();	
	return 0;
}