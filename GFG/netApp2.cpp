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

ull getNum(ull p,ull q)
{
	ull i = 1 ;
	while( (mod*i+p)%q != 0 )
	{
		// cout << i << endl ;
		i++;
		if(i>1000000)
			break;
	}
	return (mod*i+p)/q ;
}

ull getsol(ull p, ull q)
{
	ull ans = 1 ;
	for(ull i = p; i >0 ; i--)
	{
		if(i==q)
			break;
		ans *= i ;
	}
	return ans;
}

int main()
{
	ull test;
	cin >> test;
	fr(t,0,test)
	{
		int n,m;
		cin >> n >> m ; 

		if(m>n) //Prob = 1 
		{
			cout << 1 << endl;
			continue;
		}

		ull p = getsol(n,n-m);
		ull q = getsol(n+m-1,n-1);
		// cout << p << " " << q << endl ;
		p /= n;
		q /= n;
		p = q-p;

		// cout << p << " " << q << endl ;
		if(p==0)
			p = 9;
		if(q==0)
			q== 10; 	

		cout << getNum(p,q) << endl;
	}
	return 0;
}