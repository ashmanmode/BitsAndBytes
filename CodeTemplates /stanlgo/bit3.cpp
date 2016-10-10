#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define maxsiz 1000000
#define F first
#define S second
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%llu",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%llu",a)
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
typedef unsigned long long int ull;

int main()
{
	int n,m ;
	string a,b; 
	int count = 1 ;
	cin >> n >> a >> m >> b;

	int j = 0 ;
	int i = 0 ;
	bool no = true;
	while(1)
	{
		if(a[j] == b[i])
		{
			i++ ;
			j++ ;
			no = false;
		}
		else
			j++ ;

		if(i == m)
			break;
	
		if(j == n)
		{
			if(no) 
			{
				cout << -1 << endl ;
				return 0;
			}
			count++;
			j = 0 ;
			no = true ;
		}
	}
	
	cout << count << endl ;
	return 0 ;
}