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
#define printvect(a,n) fr(i,0,n) cout << fixed << a[i] << " " ;
typedef unsigned long long int ull;

class Graph
{
public:
	Graph(int n);
	void printAL();    //prints adjancency list
	void addEgde(int v, int w, bool directed); //for directed edge put directed = 1 
	void DFS(int s);
private:
	vector< vector<int> > graph;
};

Graph::Graph(int n)
{
	vector<int> list;
	for(int i = 0 ; i < n ; i++ )
		graph.push_back(list);
}

void Graph::printAL()
{
	cout << "printing the Adjacency list " << endl ;
	for(int i = 0 ; i < graph.size() ;i++ )
	{
		cout << "v" << i << " - " ;
		for(int j = 0 ; j < graph[i].size() ; j++ )
			cout << graph[i][j] << " " ;
		cout << endl ;
	}
}

void Graph::addEgde(int v,int w,bool directed)
{
	if(directed == true)
		graph[v].push_back(w);
	else
	{
		graph[v].push_back(w);
		graph[w].push_back(v);
	}
} 

void Graph::DFS(int s)
{
	bool visited[graph.size()];
	for(int i =0; i < graph.size() ; i++ )
		visited[i] = false ;

	//stack for visiting
	int i ;
	vector<int> q;
	q.push_back(s);
	visited[s] = true ;
	while(q.size() != 0)
	{
		for(i = 0 ; i < graph[q[q.size()-1]].size(); i++ )
		{
			if(visited[graph[q[q.size()-1]][i]] == false)
			{
				cout << graph[q[q.size()-1]][i] << " " ;
				visited[graph[q[q.size()-1]][i]] = true ;
				q.push_back(graph[q[q.size()-1]][i]);
				break;
			}
		}
		if( i == graph[q[q.size()-1]].size())
			q.erase(q.begin() + q.size()-1 );
	}
	cout << endl ;
}

int main()
{
	ull test;
	cin >> test;
	fr(t,0,test)
	{
		int n,k;
		cin >> n;

		Graph g(n);
		fr(i,0,n)
		{
			cin >> k ;
			g.addEgde(i,k-1,0);
		}
		g.printAL();
		g.DFS(0);
		cout << "Case #" << t+1 << ": " ;
	}
	return 0;
}