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
	ull test;
	cin >> test;
	fr(t,0,test)
	{
		ull n,q ;
		cin >> n >> q;
		vector<ull> a(n);
		fr(i,0,n)
			cin >> a[i];
		fr(i,1,n)
			a[i] = a[i] + a[i-1];
		vector<ull> newA;
		fr(i,0,n)
		{
			fr(j,0,n-i)
			{
				if(j==0)
					newA.pb(a[j+i]);
				else
					newA.pb(a[j+i]-a[j-1]);
			}
		}
		sort(newA.begin(),newA.end());
		fr(i,1,newA.size())
			newA[i] = newA[i] + newA[i-1];
		ull l,r ;
		cout << "Case #" << t+1 << ": " << endl;
		fr(i,0,q)
		{	
			cin >> l >> r ;
			if(l==1)
				cout << newA[r-1] << endl;
			else
				cout << newA[r-1] - newA[l-2] << endl;
		}
	}
	return 0;
}