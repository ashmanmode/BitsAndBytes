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
	void addEgde(int v, int w, bool directed); 
	void removeEgde(int v,int w); //for directed edge put directed = 1
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

void Graph::removeEgde(int v,int w)
{
	fr(i,0,graph[v].size())
	{
		if(graph[v][i]==w)
			graph[v].erase(graph[v].begin()+i);
	}
	// cout << "done" << endl;
}
int main()
{
	ull test;
	cin >> test;
	fr(t,0,test)
	{
		int n;
		cin >> n ; 
		string a,b;
		map<string,int> first;
		int count = 0 ;

		vector< pair<int,int> > data;
		fr(i,0,n)
		{
			cin >> a >> b ;
  			if (first.find(a) == first.end())
				first[a] = count++ ;
			if (first.find(b) == first.end())
				first[b] = count++ ;
			data.pb(make_pair(first[a],first[b]));
		}

		// fr(i,0,data.size())
		// cout << data[i].first << " " << data[i].second << endl ;
		Graph g(first.size());
		fr(i,0,data.size())
			g.addEgde(data[i].first,data[i].second,1);

		Graph gr(first.size());
		fr(i,0,data.size())
			gr.addEgde(data[i].second,data[i].first,1);

		// g.printAL();
		// gr.printAL();

		//count all edges
		int edges = 0 ;
		int temp;
		fr(i,0,g.graph.size())
		{	
			// cout << "v" << i << " ";
			if(g.graph[i].size()>1)
			{
				fr(j,0,g.graph[i].size())
				{
					// cout << g.graph[i][j] << " " ;
					if(gr.graph[g.graph[i][j]].size()>1)
						edges++;
					else if(gr.graph[g.graph[i][j]].size()==1)
					{
						// cout << "remo1" << i << g.graph[i][j] << endl;
						temp = g.graph[i][j];
						g.removeEgde(i,temp);
						gr.removeEgde(temp,i);
						j--;
					}
				}
			}
			else if(g.graph[i].size()==1)
			{
						// cout << "remo2" << i << g.graph[i][0] << endl;
				temp = g.graph[i][0];
				g.removeEgde(i,temp);
				gr.removeEgde(temp,i);
				i--;
			}
			// cout << endl ;
		}

		g.printAL();
		gr.printAL();
		// cout << edges << endl ;
		// cout << "dfvdfv" << endl;
		//Now find nodes on first and second side
		int nodesA = 0 ;
		int nodesB = 0 ;
		fr(i,0,g.graph.size())
		{	
			if(g.graph[i].size()>1)
			{
				// cout << "v" << i << " ";
				nodesA++;
			}
		}
		// cout << "dfvdfv" << endl;

		fr(i,0,gr.graph.size())
		{	
			if(gr.graph[i].size()>1)
			{
				// cout << "v" << i << " ";
				nodesB++;
			}
		}

		cout << "Case #" << t+1 << ": " << edges-max(nodesA,nodesB) << endl ;
	}
	return 0;
}