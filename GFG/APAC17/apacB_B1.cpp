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

ull power(ull a,ull b,ull k)
{
	if(b==0)
		return 1%k;
	ull ans = power(a,b/2,k);
	if(b%2==0)
		return (ans*ans)%k;
	else
		return (((ans*ans)%k)*a)%k;
	return ans ;
}

ull getNum(ull i,ull k,ull divs)
{
	if(i<k)
		return (1+divs)%mod;
	return divs;
}

int main()
{
	ull test;
	cin >> test;
	fr(t,0,test)
	{	
		ull a,b,n,k;
		cin >> a >> b >> n >> k ;
		ull divs = floor(n/k);
		ull remains = n - divs*k ; 
		// cout << "Divs " << divs << " rtem " << remains << endl ;

		map<ull,ull> mapA;
		map<ull,ull> mapB;
		ull ansNeg = 0 ;
		fr(i,0,k)
		{
			ull valA = power(i+1,a,k);
			ull valB = power(i+1,b,k);

			if(mapA.find(valA) == mapA.end())
				mapA[valA] = getNum(i,remains,divs) ;
			else
				mapA[valA] = (mapA[valA] + getNum(i,remains,divs))%mod;
			
			if(mapB.find(valB) == mapB.end())
				mapB[valB] = getNum(i,remains,divs) ;
			else
				mapB[valB] = (mapB[valB] + getNum(i,remains,divs))%mod;

			//REmove i==j cases
			if( (valA+valB)%k == 0)
				ansNeg = (ansNeg + mod - getNum(i,remains,divs))%mod;
		}

		// for (std::map<ull,ull>::iterator it=mapA.begin(); it!=mapA.end(); ++it)
		// 	std::cout << it->first << " => " << it->second << '\n';
		// cout << endl;
		// for (std::map<ull,ull>::iterator it=mapB.begin(); it!=mapB.end(); ++it)
		// 	std::cout << it->first << " => " << it->second << '\n';

		ull ans = 0 ;
		for (std::map<ull,ull>::iterator it=mapA.begin(); it!=mapA.end(); ++it)
		{
			ull find = (k-it->first)%k ;
			ans = (ans+(it->second*mapB[find])%mod)%mod ;
		}
		cout << "Case #" << t+1 << ": " << (ans + ansNeg)%mod << endl;
    	
	}
	return 0;
}