#include<bits/stdc++.h>
using namespace std;

struct Node{
	Node* lchild;
	int data;
	Node* rchild;
	Node(int val){
		lchild = NULL;
		data = val;
		rchild = NULL;
	}
};

class Tree{
	Node* root;
	public:
		Tree(){
			root = NULL;
		}
		Node* getRoot(){
			return root;
		}
		void insert(int);
		void inorder(Node*);
		void del(int);
};

void Tree::insert(int val){
	Node* curr = new Node(val);
	// Tree has no Node 
	if(root == NULL){
		root=curr;
		return;
	}
	Node* temp = root, *parent=NULL;
	while(temp != NULL){
		parent = temp ;
		if(temp->data < val){
			temp= temp->rchild;
		}else if(temp->data > val){
			temp = temp->lchild;
		}else{
			cout<<"Same value node so can't add it "<<endl;
			return;
		}
	}
	if(parent->data > val){
		parent->lchild = curr;
	}else{
		parent->rchild = curr;
	}
}
void Tree::del(int val) {
    if (root == NULL) {
        cout << "There is no node present in the tree." << endl;
        return;
    }

    Node* temp = root, *parent = NULL;

    // Find the node to delete and its parent
    while (temp != NULL && temp->data != val) {
        parent = temp;
        if (temp->data > val) {
            temp = temp->lchild;
        } else {
            temp = temp->rchild;
        }
    }

    if (temp == NULL) {
        cout << "The node is not present in the BST." << endl;
        return;
    }

    // Case 1 and 2: Node with 0 or 1 child
    if (temp->lchild == NULL || temp->rchild == NULL) {
        Node* x = (temp->lchild != NULL) ? temp->lchild : temp->rchild;

        if (parent == NULL) {
            // Node to be deleted is root
            root = x;
        } else if (parent->lchild == temp) {
            parent->lchild = x;
        } else {
            parent->rchild = x;
        }

        delete temp;
        cout << "Node deleted successfully." << endl;
        return;
    }

    // Case 3: Node with two children
    // Find in-order successor and its parent
    Node* succ = temp->rchild, *psucc = temp;

    while (succ->lchild != NULL) {
        psucc = succ;
        succ = succ->lchild;
    }

    // Replace `temp`'s data with successor's data
    temp->data = succ->data;

    // Adjust successor's parent to bypass `succ`
    if (psucc->lchild == succ) {
        psucc->lchild = succ->rchild;
    } else {
        psucc->rchild = succ->rchild;
    }

    delete succ;
    cout << "Node deleted successfully." << endl;
}

void Tree::inorder(Node* r){
	if(r==NULL){
		return;
	}
	inorder(r->lchild);
	cout<<r->data<<" ";
	inorder(r->rchild);
}
int main(){
	Tree t;
	t.insert(100);
	t.insert(90);
	t.insert(120);
	t.insert(85);
	t.insert(115);
	t.insert(125);
	t.insert(75);
	t.insert(87);
	t.insert(70);
	t.insert(79);
	t.insert(110);
	t.insert(112);
	t.insert(113);
	t.insert(140);
	t.insert(170);
	t.inorder(t.getRoot());
	t.del(100);
	cout<<endl;
	t.inorder(t.getRoot());
	t.del(90);
	cout<<endl;
	t.inorder(t.getRoot());
}












