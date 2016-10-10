#include <bits/stdc++.h>
using namespace std;

#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << fixed << a[i] << " " ;
typedef unsigned long long int ull;

int cost0;

#define gc getchar_unlocked
int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}

//class for directed weighted graph
class Graph
{
public:
	Graph(int n);
	void printAL();    //prints adjancency list
	void addEgde(int u,int v, int w); 
	int size;
	vector< vector< pair<int,int> > > graph;
};

Graph::Graph(int n)
{
	size = n ;
	vector< pair<int,int> > list;
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
			cout << graph[i][j].first << "," << graph[i][j].second << " " ;
		cout << endl ;
	}
}

void Graph::addEgde(int u,int v,int w)
{
	pair<int,int> tmp;
	tmp.first = v ; tmp.second = w ;
	graph[u].push_back(tmp);
} 

struct vertHeap
{
	int id;
	int key;
	bool set;
};

class heap
{
public:
	void insert(vertHeap a);
	void remove(int num);
	vertHeap extractmin();
	void printheap();  
private:
	vector< vertHeap > h;
	void swap(int,int);
};

void heap::swap(int i,int j)
{
	vertHeap temp = h[i];
	h[i] = h[j];
	h[j] = temp;
}

void heap::insert(vertHeap a)
{
	int i,child,temp;
	h.push_back(a); 
	child = h.size() - 1 ;
	while(i >= 0)
	{
		if(h[(child-1)/2].key > h[child].key)   //(child-1)/2 is the parent
		{
			swap(child,(child-1)/2);
			child = (child-1)/2; 
		}
		else
			break;
	}	
}

void heap::printheap()
{
	for(int i = 0 ; i < h.size() ; i = i*2 + 1)
	{
		for(int j = i; j < 2*i+1 ; j++)
			cout << h[j].id << "," << h[j].key << " " ;
		cout << endl ;
	}
}

vertHeap heap::extractmin()
{
	vertHeap root = h[0];
	h[0] = h[h.size()-1];
	h.pop_back();

	int i = 0 ; int min ; 
	while(2*i + 1 < h.size())
	{ 
		min = 2*i+1 ; 
		if(h[2*i+1].key > h[2*i+2].key)
			min = 2*i+2;
		swap(i,min);
		i = min ;
	}
	return root ;
}

void heap::remove(int num)
{
	int i;
	for(i = 0 ; i < h.size(); i++)
	{
		if(num == h[i].id)
			break;
	}
	
	h[i] = h[h.size()-1];
	h.pop_back();

	int min ; 
	while(2*i + 1 < h.size())
	{ 
		min = 2*i+1 ; 
		if(h[2*i+1].key > h[2*i+2].key)
			min = 2*i+2;
		swap(i,min);
		i = min ;
	}
}

ull dijkstra(Graph g,int v)
{
	vertHeap vertices[g.size];  //for keeping keys and the info abt set in which they are X or V-X
	for(int i = 0 ; i < g.size ; i++ )
	{
		vertices[i].id = i ;
		vertices[i].key = -1 ;
		vertices[i].set = false;
	}
	vertices[v].set = true;
	vertices[v].key = cost0;
	int new_key;

	//making a heap to store keys and respective vertices
	heap h;
	vertHeap extracted;
	for(int k = 0 ; k < g.size - 1 ; k++)
	{
		for(int i = 0 ; i < g.graph[v].size() ; i++ )
		{
			new_key = vertices[v].key + g.graph[v][i].second ; 
			if(vertices[g.graph[v][i].first].set == false)
			{
				if(vertices[g.graph[v][i].first].key == -1)
				{
					vertices[g.graph[v][i].first].key = new_key ;
					h.insert(vertices[g.graph[v][i].first]);
				}
				else if(vertices[g.graph[v][i].first].key > new_key)
				{
					h.remove(g.graph[v][i].first);
					vertices[g.graph[v][i].first].key = new_key ;
					h.insert(vertices[g.graph[v][i].first]);
				}
			}
		}
		extracted = h.extractmin();
		extracted.set = true ;
		vertices[extracted.id] = extracted ;
		v = extracted.id; 
	}

	ull ans1,ans2;
	ans1 = vertices[g.size-1].key ;
	ans2 = vertices[g.size/2-1].key ;
	return min(ans1,ans2)  ;
}

int main()
{
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);

	int test;
	scanf("%d",&test);

	while(test--)
	{
		int n,m,e;
		scanf("%d",&n); 
		scanf("%d",&m); 

		Graph g(n*m*2);
		fr(i,0,m)
		{
			scanf("%d",&e);
			if(i>0)
				g.addEgde(i-1,i,e);
			else
				cost0 = e ;
		}
		fr(i,1,n)
		{
			fr(j,0,m)
			{
				scanf("%d",&e);
				if(j>0)
					g.addEgde(i*m+j-1,i*m+j,e);
				g.addEgde( n*m+(i-1)*m + j , n*m+i*m+j,e);
			}
		}

		fr(i,0,n)
		{
			fr(j,0,m)
			{
				scanf("%d",&e);
				g.addEgde(i*m+j,n*m+i*m+j,e);
				g.addEgde(i*m+j+n*m,i*m+j,e);
			}
		}
	    
	    cout << min(dijkstra(g,0),dijkstra(g,n*m))<< endl;   
	}
	return 0 ; 
}