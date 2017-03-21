#include <bits/stdc++.h>
using namespace std;

int n ;
int rank[1005];
int parent[1005];
int sets;

void preprocess()
{
	for(int i=0;i<n;i++)
	{
		rank[i] = 0  ;
		parent[i] =  i ;
	}
}

int findRoot(int x)
{
	if(parent[x]!=x)
		return findRoot(parent[x]);
	return x;
}

void merge(int x,int y)
{
	int px = findRoot(x);
	int py = findRoot(y);

	if(px!=py)
	{
		sets--;
		if(rank[px] > rank[py])
		{
			parent[py] = px ;
			rank[px] += rank[py];
		}
		else if(rank[px] == rank[py])
		{
			parent[px] = py;
			rank[py]++;
		}
		else
		{
			parent[px] = py;
			rank[py] += rank[px];
		}
	}
}

int main()
{
	cin >> n ; 
	
	preprocess();

	int x ;
	sets = n ;
	for(int i=0;i<n;i++)
	{
		cin >> x ;
		if(i!=0)
			merge(i,x-1);
		// for(int i=0;i<n;i++)
		// 	cout << parent[i] << " - " << rank[i] << endl;
	}
	cout << "sets " << sets-1 << endl ;
	return 0;
}