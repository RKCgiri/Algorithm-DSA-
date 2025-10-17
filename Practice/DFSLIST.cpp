#include <bits/stdc++.h>
using namespace std;

int V;
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
Node* adj[10] = {NULL};

void createList(int i, int j) {
    Node* curr = new Node(j);
    if (adj[i] == NULL) {
        adj[i] = curr;
        return;
    }
    Node* temp = adj[i];
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = curr;
    return;    
}

void printList() {
    for (int i = 0; i < V; i++) {
        cout << char(i + 65) << ": ";
        Node* temp = adj[i];
        while (temp != NULL) {
            cout << char(temp->data + 65) << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

class Stack {
    private:
        int top;
        Node* arr[30];
    public:
        Stack() {
            top = -1;
        }
        void push(Node* x) {
            arr[++top] = x;
        }
        void pop() {
            if (!isEmpty()) {
                top--;
            }
        }
        Node* Top() {
            if (!isEmpty())
                return arr[top];
            return NULL;
        }
        bool isEmpty() {
            return top == -1;
        }
        int size() {
            if (!isEmpty())
                return top + 1;
            return 0;
        }
};

void DFS() {
    Stack s;
    vector<bool> vis(V, false);
    s.push(new Node(0));  
    vis[0] = true;
    while (!s.isEmpty()) {
        Node* x = s.Top();
        s.pop();
        cout << char(x->data + 65) << "->";
        Node* temp = adj[x->data];
        while (temp != NULL) {
            if (!vis[temp->data]) {
                vis[temp->data] = true;
                s.push(new Node(temp->data));
            }
            temp = temp->next;
        }
        delete x;  
    }
    cout << "END" << endl; 
}

int main() {
    fstream file;
    file.open("Graph.txt");
    if (!file) {
        cout << "Error to open the file" << endl;
        exit(1);
    }
    file >> V;
    int data; 
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            file >> data;
            if (data) createList(i, j);
        }
    }
    file.close();  
    printList();
    DFS();  
    return 0;
}
