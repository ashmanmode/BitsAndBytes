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
typedef signed long long int ull;

ull get(ull first,ull curr,ull num)
{
	// cout << first << " " << curr << "  " << num << endl;
	if(num==0)
		return 1;
	else if(num<0)
		return 0;

	ull ans = 0 ;
	if(first >= curr)
		ans += get(first,first,num-first);
	if(first+1>=curr)
		ans += get(first,first+1,num-first-1);
	if(first+2>=curr)
		ans += get(first,first+2,num-first-2);
	return ans;
}

int main()
{
	ull test;
	cin >> test;
	fr(t,0,test)
	{	
		ull n,d;
		cin >> n >> d;

		ull total = 0 ;
		for(int i=1;i<=n;i++)
		{
			if(i%d==0)
			{
				total += get(i,i,n-i);
			}
		}

		cout << "Case #" << t+1 << ": "  ;
		cout << total << endl;
	}
	return 0;
}