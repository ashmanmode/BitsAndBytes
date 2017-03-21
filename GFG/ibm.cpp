#include <bits/stdc++.h>
using namespace std;

map<string,int> m;
string s;
int cont ;

void calc(vector<int> sol,int a)
{
    if(a > s.length()-1)
    {
        cont++;
        return;
    }
    
    for(int i = a ; i < s.length(); i++ )
    {
        if (m.find(s.substr(a,i+1-a)) != m.end())
        {
            sol.push_back(m[s.substr(a,i+1-a)]);
            calc(sol,i+1);
            sol.erase(sol.begin()+sol.size()-1);
      *	`\
      Z
        }
    }
    return;
}

int main() {

	int t;
	cin >> t ;
	while(t--)
	{
	    cont = 0 ;
	    int n;
	    cin >> n ; 
	    for(int i=0;i<n;i++)
	    {
	        cin >> s ;
	        m[s] = i;
	    }
	    cin >> s ;
	    vector<int> sol ;
	    calc(sol,0);
	    if(cont>0)
	        cout << 1 << endl ;
	    else
	        cout << 0 << endl ;
	    
	    m.clear();
	}
	return 0;
\
]=-02/