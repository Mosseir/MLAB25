#include<iostream>
using namespace std;


class Node{
    public:
    	int data;
    	Node *next;
    	~Node();
};

class List{
	public:
		Node *root;
		int size;
		void show();
		void append(int);
		void insert(int,int);
		void remove(int);
};

Node::~Node(){
    cout << data << " was deleted.\n";
}

void List::insert(int d,int idx){	
	Node *n = new Node;
	n->data = d;
	
	if(idx == 0){
		n->next = root;
		root = n;
		return;
	}
	Node *current = root;
	for(int i = 0; i < idx-1;i++){
		current = current->next;
	}
	n->next = current->next;
	current->next = n;		
}

void List::show(){
	Node *current = root;
	cout << current->data << " ";	
	while(current->next){
		current = current->next;
		cout << current->data << " ";
	}	
}

void List::append(int d){	
	Node *n = new Node;
	n->data = d; n->next = NULL;
	if(root == NULL) root = n;
	else{
		Node *current = root;
		while(current->next){
			current = current->next;
		}
		current->next = n;
	}
	size++;
}

//Write List::remove() here
void List::remove(int index)
{	
	size--;
	Node *current = root;
	if (index == 0)
	{
		root = root->next;
		delete current;
	}
	else
	{
		for (int i = 0; i < index - 1; i++) current = current->next;
		Node *hereN = current->next;
		current->next = hereN->next;
		delete hereN;
	}
}

int main()
{
	List myList = {0,0};
	myList.append(5);
	myList.append(7);
	myList.append(11);
	myList.append(4);
	myList.append(12);
	myList.append(45);

	myList.insert(29,2);
	myList.insert(33,3);
	myList.insert(77,5);
	myList.insert(69,0);
	myList.show();
	cout << "\n"; 

	myList.remove(2);
	myList.show();
	cout << "\n"; 
	myList.remove(4);
	myList.show();
	cout << "\n";
	myList.remove(0);
	myList.show();
	cout << "\n";
}