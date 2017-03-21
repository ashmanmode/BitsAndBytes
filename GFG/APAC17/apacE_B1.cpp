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

ull solve(ull n,ull a,ull start,ull end,ull prev)
{
	ull mid = (start+end)/2;
	ull vala = (ull)pow(start,a) - n*start + n - 1 ;
	ull valb = (ull)pow(end,a) - n*end + n - 1 ;
	if(vala==0)
		return start;
	if(valb==0)
		return end;
	if(mid==n||mid==2)
		return -1;
	ull val = (ull)pow(mid,a) - n*mid + n - 1 ;
	// cout << n << " "  << a << " = " << mid << " "<< val << endl ;
	if(val == prev)
		return -1;
	prev = val;
	if(val==0)
		return mid;
	else if(val>0)
		return solve(n,a,start,mid,prev);
	else
		return solve(n,a,mid+1,end,prev);
}

ull get(ull n)
{
	// cout << log(n)/log(2)+1 << endl ;
	for( int a = (int)(log(n)/log(2))+1 ; a > 1 ; a-- )
	{
		if(solve(n,a,2,n,-INT_MAX)!=-1)
		{
			return solve(n,a,2,n,-INT_MAX);
		}
	}
	return n-1;
}

int main()
{
	ull test;
	cin >> test;
	fr(t,0,test)
	{	
		ull n;
		cin >> n;

		cout << "Case #" << t+1 << ": "  ;
		cout << get(n) << endl;
	}
	return 0;
}