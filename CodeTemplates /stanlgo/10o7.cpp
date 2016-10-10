//Kosaraju's Strongly connected components algo
#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include <algorithm>
using namespace std;

class Graph
{
public:
	Graph(int n);
	void printAL();    //prints adjancency list
	void addEgde(int v, int w); 
	void SSC();
private:
	vector< vector<int> > graph;
	vector< vector<int> > graphrev;
};

Graph::Graph(int n)
{
	vector<int> list;
	for(int i = 0 ; i < n ; i++ )
	{
		graph.push_back(list);
		graphrev.push_back(list);
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

void Graph::addEgde(int v,int w)
{
	graph[v].push_back(w);
	graphrev[w].push_back(v);
} 

void Graph::SSC()
{
	int label = 0 ;
	pair<int,int> finishingt[graphrev.size()];
	bool visited[graphrev.size()];
	for(int i = 0; i < graphrev.size() ; i++ )
		visited[i] = false ;

	int i ; bool last ;
	vector<int> q;
	for (int k = 0 ; k < graphrev.size(); k++ )
	{
		if(visited[k] == false)
		{
			q.push_back(k);
			visited[k] = true ;
			while(q.size() != 0)
			{
				last = false ;
				for(i = 0 ; i < graphrev[q[q.size()-1]].size(); i++ )
				{
					if(visited[graphrev[q[q.size()-1]][i]] == false)
					{
						visited[graphrev[q[q.size()-1]][i]] = true ;
						q.push_back(graphrev[q[q.size()-1]][i]);
						last = true ;
						break;
					}
				}
				if( i == graphrev[q[q.size()-1]].size() && last == false)
				{
					finishingt[q[q.size()-1]].first = label++ ; 
					q.erase(q.begin() + q.size()-1 );   
				}
			}
		}
	}

	// RUN 2 --------------
	for(int i= 0  ;i < graphrev.size() ; i++ )
		finishingt[i].second = i ;
	sort(&finishingt[0],&finishingt[graphrev.size()]); 

	vector<int> ssc;
	int count;
	for(int i = 0; i < graph.size() ; i++ )
		visited[i] = false ;

	for (int k = graph.size() - 1 ; k >= 0; k-- )
	{
		int m = finishingt[k].second;
		if(visited[m] == false)
		{
			count = 1 ;
			q.push_back(m); 
			visited[m] = true ;
			while(q.size() != 0)
			{
				last = false ;
				for(i = 0 ; i < graph[q[q.size()-1]].size(); i++ )
				{
					if(visited[graph[q[q.size()-1]][i]] == false)
					{
						count++ ;
						visited[graph[q[q.size()-1]][i]] = true ;
						q.push_back(graph[q[q.size()-1]][i]);
						last = true ;
						break;
					}
				}
				if( i == graph[q[q.size()-1]].size() && last == false)
					q.erase(q.begin() + q.size()-1 );  
			}
			ssc.push_back(count);
		}
	}

	//2nd loop check
	sort(ssc.begin(),ssc.end());
	for(int i = ssc.size() -1  ;i > ssc.size()-6 ; i-- )
		cout << ssc[i] << " " ;
	cout << endl ;
}

int main()
{
	clock_t start_t = clock();
	Graph g(875714); 
	ifstream file("SCC.txt");
	int v,w;
	while(!file.eof())
	{
		file >> v >> w ;
		g.addEgde(v-1,w-1);
	}
	g.SSC();
	cout << "time " << (float)(clock() - start_t)*1000/CLOCKS_PER_SEC << " ms" << endl;
	return 0;
}