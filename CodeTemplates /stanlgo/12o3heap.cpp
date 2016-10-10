//heap data structure
#include <iostream>
#include <vector>
using namespace std;

class heap
{
public:
	void insert(int a);
	int extractmin();
	void printheap();  
private:
	vector<int> h;
	void swap(int,int);
};

void heap::swap(int i,int j)
{
	int temp = h[i];
	h[i] = h[j];
	h[j] = temp;
}

void heap::insert(int a)
{
	int i,child,temp;
	h.push_back(a); 
	child = h.size() - 1 ;
	while(i >= 0)
	{
		if(h[(child-1)/2] > h[child])   //(child-1)/2 is the parent
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
	for(int i = 0 ; i < h.size() ; i = i*2 + 1)
	{
		for(int j = i; j < 2*i+1 ; j++)
			cout << h[j] << " " ;
		cout << endl ;
	}
}

int heap::extractmin()
{
	int root = h[0];
	h[0] = h[h.size()-1];
	h.pop_back();

	int i = 0 ; int min ; 
	while(2*i + 1 < h.size())
	{ 
		min = 2*i+1 ; 
		if(h[2*i+1] > h[2*i+2])
			min = 2*i+2;
		swap(i,min);
		i = min ;
	}
	return root ;
}

int main()
{
	int a ;
	heap h1;
	for(int i = 0 ; i < 9 ; i++)
	{
		cin >> a ;
		h1.insert(a);
	}
	for(int i = 0 ; i < 10 ; i++)
		cout << "min" << h1.extractmin() << endl ;
	return 0 ;
} 