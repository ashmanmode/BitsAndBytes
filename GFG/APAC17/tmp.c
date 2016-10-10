#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	int some;
	int some1;
	int some2;
	struct node *next;
};

typedef struct node NODE;

NODE *getnode()
{
	NODE *p ; 
	p = (NODE*)malloc(sizeof(NODE));
	printf("%ld\n", sizeof(int));
	printf("%ld\n", sizeof(int*));
	return p;
}

int main()
{
	printf("%s\n","sdvbdfyuvb" );

	NODE *p = getnode();
	p->info = 5;
	p->next = NULL;	
	
	printf("%p\n",(void *)p);
	printf("%d\n",p->info);
	return 0;
}