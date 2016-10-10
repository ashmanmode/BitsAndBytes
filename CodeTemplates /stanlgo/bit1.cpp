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
	ull a;
	sl(a);
	if(a == 1)
		cout << 1 << endl;
	else if(a==2)
		cout << 6 << endl;
	else
	{
		ull ans = ((a%mod)*( (a+1)%mod ))%mod ;
		//a -= 2 ;
		ull b = a-2;
		ull p = 1;
		ull a1 = 2;
	
		while (b > 0) 
		{	
     		if (b%2==1) 
     		{
         		p *= a1;
         		p = p%mod;
     		}
    		b /= 2;
     		a1 = (a1 * a1)% mod;
		}
		p = p%mod ;
		ans = ( p*ans )%mod;
		cout << ans << endl ;
	}
}

