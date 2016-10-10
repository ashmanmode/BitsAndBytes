//FB-01
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
	freopen("fb_input.txt","r",stdin);
	freopen("fb_output.txt","w",stdout);	
	int test,all;
	cin >> test ;
	all = test ;
	while(test--)
	{
		int n;
		cin >> n ; 
		vector<int> a(n);
		fr(i,0,n) cin >> a[i] ;

		// fr(i,0,n) cout << a[i] << " " ;
		// cout << endl ;

		// fr(i,0,n-1) cout << a[i+1] - a[i] << " " ;
		// cout << endl ;

		//Solution
		int tuple_count = 1 ;
		int extra_count = 0 ;
		fr(i,0,n-1)
		{
			// cout << i << " tuple_count " << tuple_count << endl ; 
			// cout << i << " extra_count " << extra_count << endl ; 
			if(tuple_count >= 4)
				tuple_count = tuple_count%4 ;

			if(tuple_count == 0)
			{
				tuple_count++ ;
				continue;
			}
			
			if(a[i+1] - a[i] <= 0)
			{
				extra_count += 4 - tuple_count ;
				tuple_count = 5 ;
			}
			else if( a[i+1] - a[i] <= 10 )
				tuple_count++;
			else 
			{
				extra_count +=  min( 4 - tuple_count , (a[i+1] - a[i] - 1)/10 ) ; 
				tuple_count += min( 4 - tuple_count , (a[i+1] - a[i] - 1)/10 )  + 1 ;
			}			
		}

		// cout << n-1 << " tuple_count " << tuple_count << endl ; 
		// cout << n-1 << " extra_count " << extra_count << endl ; 
		if(tuple_count%4 != 0)
			extra_count += 4 - (tuple_count%4) ;
		cout << "Case #" << all - test << ": " << extra_count << endl;
	}
}
