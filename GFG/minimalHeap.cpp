#include <bits/stdc++.h>
using namespace std;

class minHeap
{
private:
	int *heapContainer;
	int *currentLoc;
	int n;
public:
	void AllocTinyHeap(int n);
	void DeleteTinyHeap();
	void AllocTiny(int n);
	void print();
};

void minHeap::AllocTinyHeap(int n)
{
	heapContainer = (int*)malloc(sizeof(int)*n);
	currentLoc = heapContainer ;
	this->n = n ;
}

void minHeap::AllocTiny(int n)
{
	*(currentLoc++) = n ;
}

void minHeap::DeleteTinyHeap()
{
	delete [] heapContainer ;
	heapContainer = NULL;
	currentLoc = NULL;
}

void minHeap::print()
{
	if(heapContainer==NULL)
	{
		cout << "Empty" << endl;
		return;
	}

	for(int i=0;i<n;i++)
		cout << heapContainer+i << " " << *(heapContainer+i) << endl;
}

int main()
{
	minHeap heap;
	heap.AllocTinyHeap(10);
	heap.AllocTiny(2);
	heap.AllocTiny(3);
	heap.AllocTiny(4);
	heap.AllocTiny(5);
	heap.print();
	heap.DeleteTinyHeap();
	heap.print();

	// int *a,*b;
	// a = (int*)malloc(sizeof(int)*5);
	// b = a; 
	// *(a++) = 10;
	// *(a++) = 9 ;
	// *(a++) = 8 ;
	// *(a++) = 7 ;
	// *(a++) = 6 ;
	// cout << *(b++) << endl;
	// cout << *(b++) << endl;
	// cout << *(b++) << endl;
	// cout << *(b++) << endl;
	// cout << *(b++) << endl;
	// cout << *(b++) << endl;


	return 0;
}