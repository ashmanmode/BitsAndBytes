#include <iostream>
#include <vector>
using namespace std;

class Graph
{
public:
	Graph(int n);
	void printAL();    //prints adjancency list
	void addEgde(int v, int w, bool directed); //for directed edge put directed = 1 
	int BFS(int s);
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

bool visited[graph.size()];
for(int i =0; i < graph.size() ; i++ )
		visited[i] = false ;

int Graph::BFS(int s)
{
	int count = 0 ;

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
				count++;
				visited[graph[q[0]][i]] = true ;
				q.push_back(graph[q[0]][i]);
			}
		}
		q.erase(q.begin());
	}
	return count;
}

int main()
{
	int n,k,x,y;
	cin >> n ;
	Graph g(n);
	do{
		cin >> x >> y ;
		g.addEgde(x,y,0);
	}while(x);
	vector<int> s;
	for(int i = 0 ; i < n ; i++ )
		s.push_back(g.BFS(i));
	return 0;
}