#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class llist
{
public:
	llist();
	void insertFront(int x);
	void print();
	// void insertAfter();
	// void insertLast(int x);
private:
	struct node* head ;
};

llist::llist()
{
	head = NULL;
}

void llist::insertFront(int x)
{
	struct node* new_node ;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = x;

	if(head==NULL)
	{
		*head = new_node;
		return;
	}

	new_node->next = *head ;
	*head = new_node ;
}

void llist::print()
{
	if(head==NULL)
		return;

	struct node *tmp = *head ;
	while(tmp!=NULL)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
}

int main()
{
	llist a;
	a.insertFront(5);
	a.print();
}