//Graph Implementation with BFS,DFS,TopoSort
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
		void BFS(int s);
		void doRun();
	private:
		vector< vector<int> > graph;
		vector<int> vals;
};

Graph::Graph(int n)
{
	vector<int> list;
	fr(i,0,n)
	{
		graph.pb(list);
		vals.pb(-1);
	}
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
		graph[v].pb(w);
	else
	{
		graph[v].pb(w);
		graph[w].pb(v);
	}
} 

void Graph::BFS(int s)
{
	bool visited[graph.size()];
	for(int i =0; i < graph.size() ; i++ )
		visited[i] = false ;

	//queue for visiting
	vector<int> q;
	q.pb(s);
	visited[s] = true ;
	vals[s] = 0 ;
	while(q.size() != 0)
	{
		for(int i = 0 ; i < graph[q[0]].size(); i++ )
		{
			if(visited[graph[q[0]][i]] == false)
			{
				//cout << graph[q[0]][i] << " " ;
				vals[graph[q[0]][i]] = 6+vals[q[0]] ;
				visited[graph[q[0]][i]] = true ;
				q.pb(graph[q[0]][i]);
			}
		}
		q.erase(q.begin());
	}
	//cout << endl ;
}

void Graph::doRun()
{
	fr(i,0,graph.size())
	{
		if(vals[i]!=0)
			cout << vals[i] << " ";
	}
	cout << endl ;
}

int main()
{
	int t;
	cin >> t ;
	while(t--)
	{
		int n ;
		cin >> n ;
		Graph g(n);
		int edges;
		cin >> edges ;
		int v,w;
		for(int i = 0 ; i < edges ;i++ )
		{
			cin >> v >> w ;
			g.addEgde(v-1,w-1,0);
		}
		int s;
		cin >> s ;
		//g.printAL();
		g.BFS(s-1);
		g.doRun();
	}
	return 0;
}