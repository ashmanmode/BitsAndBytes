//dijkstra's shortest path algorithm
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

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

void dijkstra(Graph g,int v)
{
	vertHeap vertices[g.size];  //for keeping keys and the info abt set in which they are X or V-X
	for(int i = 0 ; i < g.size ; i++ )
	{
		vertices[i].id = i ;
		vertices[i].key = -1 ;
		vertices[i].set = false;
	}
	vertices[v].set = true;
	vertices[v].key = 0;
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
	ofstream out("output.txt");
	for(int i = 0 ; i < g.size ; i++ )
		out << vertices[i].key << endl ; 
}

int main()
{
	Graph g(200);
	ifstream file("dijkstraData.txt");
    int x,w,current;
    string str;
    while(getline(file,str))
    {
        istringstream ss(str);
        ss >> current ;
        while(ss >> x >> w)
            g.addEgde(current-1, x-1, w);
    }
    dijkstra(g,0);
}