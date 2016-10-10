//Prims MST algorithm
#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

struct vertHeap
{
	int id;
	int key;
	bool set;
};

class heap
{
public:
	void insert(vertHeap a);
	void remove(int num);
	vertHeap extractmin();
	void printheap();  
private:
	vector< vertHeap > h;
	void swap(int,int);
};

void heap::swap(int i,int j)
{
	vertHeap temp = h[i];
	h[i] = h[j];
	h[j] = temp;
}

void heap::insert(vertHeap a)
{
	int child,temp;
	h.push_back(a); 
	child = h.size() - 1 ;
	while(child > 0)
	{
		if(h[(child-1)/2].key > h[child].key)   //(child-1)/2 is the parent
		{
			swap(child,(child-1)/2);
			child = (child-1)/2; 
		}
		else
			break;
	}	
}

void heap::printheap()
{
	cout << "Heap" << endl ;
	for(int i = 0 ; i < h.size() ; i = i*2 + 1)
	{
		for(int j = i; j < 2*i+1 ; j++)
		{
			if(j < h.size())
			cout << h[j].id << "," << h[j].key << " " ;
		}
		cout << endl ;
	}
}

vertHeap heap::extractmin()
{
	vertHeap root = h[0];
	h[0] = h[h.size()-1];
	h.pop_back();

	int i = 0 ; int min ; 
	while(2*i + 1 < h.size())
	{ 
		min = 2*i+1 ; 
		if(2*i+2 < h.size())
		{
			if(h[2*i+1].key < h[i].key || h[2*i+1].key < h[i].key )
			{
				if(h[2*i+1].key > h[2*i+2].key)
					min = 2*i+2;
				swap(i,min);
				i = min ;
			}
			else
				break;
		}
		else if(h[2*i+1].key < h[i].key)
		{
			swap(i,min);
			i = min ;
		}
		else 
			break;
	}
	return root ;
}

void heap::remove(int num)
{
	int i;
	for(i = 0 ; i < h.size(); i++)
	{
		if(num == h[i].id)
			break;
	}
	
	h[i] = h[h.size()-1];
	h.pop_back();

	int min ; 
	int child = i ;
	bool up = true;
	
	//heapify-up routine
	if(2*i+1 < h.size() && h[i].key > h[2*i+1].key)
		up = false ;
	if(2*i+2 < h.size() && h[i].key > h[2*i+2].key)
		up = false ;
	if(up)
	{
		while(child > 0)
		{
			if(h[(child-1)/2].key > h[child].key)   //(child-1)/2 is the parent
			{
				swap(child,(child-1)/2);
				child = (child-1)/2; 
			}
			else
				break;
		}	
	}
	else //heapify-down routine
	{
		while(2*i + 1 < h.size())
		{ 
			min = 2*i+1 ; 
			if(2*i+2 < h.size())
			{
				if(h[2*i+1].key < h[i].key || h[2*i+1].key < h[i].key )
				{
					if(h[2*i+1].key > h[2*i+2].key)
						min = 2*i+2;
					swap(i,min);
					i = min ;
				}
				else
					break;
			}
			else if(h[2*i+1].key < h[i].key)
			{
				swap(i,min);
				i = min ;
			}
			else 
				break;
		}
	}
}
int main()
{
	heap h ; 
	vertHeap tmp;
	tmp.id = 1; tmp.key = 4 ;
	h.insert(tmp); h.printheap();

	tmp.id = 2; tmp.key = 14 ;
	h.insert(tmp); h.printheap();

	tmp.id = 3; tmp.key = 5 ;
	h.insert(tmp); h.printheap();

	tmp.id = 4; tmp.key = 15 ;
	h.insert(tmp); h.printheap();

	tmp.id = 5; tmp.key = 16 ;
	h.insert(tmp); h.printheap();

	tmp.id = 6; tmp.key = 6 ;
	h.insert(tmp); h.printheap();

	tmp.id = 7; tmp.key = 7 ;
	h.insert(tmp); h.printheap();

	tmp.id = 8; tmp.key = 17 ;
	h.insert(tmp); h.printheap();

	tmp.id = 9; tmp.key = 18 ;
	h.insert(tmp); h.printheap();

	tmp.id = 10; tmp.key = 19 ;
	h.insert(tmp); h.printheap();

	tmp.id = 11; tmp.key = 20 ;
	h.insert(tmp); h.printheap();

	tmp.id = 12; tmp.key = 8 ;
	h.insert(tmp); h.printheap();

	h.remove(4);
	h.printheap();

	
	
}