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

int main()
{
	int test,a,b,c,d,s;
	cin >> test ;
	while(test--)
	{
		cin >> a >> b >> c >> d >> s ;
		int l = c-s;
		if(l>=a && l <=b)
			cout << l << endl ;
		else if(l>b)
			cout << b << endl ;
		else
			cout << "STAY IN LONDON" << endl ; 
	}
    return 0;
}