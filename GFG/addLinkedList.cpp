#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	int carry;
	struct node *next;
};

void printList(struct node *head)
{
	cout << "Printing Lisked List : " ;
	while(head!=NULL)
	{
		cout << head->data << " " ;
		head = head->next ;
	}
	cout << endl ;
}

struct node* addLinkedListsHelper(struct node *head,struct node *tail)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	if(head->next==NULL&&tail->next==NULL)
	{
		temp->data = (head->data+tail->data)%10;
		temp->carry = (head->data+tail->data)/10;
		temp->next = NULL;	
	}
	else
	{
		struct node *nextNode = addLinkedListsHelper(head->next,tail->next) ;
		temp->data = (head->data+tail->data+nextNode->carry)%10;
		temp->carry = (head->data+tail->data+nextNode->carry)/10;
		temp->next = nextNode ;
	}
	return temp;
}

struct node* addLinkedLists(struct node *head,struct node *tail)
{
	struct node *result  = addLinkedListsHelper(head,tail);
	if(result->carry > 0)
	{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->data = result->carry;
		temp->next = result;
		return temp;
	}
	return result;
}

int main()
{
	struct node *head = (struct node*)malloc(sizeof(struct node));
	struct node *head1 = (struct node*)malloc(sizeof(struct node));
	struct node *head2 = (struct node*)malloc(sizeof(struct node));

	head->data = 1;
	head1->data = 2;
	head2->data = 3;
	head->next = head1;
	head1->next = head2;
	head2->next = NULL;

	struct node *tail = (struct node*)malloc(sizeof(struct node));
	struct node *tail1 = (struct node*)malloc(sizeof(struct node));
	struct node *tail2 = (struct node*)malloc(sizeof(struct node));

	tail->data = 8;
	tail1->data = 9;
	tail2->data = 10;
	tail->next = tail1;
	tail1->next = tail2;
	tail2->next = NULL;

	printList(head);
	printList(tail);

	struct node *addition = addLinkedLists(head,tail);
	printList(addition);
	return 0;
}