#include <bits/stdc++.h>
using namespace std;

int n1,n2,n;
set<int> dont;
vector<int> sol;
int minn ;

void solve()
{
    cout << "here" << endl ;
    set<int>::iterator it = dont.begin();
    while(it!=dont.end())
    {
        cout << "In loop " << *it << endl ;
        if(minn<*it)
            break;
        if(*it==minn)
        {
            minn++;
            dont.erase(it);
        }
    }
    
    sol.push_back(minn);
    
    if(sol.size()==1)
    {
        int a = n1*sol[0] - n2*sol[0];
        int b = n1*sol[0] - n2*sol[0];
        if(a>minn)
            dont.insert(a);
        if(b>minn)
            dont.insert(b);
    }
        
    //Update Dont
    for(int i=0;i<sol.size()-1;i++)
    {
        int a = n1*sol[sol.size()-1] - n2*sol[i];
        int b = n1*sol[i] - n2*sol[sol.size()-1];
        if(a>minn)
            dont.insert(a);
        if(b>minn)
            dont.insert(b);
    }
    
    minn++ ;
}

int main() 
{
	int t;
	cin >> t ;
	while(t--)
	{
	    cin >> n1 >> n2 >> n ;
	    minn = 1 ;
	    for(int i=0;i<n;i++)
	        solve();
	    
	    for(int i=0;i<n;i++)
	        cout << sol[i] << " ";
	   cout << endl ;
	}
	return 0;
}