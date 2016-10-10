#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define mod 1000000007
#define F first
#define S second
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%llu",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%llu",a)
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
typedef unsigned long long int ull;
typedef signed long long int sll;

struct edge
{
	int u;
	int v;
	int w;
};

bool mycomp(edge a,edge b)
{
	return a.w < b.w ;
}

//global DS container
vector<int> rankA;   //here rankA is the size of set	
vector<int> parentA;	//parentA denotes root as well as parentA

int findroot(int x)
{
	if(x != parentA[x])
		return findroot(parentA[x]);
	return x;
}

void mergeset(int x,int y)
{
	int px = findroot(x);
	int py = findroot(y);
	if(px != py)
	{
		if(rankA[px] > rankA[py])
		{
			parentA[py] = px ;
			rankA[px] += rankA[py];  
		}
		else
		{
			parentA[px] = py ;
			rankA[py] += rankA[px];
		}
	}
}

int main()
{

	int nodes,edges;
	cin >> nodes >> edges;
	
	//initialise all the nodes to be separate;
	fr(i,0,nodes) 
	{
		rankA.pb(1);
		parentA.pb(i);
	}

	//Graph input
	vector<edge> e;
	edge tmp;
	int a;
	while(edges--)
	{
		cin >> tmp.u >> tmp.v ;
		cin >> a ;
		if(a==0)
			tmp.w = 0 ;
		else
			cin >> tmp.w ; 
		tmp.u-- ; tmp.v -- ;
		e.pb(tmp);
	}
	sort(e.begin(),e.end(),mycomp);

	//Kruskal MST
	sll mincost = 0 ;
	for(int i = 0 ; i < e.size() ; i++ )
	{
		if(findroot(e[i].u) != findroot(e[i].v))
		{
			mincost += e[i].w ;
			mergeset(e[i].u,e[i].v);
		}
	}

	cout << mincost << endl ;
	return 0;
}