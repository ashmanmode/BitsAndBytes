//BFS with addege operation
//This type of datastructure for graph is not useful in mincut beacause in there we change the graph in every iteration by removing a node, if we do same here we would need to rename all the nodes and its list.
#include <iostream>
#include <vector>
using namespace std;

class Graph
{
public:
	Graph(int n);
	void printAL();    //prints adjancency list
	void addEgde(int v, int w, bool directed); //for directed edge put directed = 1 
	void BFS(int s);
	void DFS(int s);
	void TopoSort();
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

void Graph::BFS(int s)
{
	bool visited[graph.size()];
	for(int i =0; i < graph.size() ; i++ )
		visited[i] = false ;

	//queue for visiting
	vector<int> q;
	q.push_back(s);
	visited[s] = true ;
	while(q.size() != 0)
	{
		for(int i = 0 ; i < graph[q[0]].size(); i++ )
		{
			if(visited[graph[q[0]][i]] == false)
			{
				cout << graph[q[0]][i] << " " ;
				visited[graph[q[0]][i]] = true ;
				q.push_back(graph[q[0]][i]);
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
		q.push_back(k);
		visited[k] = true ;
		while(q.size() != 0)
		{
			for(i = 0 ; i < graph[q[q.size()-1]].size(); i++ )
			{
				if(visited[graph[q[q.size()-1]][i]] == false)
				{
					visited[graph[q[q.size()-1]][i]] = true ;
					q.push_back(graph[q[q.size()-1]][i]);
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
	Graph g(4);
	int edges; cin >> edges ;
	int v,w;
	for(int i = 0 ; i < edges ;i++ )
	{
		cin >> v >>w ;
		g.addEgde(v,w,1);
	}
	g.printAL();
	g.TopoSort();
	return 0;
}