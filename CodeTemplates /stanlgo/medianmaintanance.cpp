//median maintanance using two heaps  (7642)
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class heapLow
{
public:
	void insert(int a);
	int extractmin();
	void printheap();
	int returnmin();
	int size() {return h.size();} 
private:
	vector<int> h;
	void swap(int,int);
};

void heapLow::swap(int i,int j)
{
	int temp = h[i];
	h[i] = h[j];
	h[j] = temp;
}

void heapLow::insert(int a)
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

void heapLow::printheap()
{
	for(int i = 0 ; i < h.size() ; i = i*2 + 1)
	{
		for(int j = i; j < 2*i+1 ; j++)
			cout << h[j] << " " ;
		cout << endl ;
	}
}

int heapLow::extractmin()
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

int heapLow::returnmin()
{
	return h[0];
}

class heapHigh
{
public:
	void insert(int a);
	int extractmax();
	void printheap();
	int returnmax();
	int size() {return h.size();}   
private:
	vector<int> h;
	void swap(int,int);
};

void heapHigh::swap(int i,int j)
{
	int temp = h[i];
	h[i] = h[j];
	h[j] = temp;
}

void heapHigh::insert(int a)
{
	int i,child,temp;
	h.push_back(a); 
	child = h.size() - 1 ;
	while(i >= 0)
	{
		if(h[child] > h[(child-1)/2])   //(child-1)/2 is the parent
		{
			swap(child,(child-1)/2);
			child = (child-1)/2; 
		}
		else
			break;
	}	
}

void heapHigh::printheap()
{
	for(int i = 0 ; i < h.size() ; i = i*2 + 1)
	{
		for(int j = i; j < 2*i+1 ; j++)
			cout << h[j] << " " ;
		cout << endl ;
	}
}

int heapHigh::extractmax()
{
	int root = h[0];
	h[0] = h[h.size()-1];
	h.pop_back();

	int i = 0 ; int min ; 
	while(2*i + 1 < h.size())
	{ 
		min = 2*i+1 ; 
		if(h[2*i+2] > h[2*i+1])
			min = 2*i+2;
		swap(i,min);
		i = min ;
	}
	return root ;
}

int heapHigh::returnmax()
{
	return h[0];
}

int main()
{
	ifstream file("medianinp.txt");

	int a;
	heapHigh hh;
	heapLow hl;
	file >> a ;
	hh.insert(a); cout << a << " " ;
	unsigned long long int answer = a ;
	while(file >> a)
	{
		if(hh.size() == hl.size())
		{
			if(a <= hl.returnmin())
				hh.insert(a);
			else 
			{
				hh.insert(hl.extractmin());
				hl.insert(a);
			}
		}
		else
		{
			if(a >= hh.returnmax())
				hl.insert(a);
			else
			{
				hl.insert(hh.extractmax());
				hh.insert(a);
			}
		}
		cout << hh.returnmax() << " " ;
		answer += hh.returnmax() ;
	}
	cout << endl << answer % 10000 << endl ;
	return 0;
}