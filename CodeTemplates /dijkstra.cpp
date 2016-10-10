//Dijkstra
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
		void printAL();    
		void addEgde(int v, int w,int k); 
		void dijkstra(int s);
	private:
		vector< vector< pair<int,int> > > graph; //<EdgeWeight,VertexID>
};

Graph::Graph(int n)
{
	vector< pair<int,int> > list;
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
			cout << "( " << graph[i][j].S << " , " << graph[i][j].F << " ) " ;
		cout << endl ;
	}
}

void Graph::addEgde(int v,int w,int k)
{
	graph[v].pb(mp(k,w)); 
	graph[w].pb(mp(k,v)); 
} 

void Graph::dijkstra(int s)
{
	vector<int> distance(graph.size());
	fr(i,0,graph.size())
		distance[i] = -1*INT_MAX ;
	distance[s] = 0 ; 

	//Priority queue to maintain edges and weights
	priority_queue< pair<int,int> > q ; //<edgeWeight,vetrexID>
	q.push(mp(0,s));
	while(!q.empty())
	{
		int vertex = q.top().S ; 
		q.pop();
		//cout << vertex << endl;
		fr(i,0,graph[vertex].size())
		{
			if(distance[vertex]+graph[vertex][i].F > distance[graph[vertex][i].S])
			{
				//cout << "change " << distance[graph[vertex][i].S] << " to " << distance[vertex]+graph[vertex][i].F << endl ; 
				distance[graph[vertex][i].S] = distance[vertex]+graph[vertex][i].F ;
				q.push(mp(distance[graph[vertex][i].S],graph[vertex][i].S));
			}			
		}
		
	}

	fr(i,0,graph.size())
	{
		if(distance[i]==0)
			continue;
		else if(distance[i] == -1*INT_MAX)
			cout << -1 << " ";
		else
			cout << distance[i]*-1 << " " ;
	}
	cout << endl;
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
		int v,w,k;
		for(int i = 0 ; i < edges ;i++ )
		{
			cin >> v >> w >> k;
			g.addEgde(v-1,w-1,-1*k);
		}
		//g.printAL();
		int s ;
		cin >> s ;
		g.dijkstra(s-1);
	}
	return 0;
}