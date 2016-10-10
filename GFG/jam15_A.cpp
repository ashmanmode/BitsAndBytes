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

bool nums[10];

void mark(ull a)
{
	while(a)
	{
		nums[a%10] = true;
		a /= 10 ;
	}
}

bool check()
{
	fr(i,0,10)
	{
		if(nums[i]==false)
			return false;
	}
	return true;
}

int main()
{
	ull test,n;
	cin >> test;
	fr(t,0,test)
	{
		cin >> n ; 
		if(n==0)
		{
			cout << "Case #" << t+1 << ": " << "INSOMNIA" << endl;
			continue;
		}

		ull mult = 1;
		fr(i,0,10)
			nums[i] = false;

		while(1)
		{
			mark(n*mult);
			if(check())
				break;
			else
				mult++;
		}
		cout << "Case #" << t+1 << ": " << n*mult << endl;
	}
	return 0;
}