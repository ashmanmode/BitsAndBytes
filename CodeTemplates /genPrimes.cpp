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

ull num = 100000000;
vector<bool> primes(num,true);
vector<ull> pr;

void genPrimes()
{
	fr(i,2,sqrt(num))
	{
		if(primes[i])
		{
			ull j = i*i;
			while(j < num)
			{
				primes[j] = false;
				j = j + i ;
			}
		}
	}

	fr(i,2,num)
	{
		if(primes[i])
			pr.pb(i);
	}
}

int main()
{
	genPrimes();
	fr(i,0,pr.size())
		cout << pr[i] << " " ;
	cout << endl ;
	return 0;
}