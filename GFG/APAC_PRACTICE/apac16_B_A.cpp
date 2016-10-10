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

struct EdgeWeight
{
	int time[24];
};

class Graph
{
	public:
		Graph(int n);
		void printAL();    
		void addEgde(int v, int w,EdgeWeight k); 
		void dijkstra(int s,int t,int dest);
	private:
		vector< vector< pair<EdgeWeight,int> > > graph; //<EdgeWeight,VertexID>
};

Graph::Graph(int n)
{
	vector< pair<EdgeWeight,int> > list;
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
			cout << graph[i][j].S << " " ;
		cout << endl ;
	}
}

void Graph::addEgde(int v,int w,EdgeWeight k)
{
	graph[v].pb(mp(k,w)); 
	graph[w].pb(mp(k,v)); 
} 

void Graph::dijkstra(int s,int t,int dest)
{
	vector<int> distance(graph.size());
	fr(i,0,graph.size())
		distance[i] = -1*INT_MAX ;
	distance[s] = -1*t ; 

	//Priority queue to maintain edges and weights
	priority_queue< pair<int,int> > q ; //<edgeWeight,vetrexID>
	q.push(mp(0,s));
	while(!q.empty())
	{
		int vertex = q.top().S ; 
		q.pop();
		int curTime = (distance[vertex]*-1)%24;
		// cout << vertex <<  " time: " << curTime <<  endl;
		fr(i,0,graph[vertex].size())
		{
			if(distance[vertex]+graph[vertex][i].F.time[curTime] > distance[graph[vertex][i].S])
			{
				// cout << "change " << graph[vertex][i].S << " to " << distance[vertex]+graph[vertex][i].F.time[curTime] << endl ; 
				distance[graph[vertex][i].S] = distance[vertex]+graph[vertex][i].F.time[curTime] ;
				q.push(mp(distance[graph[vertex][i].S],graph[vertex][i].S));
			}			
		}
		
	}

	if(distance[dest] == -1*INT_MAX)
		cout << -1 << " ";
	else
		cout << distance[dest]*-1 - t << " " ;
}

int main()
{
	ull test;
	cin >> test;
	fr(t,0,test)
	{
		int n,m,k,x,y,z;
		cin >> n >> m >> k ;
		Graph g(n);
		fr(i,0,m) 
		{
			cin >> x >> y ;
			EdgeWeight w ;
			fr(j,0,24)
			{
				cin >> w.time[j] ; 
				w.time[j] *= -1 ;
			}
			g.addEgde(x-1,y-1,w);
		}
		// g.printAL();
		cout << "Case #" << t+1 << ": ";
		fr(i,0,k)
		{
			cin >> x >> y ;
			g.dijkstra(0,y,x-1);
		}
		cout << endl ;
	}
	return 0;
}