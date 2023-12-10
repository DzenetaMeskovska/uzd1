#include<iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};
//-----------------------------
Node *CreateNode(){
	Node *newNode;
	newNode=new Node;
	cout<<"\nInput node's integer number: ";
	cin>>newNode->data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}
//-----------------------------
void PrintTree(Node *cur){
	//inorder
	if(!cur) return;
	PrintTree(cur->left);  //Left
	cout<<cur->data<<" ";  //Vertex
	PrintTree(cur->right); //Right
}
//-----------------------------
void PreOrder(Node *cur){
    if(cur!=NULL){
		cout<<cur->data<<" ";
        PreOrder(cur->left);
		PreOrder(cur->right);
    }
}
//-----------------------------
void PostOrder(Node *cur){
	if(cur!=NULL){
		PostOrder(cur->left);
       	PostOrder(cur->right);
		cout<<cur->data<<" ";
 	}
}
//-----------------------------
void AddNode(Node *root){
	//1.create node
	Node *newNode, *cur;
	newNode=CreateNode();
	//2.add node in tree
	cur=root;
	//big loop
	while((newNode->data<cur->data && cur->left!=NULL) || (newNode->data>=cur->data && cur->right!=NULL)){
		//to the left
		while(newNode->data<cur->data && cur->left!=NULL){ cur=cur->left; }
		//to the right
		while(newNode->data>=cur->data && cur->right!=NULL){ cur=cur->right; }
	}
	//add node
	if(newNode->data<cur->data && cur->left==NULL) cur->left=newNode;
	else if(newNode->data>=cur->data && cur->right==NULL) cur->right=newNode;
}
//-----------------------------
Node *FindNode(Node *root, int x){
	Node *cur;
	cur=root;
	while(cur!=NULL && cur->data!=x){
		if(cur->data>x) cur=cur->left;
		else cur=cur->right;
	}
	return cur;
}
//-----------------------------
Node *FindParent(Node *root, int x){
	Node *cur, *parent;
	cur=root;
	parent=NULL;
	while(cur!=NULL && cur->data!=x){
		parent=cur;
		if(cur->data>x) cur=cur->left;
		else cur=cur->right;
	}
	return parent;
}
//-----------------------------
Node *DeleteNode(Node *root){
	Node *cur, *temp, *parent;
	int x;
	cout<<"\nWhich node do you want to delete? "; cin>>x;
	cur=FindNode(root,x);
	parent=FindParent(root,x);
	if(cur){
		if(cur==root){
			if(cur->left==NULL && cur->right==NULL){
				delete root;
				root=NULL;
			}
			else if(cur->left==NULL && cur->right!=NULL){
				root=cur->right;
				//cur->right=NULL;
				delete cur;
			}
			else if(cur->left!=NULL && cur->right==NULL){
				root=cur->left;
				//cur->left=NULL;
				delete cur;
			}
			else{
				temp=cur->left;
				parent=cur->right;
				root=temp;
				while(temp->right!=NULL) temp=temp->right;
				temp->right=parent;
			}
		}
		else if(cur->left!=NULL && cur->right!=NULL){
			if(parent->left==cur){
				temp=cur->left;
				parent->left=cur->left;
				while(temp->right!=NULL) temp=temp->right;
				temp->right=cur->right;
				cur->left=NULL;
				cur->right=NULL;
			}
			else if(parent->right==cur){
				temp=cur->right;
				parent->right=cur->right;
				while(temp->left!=NULL) temp=temp->left;
				temp->left=cur->left;
				cur->left=NULL;
				cur->right=NULL;
			}
			delete cur;
		}
		else if(cur->left==NULL && cur->right!=NULL){
			if(parent->left==cur) parent->left=cur->right;
			else parent->right=cur->right;
			cur->right=NULL;
			delete cur;
		}
		else if(cur->left!=NULL && cur->right==NULL){
			if(parent->left==cur) parent->left=cur->left;
			else parent->right=cur->left;
			cur->left=NULL;
			delete cur;
		}
		else if(cur->left==NULL && cur->right==NULL){
			if(parent->left==cur) parent->left=NULL;
			else parent->right=NULL;
			delete cur;
		}
		cout<<"\nNode deleted!";
	}
	else cout<<"\nNode does not exist!";
	return root;
}
//-----------------------------
int CountNodes(Node *root){
	if(root==NULL) return 0;
	else return 1 + CountNodes(root->left) + CountNodes(root->right);
}
//-----------------------------
Node *SwapTree(Node *root){
   Node *cur1, *cur2;
   cur1=NULL;
   cur2=NULL;
   if(root!=NULL){ 
	   cur1=SwapTree(root->left);
	   cur2=SwapTree(root->right);
	   root->right=cur1;
	   root->left=cur2;
   }
   return(root);
}
//-----------------------------
void PrintStructure(Node* cur, int atkape=0){
	int i;
    if(cur!=NULL){
        PrintStructure(cur->right, atkape+1);
        for(i=0;i<atkape;i++) cout<<"   ";
        cout<<"("<<cur->data<<")\n";
        PrintStructure(cur->left, atkape+1);
    }
}
//-----------------------------
int main(){
	Node *root=NULL;
	int choice;
	do{
		system("cls");
		cout<<"\t\t\t\tBinary search tree";
		cout<<"\n1.Create root";
		cout<<"\n2.Print root value";
		cout<<"\n3.Print tree";
		cout<<"\n4.Add node";
		cout<<"\n5.Delete node";
		cout<<"\n6.Preorder tree travelling";
		cout<<"\n7.Inorder tree travelling";
		cout<<"\n8.Postorder tree travelling";
		cout<<"\n9.Count tree nodes";
		cout<<"\n10.Swap tree";
		cout<<"\n11.Print tree structure";
		cout<<"\n12.About";
		cout<<"\n0.Stop the program";
		cout<<"\n\nInput action number: "; cin>>choice;
		switch(choice){
			case 1: if(!root) root=CreateNode();
					else cout<<"\nRoot exists!";
					system("pause>nul");
					break;
			case 2: if(root){
					cout<<"\nRoot value: "<<root->data;
					cout<<"\nRoot left pointer: "<<root->left;
					cout<<"\nRoot right pointer: "<<root->right;
					}
					else cout<<"\nRoot does not exist! Create root!";
					system("pause>nul");
					break;
			case 3: if(root) PrintTree(root);
					else cout<<"\nTree does not exist!";
					system("pause>nul");
					break;
			case 4: if(root) AddNode(root);
					else cout<<"\nRoot does not exist! Create root!";
					system("pause>nul");
					break;
			case 5: if(root) root=DeleteNode(root);
					else cout<<"\nTree does not exist!";
					system("pause>nul");
					break;
			case 6: if(root) PreOrder(root);
			        else cout<<"\nTree does not exist!";
					system("pause>nul");
					break;
			case 7: if(root) PrintTree(root);
			        else cout<<"\nTree does not exist!";
					system("pause>nul");
					break;
			case 8: if(root) PostOrder(root);
			        else cout<<"\nTree does not exist!";
					system("pause>nul");
					break;
			case 9: if(root) cout<<"\nThere are "<<CountNodes(root)<<" nodes in the tree";
			        else cout<<"\nThere are no nodes in the tree!";
					system("pause>nul");
					break;
			case 10: if(root) { root=SwapTree(root); cout<<"\nTree swapped!"; }
			        else cout<<"\nTree does not exist!";
					system("pause>nul");
					break;
			case 11: if(root) PrintStructure(root);
					else cout<<"\nTree does not exist!";
					system("pause>nul");
					break;
			case 12: cout<<"\nAuthor: Dzeneta Meskovska\nVersion: 1.0";
					system("pause>nul");
					break;
			case 0: cout<<"Exit!";
					break;
			default: cout<<"I don't understand you!";
					system("pause>nul");
		}//switch
	}//do
	while(choice!=0);
	
	system("pause>nul");
	return 0;
}