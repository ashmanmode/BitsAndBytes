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
		void DFS(int s);
		void DFSRecursive(int s);
		void TopoSort();
	private:
		vector< vector<int> > graph;
		void DFSHelper(int s,bool arr[]);
};

Graph::Graph(int n)
{
	vector<int> list;
	fr(i,0,n)
		graph.pb(list);
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
	while(q.size() != 0)
	{
		for(int i = 0 ; i < graph[q[0]].size(); i++ )
		{
			if(visited[graph[q[0]][i]] == false)
			{
				cout << graph[q[0]][i] << " " ;
				visited[graph[q[0]][i]] = true ;
				q.pb(graph[q[0]][i]);
			}
		}
		q.erase(q.begin());
	}
	cout << endl ;
}

void Graph::DFS(int s)
{
	bool visited[graph.size()];
	for(int i =0; i < graph.size() ; i++ )
		visited[i] = false ;

	//stack for visiting
	int i ;
	vector<int> q;
	q.pb(s);
	visited[s] = true ;
	while(q.size() != 0)
	{
		for(i = 0 ; i < graph[q[q.size()-1]].size(); i++ )
		{
			if(visited[graph[q[q.size()-1]][i]] == false)
			{
				cout << graph[q[q.size()-1]][i] << " " ;
				visited[graph[q[q.size()-1]][i]] = true ;
				q.pb(graph[q[q.size()-1]][i]);
				break;
			}
		}
		if( i == graph[q[q.size()-1]].size())
			q.erase(q.begin() + q.size()-1 );
	}
	cout << endl ;
}

void Graph::DFSRecursive(int s)
{
	bool visited[graph.size()];
	for(int i =0; i < graph.size() ; i++ )
		visited[i] = false ;

	DFSHelper(s,visited);
}

void Graph::DFSHelper(int s, bool visited[])
{
	visited[s] = true;
	cout << s << " " ;

	fr(i,0,graph[s].size())
	{
		if(visited[graph[s][i]] == false)
			DFSHelper(graph[s][i],visited);
	}
}

void Graph::TopoSort()
{
	//dere r few bugs in here checkout with the SSC and modify
	int topo[graph.size()];
	int label = graph.size();
	bool visited[graph.size()];
	for(int i =0; i < graph.size() ; i++ )
		visited[i] = false ;

	//stack for visiting
	int i ;
	vector<int> q;
	for (int k = 0 ; k < graph.size() && visited[k] == false; k++ )
	{
		q.pb(k);
		visited[k] = true ;
		while(q.size() != 0)
		{
			for(i = 0 ; i < graph[q[q.size()-1]].size(); i++ )
			{
				if(visited[graph[q[q.size()-1]][i]] == false)
				{
					visited[graph[q[q.size()-1]][i]] = true ;
					q.pb(graph[q[q.size()-1]][i]);
					break;
				}
			}
			if( i == graph[q[q.size()-1]].size() )
			{
				topo[q[q.size()-1]] = label-- ;
				q.erase(q.begin() + q.size()-1 );
			}
		}
	}

	for(int i = 0 ; i < graph.size() ; i++ )
		cout << topo[i] << " ";
	cout << endl ;
}

int main()
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
		g.addEgde(v,w,1);
	}
	g.printAL();
	g.DFSRecursive(0);
	return 0;
}