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

class Queue {
    private:
        int front, rear;
        Node* arr[30];
    public:
        Queue() {
            front =0;
		    rear = -1;
        }
        void push(Node* x) {
            arr[++rear] = x;
        }
        void pop() {
           front++;
        }
        Node* Front() {
            return arr[front];
        }
        bool isEmpty() {
            return rear==-1 || front>=rear+1;
        }
};

void BFS() {
    Queue q;
    vector<bool> vis(V, false);
    q.push(new Node(0));  // Start with the first node
    vis[0] = true;
    while (!q.isEmpty()) {
        Node* x = q.Front();
        cout << char(x->data + 65) << "->";
        q.pop();
        Node* temp = adj[x->data];
        while (temp != NULL) {
            if (!vis[temp->data]) {
                vis[temp->data] = true;
                q.push(new Node(temp->data));
            }
            temp = temp->next;
        }
        delete x;  // Free the memory allocated for the node
    }
    cout << "END" << endl;  // To mark the end of traversal
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
    file.close();  // Close the file after reading
    printList();
    BFS();  // Call the BFS function to perform the traversal
    return 0;
}
