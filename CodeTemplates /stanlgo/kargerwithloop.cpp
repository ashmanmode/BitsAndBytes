//Graph implementation and karger's min cut algo.
//using for loop for multiple invocations
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector< vector<int> > graph)
{
	cout << "printing ... " << endl ;
	for(int i = 0 ; i < graph.size() ;i++ )
	{
		for(int j = 0 ; j < graph[i].size() ; j++ )
			cout << graph[i][j] << " " ;
		cout << endl ;
	}
}

int b_search(vector< vector<int> > vect,int first,int last,int s)
{
	int index;
	if(first > last)
		index = -1 ;
	else
	{
		int mid = (first+last)/2;
		if(vect[mid][0] == s)
			index = mid;
		else if(s < vect[mid][0])
			index = b_search(vect,first,mid,s);
		else	
			index = b_search(vect,mid+1,last,s);			
	}
	return index;
}

int mincut()
{
	ifstream file("input.txt");
	vector< vector<int> > graph;
	vector<int> list; 
	int x ;
	string str;
	while(getline(file,str))
	{
		istringstream ss(str);
		while(ss >> x)
			list.push_back(x);
		graph.push_back(list);
		list.clear();
	}

	while(graph.size() > 2)
	{ 
		srand(time(NULL));
		int r_vertex = rand() % graph.size() ; 
		int r_edge = rand() % (graph[r_vertex].size()-1) + 1 ; 
		
		//appending edge vector into vertex
		int index_edge = b_search(graph,0,graph.size(),graph[r_vertex][r_edge]) ; 
		for(int i = 1 ; i < graph[index_edge].size() ; i++ )
			graph[r_vertex].push_back(graph[index_edge][i]);
		
		//replacing edge with new vertex value for all connections
		for(int i = 1 ; i < graph[index_edge].size() ; i++)
		{
			int index_replace = b_search(graph,0,graph.size(),graph[index_edge][i]) ;
			for(int j = 1 ; j < graph[index_replace].size() ; j++ )
			{
				if(graph[index_replace][j] == graph[index_edge][0])
					graph[index_replace][j] = graph[r_vertex][0];
			}
		}

		//removing self loops in r_vertex
		for(int i = 1; i < graph[r_vertex].size() ; i++ )
		{
			if(graph[r_vertex][i] == graph[r_vertex][0])
			{
				graph[r_vertex].erase(graph[r_vertex].begin()+i);
				i-- ;
			}
		}

		//removing r_edge node
		graph.erase(graph.begin() + index_edge);
	}

	//posting result
	if(graph[0].size() == graph[1].size())
	{
		cout << "Minimun cut " << graph[1].size() - 1 << endl ; 
		return graph[0].size() -1 ;
	}
	else
	{
		cout << "Error has occured !! " << endl;
		return -1 ;
	}
}

int main()
{
	int invocations =  100 ;
	vector<int> data;
	for(int i = 0 ; i < invocations ; i++ )
		data.push_back(mincut());
	sort(data.begin(),data.end());
	cout << "Result " << data[0] << endl ;
	return 0 ;
}