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
    int V;    
    list<int> *adj;    
    bool isCyclicUtil(int v, bool visited[], bool *rs);  
public:
    Graph(int V);   
    void addEdge(int v, int w);   
    bool isCyclic();    
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
}
 

bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        
        visited[v] = true;
        recStack[v] = true;
 
        
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
 
    }
    recStack[v] = false;  
    return false;
}

bool Graph::isCyclic()
{
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
}

int main()
{
	ull test;
	cin >> test;
	fr(t,0,test)
	{	
		int n;
		cin >> n ; 
		map<string,int> verts;
		vector< pair<int,int> > edges;
		int vertCount = 0 ;
		fr(i,0,n)
		{
			string exp;
			cin >> exp ;

			std::size_t pos = exp.find("=");
			string out = exp.substr(0,pos);
			if(verts.find(out)==verts.end())
			{
				verts[out] = vertCount ;
				vertCount++;
			}

			//Varibles
			std::size_t pos1 = exp.find("(");
			string var = exp.substr(pos1+1);
			string tmp = "";
			fr(j,0,var.length())
			{
				if(var[j-1] == ',' && j-1 >= 0)
					tmp = "";
				if(var[j]==',' || var[j] == ')')
				{
					//New var
					// cout << tmp << endl ;
					if(verts.find(tmp)==verts.end())
					{
						verts[tmp] = vertCount ;
						vertCount++;
					}
					//Add Edge
					edges.pb(mp(verts[tmp],verts[out]));
					tmp = "";
				}
				tmp += var[j];
			}
		}

		// for (std::map<string,int>::iterator it=verts.begin(); it!=verts.end(); ++it)
  //   		std::cout << it->first << " => " << it->second << '\n';

    	if(verts.find("")==verts.end())
    	{
    		cout << "Case #" << t+1 << ": " << "BAD" << endl ;
    		continue;
    	}

		//Make a graph now
		Graph g(vertCount);
		fr(i,0,edges.size())
		{
			// cout << "Edge " << edges[i].F << " " << edges[i].S << endl ;
			g.addEdge(edges[i].F,edges[i].S);
 		}
 		if(g.isCyclic())
        	cout << "Case #" << t+1 << ": " << "BAD" << endl ;
	    else
	        cout << "Case #" << t+1 << ": " << "GOOD" << endl ;
		
	}
	return 0;
}