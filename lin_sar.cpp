#include<iostream>
#include<cstdlib>

using namespace std;

struct Node{
    int data; //4B
    Node *link; //4B
};
//---------------------------------	
Node *CreateNode(){
	Node *newNode;
	newNode=new Node;
	cout<<"\nInput node's integer number:  ";
	cin>>newNode->data;
	newNode->link=NULL;
	return newNode;
}
//---------------------------------
void PrintList (Node *head){ 
	Node *cur;
	cout<<"\nList items:\n";
	cur=head;
	if(cur==NULL) cout<<"\nThe list is empty";
	else{
		while (cur!=NULL){
			cout<<cur->data<<" ";
			cur=cur->link;        
		}
	}
}
//----------------------------------
Node *AddFirst(Node *head){
	Node *cur;
	cur=new Node;
	cur=CreateNode();
	cur->link=head;
	head=cur;
	return head;
}
//----------------------------------
void AddLast(Node *head){
	Node *cur1, *cur;
	cur1=new Node;
	cur1=CreateNode();
	cur=head;
	while(cur->link!=NULL) cur=cur->link;
	cur->link=cur1;
}
//----------------------------------
Node *FindNode(Node *head, int x){
	Node *cur;
	cur=head;
	while(cur!=NULL && cur->data!=x) cur=cur->link;
	return cur;
}
//----------------------------------
Node *PreviousNode(Node *head, int x){
	Node *cur, *prev;
	cur=head;
	while(cur!=NULL && cur->data!=x){
		prev=cur;
		cur=cur->link;
	}
	return prev;
}
//----------------------------------
Node *AddBefore(Node *head){
	int x;
	Node *cur, *newNode, *prev;
	cout<<"Before which node to add: ";
	cin>>x;
	cur=FindNode(head, x);
	if(cur){
		cout<<"Node exists!\n";
		newNode=CreateNode();
		prev=PreviousNode(head,x);
		if(head->data == x){
			newNode->link=head;
			head=newNode;
		}
        else{
		prev->link=newNode;
		newNode->link=cur;
		}
    cout<<"New node is added!\n";
	}
	else cout<<"Node does not exist!\n";
	return head;
}
//----------------------------------
void AddAfter(Node *head){
	Node *cur, *vid;
	int x;
	cout<<"\nAfter which node to add? "; cin>>x;
	cur=FindNode(head,x);
	if(cur){
		vid=new Node;
		vid=CreateNode();
		vid->link=cur->link;
		cur->link=vid;
	}
	else cout<<"\nNode does not exist!";
}
//----------------------------------
Node *DeleteFirst(Node *head){
	Node *cur;
	cur=head->link;
	delete head;
	cout<<"\nNode deleted!";
	head=cur;
	return head;
}
//----------------------------------
Node *DeleteLast(Node *head){
	Node *cur;
	cur=head;
	if(cur->link==NULL) head=DeleteFirst(head);
	else{
		while(cur->link->link!=NULL) cur=cur->link;
		delete cur->link;
		cur->link=NULL;
		cout<<"\nNode deleted!";
	}
	return head;
}
//----------------------------------
void DeleteAfter(Node *head){
	Node *cur, *oldNode;
	int x;
	cout<<"\nAfter which node to delete? "; cin>>x;
	cur=FindNode(head,x);
	if(cur){
		if(cur->link==NULL) cout<<"\nThere is no node after this one!";
		else{
			oldNode=cur->link;
			cur->link=oldNode->link;
			delete oldNode;
			cout<<"\nNode deleted!";
		}
	}
	else cout<<"\nNode does not exist!";
}
//----------------------------------
Node *DeleteBefore(Node *head){
	Node *cur, *prev, *prev2;
	int x;
	cout<<"\nBefore which node to delete? "; cin>>x;
	cur=FindNode(head,x);
	if(cur){
		if(cur==head) cout<<"\nThere is no node before this one!";
		else{
			prev=PreviousNode(head,x);
			if(prev==head) head=DeleteFirst(head);
			else{
				prev2=PreviousNode(head,prev->data);
				prev2->link=cur;
				delete prev;
			}
			cout<<"\nNode deleted!";
		}
	}
	else cout<<"\nNode does not exist!";
	return head;
}
//----------------------------------
int CountItems(Node *head){
	int count;
	Node *cur;
	cur=head;
	while(cur!=NULL){
		cur=cur->link;
		count++;
	}
	return count;
}
//----------------------------------
Node *DeleteList(Node *head){
	Node *cur, *cur1;
	cur=head;
	while(cur!=NULL){
		cur1=cur;
		cur=cur->link;
		delete cur1;
	}
	cout<<"\nList deleted!";
	head=NULL;
	return head;
}
//----------------------------------
int main() {
	Node *head=NULL;
	int choice;
	do{
		system("cls");
		cout<<"\t\t\t\tLinked list";
		cout<<"\n99.Create head";
		cout<<"\n1.Print head";
		cout<<"\n2.Print list";
		cout<<"\n3.Add node to list beginning";
		cout<<"\n4.Add node to list ending";
		cout<<"\n5.Add new node before a node";
		cout<<"\n6.Add new node after a node";
		cout<<"\n7.Delete node in the beginning";
		cout<<"\n8.Delete node in the ending";
		cout<<"\n9.Delete node before a node";
		cout<<"\n10.Delete node after a node";
		cout<<"\n11.Count list items";
		cout<<"\n12.Delete the list";
		cout<<"\n0.STOP the program";
		cout<<"\n\nChoose action number: ";
		cin>>choice;
	switch(choice){
		case 99: head=CreateNode();
				 break;
		case 1: if(head){
				cout<<"Head value= "<<head->data;
				cout<<"\nHead link= "<<head->link;}
				else cout<<"\nHead doesn't exist! Create a head!";
				system("pause>nul");
				break;
		case 2: PrintList(head);
				system("pause>nul");
				break;
		case 3: head=AddFirst(head);
				break;
		case 4: if(head) AddLast(head);
				else cout<<"\nHead doesn't exist! Create a head!";
				system("pause>nul");
				break;
		case 5: if (head) head=AddBefore(head);
				else cout<<"\nHead doesn't exist! Create a head!";
				system("pause>nul");
				break;
		case 6: if(head) AddAfter(head);
				else cout<<"\nHead doesn't exist! Create a head!";
				system("pause>nul");
				break;
		case 7: if(head) head=DeleteFirst(head);
				else cout<<"\nHead doesn't exist! Create a head!";
				system("pause>nul");
				break;
		case 8: if(head) head=DeleteLast(head);
				else cout<<"\nHead doesn't exist! Create a head!";
				system("pause>nul");
				break;
		case 9: if(head) head=DeleteBefore(head);
				else cout<<"\nHead doesn't exist! Create a head!";
				system("pause>nul");
				break;
		case 10: if(head) DeleteAfter(head);
				else cout<<"\nHead doesn't exist! Create a head!";
				system("pause>nul");
				break;
		case 11: if(head) cout<<"\nThere are "<<CountItems(head)<<" items in this list";
				else cout<<"\nThere are no items in this list!";
				system("pause>nul");
				break;
		case 12: if(head) head=DeleteList(head);
				else cout<<"\nThe list is already empty!";
				system("pause>nul");
				break;
		case 0: cout<<"STOP the program";
				break;
		default: cout<<"Wrong number choice!";
				system("pause>nul");
	 } //switch
	} //do
	while(choice!=0);
	
	system("pause>nul");
	return 0;
}
