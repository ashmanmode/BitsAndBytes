//DISJOINT - UNION DATA STRUCTURE FOR GRAPHS
//used to check for connectivity, takes lesser time than BFS as only connectivity is needed
//and not the path or path length
#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
typedef unsigned long long int ull;

//global DS container
vector<int> rank;   //here rank is the size of set	
vector<int> parent;	//parent denotes root as well as parent
int lset;

int findroot(int x)
{
	if(x != parent[x])
		return findroot(parent[x]);
	return x;
}

void mergeset(int x,int y)
{
	int px = findroot(x);
	int py = findroot(y);
	if(px != py)
	{
		if(rank[px] > rank[py])
		{
			parent[py] = px ;
			rank[px] += rank[py];  
			if(rank[px] > lset) lset = rank[px];
		}
		else
		{
			parent[px] = py ;
			rank[py] += rank[px];
			if(rank[py] > lset) lset = rank[py];
		}
	}
}

int main()
{
	int nodes;
	cin >> nodes ;
	
	//initialise all the nodes to be separate;
	fr(i,0,nodes) 
	{
		rank.pb(1);
		parent.pb(i);
	}
	lset = 1 ;

	//DS check
	int q,q_type,x,y;
	cout << "no. of queries" << endl ; cin >> q ;
	fr(i,0,q)
	{
		cin >> q_type ;
		switch(q_type)
		{
			case 1: //merge two sets
					cin >> x >> y ; mergeset(x,y);
					break;
			case 2: //check connectivity
					cin >> x >> y ; 
					if(findroot(x)==findroot(y)) cout << "Connected" << endl;
					else cout << "Oops" << endl ;
					break;
			case 3: //size of set with given element
					cin >> x ; cout << rank[findroot(x)] << endl ;
					break;
			case 4: //size of largest set
					cout << lset << endl;
		}
	}
	return 0;
}