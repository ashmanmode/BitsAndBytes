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
ull findB(ull ,ull);
vector<ull> a ;
ull forA[10010][10010];

ull val(ull i)
{
	if(i==0)
		return 0;
	else
		return (a[i-1]*a[i-1]+45)%mod ;
}

ull findA(ull u,ull v)
{
	if(u==v)
		return a[u];
	else 
	{
		forA[u][v] = max(a[u]+findB(u+1,v),findB(u,v-1)+a[v]);
		return forA[u][v]; 
	}
}

ull findB(ull u,ull v)
{
	if(u==v)
		return 0;
	else 
	{
		if(forA[u+1][v]==-1)
			findA(u+1,v);
		if(forA[u][v-1]==-1)
			findA(u,v-1);
		return min(forA[u+1][v],forA[u][v-1]); 
	}
}

int main()
{
	ull n;
	cin >> n ;
	fr(i,0,n)
		a.pb(val(i));
	memset(forA,-1,sizeof(forA));
	cout << findA(0,n-1) << endl ;
}