#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
#define point pair<int,int>
#define pii pair<int,int>
#define pib pair<int,bool>
#define arr vector<int> 
#define vectin(a,n) fr(i,0,n) { cin >> a[i] ; }
typedef unsigned long long int ull;

int main()
{
	int n,m;
	cin >> n >> m ;
	string str;
	cin >> str;
	cout << str <<  endl;

	vector<int> pos(n+1);
	pos[0] = -1 ;
	int count = 0 ;
	int j = 1;
	while(j < n)
	{
		cout << j << " "  << pos[j] << endl;
		if (pos[j] >= 0 && str[pos[j]] < str[j])
        {
        	cout << "Deleting char at " << pos[j] << endl;
            str[pos[j]] = '-';
            count++;
            pos[j] = pos[pos[j]];
        }
        else
        {
            pos[j + 1] = j;
            j++;
        }
        if (count == m)
        	break;
	}
	j = n-1;

    //If all m elemertns are not deleted just delete them from back
	while (count < m)
    {
        if (str[j] != '-')
        {
            str[j] = '-';
            count++;
        }
        j--;
    }

    string ans = "";
    fr(i,0,n)
    {
    	if(str[i]!='-')
    		ans += str[i];
    }

	cout << ans << endl ;
}