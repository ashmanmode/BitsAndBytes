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
vector<int> rank;   //here rank is the size of set	
vector<int> parent;	//parent denotes root as well as parent

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
		}
		else
		{
			parent[px] = py ;
			rank[py] += rank[px];
		}
	}
}

int main()
{

	int nodes,clusters;
	cin >> nodes >> clusters;
	
	//initialise all the nodes to be separate;
	fr(i,0,nodes) 
	{
		rank.pb(1);
		parent.pb(i);
	}

	//Graph input
	vector<edge> e;
	edge tmp;
	while(cin >> tmp.u >> tmp.v >> tmp.w )
	{
		tmp.u-- ; tmp.v -- ;
		e.pb(tmp);
	}
	sort(e.begin(),e.end(),mycomp);

	//cluster making
	int c = nodes ;
	for(int i = 0 ; i < e.size() ; i++ )
	{
		if(findroot(e[i].u) != findroot(e[i].v))
		{
			if(c == clusters)
			{
				cout << e[i].w << endl ;
				break;
			}
			mergeset(e[i].u,e[i].v);
			c-- ;
		}
	}

	return 0;
}