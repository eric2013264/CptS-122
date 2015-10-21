#include <iostream>
 
#include <stack>
#include <string>
#include <stdlib.h>
#include <conio.h>

using namespace std;
 
#include <iostream>
 
typedef string valuetype;
 
class Node{
public:
	valuetype data;
	Node* left;
	Node* right;
	Node();
	Node(valuetype);
	friend void getStrings(NodePtr n, string arr[], int& ref);
};
 
class BST{
	Node* findNodebyvalue(valuetype);
	Node* findparentforNode(valuetype);
	Node* findrightnode(Node*);
	void inorder(Node*);
	void postorder(Node*);
	void preorder(Node*);
	friend void getString(BST& tree, string arr[]);
	public:
		Node* root;
		Node* current;
		BST();
		void insert(valuetype);
		void remove(valuetype);
		void traverse();
		valuetype retrieve();
		void custom_print();
	private:
		void getStringR(BSTNodePtr n, string arr[], 
		
};
 
//Node constructor1
Node::Node(){
	left=right=NULL;
}
//Node constructor2
Node::Node(valuetype val){
	data=val;
	left=right=NULL;
}
 
// BST constructor
BST::BST(){
	root=current=NULL;
}

// Insert a node with value val in tree
void BST::insert(valuetype val){
	if(root==NULL)
	{
		root = new Node(val);
	}
	else{
		Node* p =findNodebyvalue(val);
		if(p==0)
		{
			Node* parent=root;
			if (p != root)
			parent = findparentforNode(val);
			if(val>parent->data) parent->right=new Node(val);
			else parent->left=new Node(val);
       }
    }
}

BST&operator = (BST&rhs){
	copyNodes(rhs, root);
}

void copyBodes (BSTNodePtr n){
	if(n != NULL){
		insertNode(n->data);
		copyNode(n->nLeft);
		copyNode(n->nRight);
	}
}

//remove the node if value is val
void BST::remove(valuetype val){
	Node* p = findNodebyvalue(val);
	if(p!=0){
          //if both of child of node are null(leaf node)
		if(p->left==NULL&&p->right==NULL){
			if(p!=root){
				Node* parent= findparentforNode(val);
				if(val<parent->data)
				{
					parent->left=NULL;
				}
				else 
				{
					parent->right=NULL;
				}
			}
			else 
			{
				root = NULL;
			}
            delete (p);
	}
          //if only left child is not null  
          else if(p->left!=NULL&&p->right==NULL){
               if(p!=root)
			   {
					Node* parent=findparentforNode(val);
					if(val<parent->data) 
					{
						parent->left=p->left;
					}
					else
					{ 
						parent->right=p->left;
					}
                }
				else 
				{
					root=NULL;
				}
				delete (p);
          }
          //if only right child is not null                                      
		else if(p->left==NULL&&p->right!=NULL){
			if(p!=root){
				Node* parent=findparentforNode(val);
				if(val<parent->data){
					parent->left=p->right;
				}
				else {
					parent->right=p->right;
				}
			}
			else root=NULL;
			delete (p);
		}
          //if both child are not null
			else{
				Node* righty=findrightnode(p->left);
				Node* parent=findparentforNode(righty->data);
				p->data=righty->data;
				if(parent!=p){
				   parent->right=righty->left;
			   }
				else{
					p->left=righty->left;
			   }
           }
		}
}                                                  
//fins node with a value key
Node* BST::findNodebyvalue(valuetype key){
	Node* p =root;
	while((p!=NULL)&&(p->data!=key)){
		if(key<p->data)p=p->left;
		else p=p->right;
	}
	return p;
}
//find parent of a node with value key
Node* BST::findparentforNode(valuetype key){
	Node* p =root;
	Node* q=0;
	while((p!=NULL)&&(p->data!=key)){
		q=p;
		if(key<p->data)p=p->left;
		else p=p->right;
	}
   return q;
}
//finds the most right of a node p(means immediate succesor of p in inorder representation)
Node* BST::findrightnode(Node* p){
	Node* righty=p;
	while(righty->right!=NULL)
	righty=righty->right;
	return righty;
}

// preorder      
void BST::preorder(Node* p){
 if(p!=NULL){
		cout<<p->data<<" \n";
		preorder(p->left);
		preorder(p->right);
	}
}

// inorder
void BST::inorder(Node* p){
 if(p!=NULL){
		inorder(p->left);
		cout<<p->data<<" \n";
		inorder(p->right);
	}
}

// postorder
void BST::postorder(Node* p){
	if(p!=NULL){
		postorder(p->left);
		postorder(p->right);
		cout<<p->data<<" \n";
	}
}
 
void BST::traverse(){
	cout << "Preorder: \n";
	preorder(root);
	cout << endl << "Inorder: \n";
	inorder(root);
	cout << endl << "PostOrder: \n";
	postorder(root);
	cout<<endl;
}

void getStrings(BST& tree, string arr[]){
	int i = 0;
	getStrings(tree.root, arr, i);
}

 
int main(){
	Node n("Hello World", NULL, NULL);

	BST tree;
	tree.insert("Eric");
	tree.insert("Leonardo");
	tree.insert("Jennifer");
	tree.insert("Christopher");
	tree.insert("Molly");
	tree.insert("Steve");
	tree.insert("Andrew");
	tree.insert("Nick");
	tree.insert("Tara");
	tree.insert("Marshall");

	tree.traverse();

	getStrings(cpyTree, strArr);

	for(int i = 0; i < 13; i++){
		cout << strArr[i] + "\n";
	}
	_getch();
 
return 0;
}