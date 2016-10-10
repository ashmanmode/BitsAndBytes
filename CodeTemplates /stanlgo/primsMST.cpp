//Prims MST algorithm
#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

//class for directed weighted graph
class Graph
{
public:
	Graph(int n);
	void printAL();   
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
	tmp.first = u ; tmp.second = w ;
	graph[v].push_back(tmp);
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
	int child,temp;
	h.push_back(a); 
	child = h.size() - 1 ;
	while(child > 0)
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
		if(2*i+2 < h.size())
		{
			if(h[2*i+1].key < h[i].key || h[2*i+1].key < h[i].key )
			{
				if(h[2*i+1].key > h[2*i+2].key)
					min = 2*i+2;
				swap(i,min);
				i = min ;
			}
			else
				break;
		}
		else if(h[2*i+1].key < h[i].key)
		{
			swap(i,min);
			i = min ;
		}
		else 
			break;
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
	int child = i ;
	bool up = true;
	
	//heapify-up routine
	if(2*i+1 < h.size() && h[i].key > h[2*i+1].key)
		up = false ;
	if(2*i+2 < h.size() && h[i].key > h[2*i+2].key)
		up = false ;
	if(up)
	{
		while(child > 0)
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
	else //heapify-down routine
	{
		while(2*i + 1 < h.size())
		{ 
			min = 2*i+1 ; 
			if(2*i+2 < h.size())
			{
				if(h[2*i+1].key < h[i].key || h[2*i+1].key < h[i].key )
				{
					if(h[2*i+1].key > h[2*i+2].key)
						min = 2*i+2;
					swap(i,min);
					i = min ;
				}
				else
					break;
			}
			else if(h[2*i+1].key < h[i].key)
			{
				swap(i,min);
				i = min ;
			}
			else 
				break;
		}
	}
}

signed long long int prim(Graph g,int v)
{
	//cout << "************** RUN " << v << endl ;
	signed long long int mincost = 0 ;
	vertHeap vertices[g.size];  //for keeping keys and the info abt set in which they are X or V-X
	for(int i = 0 ; i < g.size ; i++ )
	{
		vertices[i].id = i ;
		vertices[i].key = INF ;
		vertices[i].set = false;
	}
	int new_key; 
	vertices[v].set = true; 	
	

	//making a heap to store keys and respective vertices
	heap h;
	vertHeap extracted;
	for(int k = 0 ; k < g.size - 1 ; k++)
	{
		for(int i = 0 ; i < g.graph[v].size() ; i++ )
		{
			new_key = g.graph[v][i].second ; 
			if(vertices[g.graph[v][i].first].set == false)
			{
				if(vertices[g.graph[v][i].first].key == INF)
				{
					vertices[g.graph[v][i].first].key = new_key ;
					h.insert(vertices[g.graph[v][i].first]);
				}
				else if(vertices[g.graph[v][i].first].key > new_key) //false stands for element in heap
				{
					h.remove(g.graph[v][i].first);
					vertices[g.graph[v][i].first].key = new_key ;
					h.insert(vertices[g.graph[v][i].first]);
				}
			}
		}
		//h.printheap();
		extracted = h.extractmin();
		mincost += extracted.key ;
		vertices[extracted.id].set = true ;
		//cout << "edge " << extracted.id << " -> " << extracted.key << endl ;
		v = extracted.id; 
	}

	cout << mincost << endl ;
	return mincost;
}

int main()
{
	int n,e,u,v,w;
	cin >> n >> e ;
	Graph g(n); 
 
    while(e--)	
    {
        cin >> u >> v >> w ; 
       	g.addEgde(u-1, v-1, w);
    }
    //g.printAL();

    vector<signed long long int> sol(n); 
    for(int i = 0 ; i < n ; i++)
    	sol[i] = prim(g,i);
    sort(sol.begin(),sol.end());
    cout << "Final " << sol[0] << endl ;
}