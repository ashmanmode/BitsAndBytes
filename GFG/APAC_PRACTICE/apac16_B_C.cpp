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
ull playerB(ull,ull);

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

bool gNum(ull n)
{
	ull sum = 0 ;
	while(n!=0)
	{
		sum += n%10;
		n /= 10;
	}
	return primes[sum];
}

vector< pair<ull,ull> > getFact(ull n)
{
	vector< pair<ull,ull> > fact;
	ull i = 0 ;
	while(pr[i] < sqrt(n))
	{
		if(n%pr[i]==0)
		{
			ull powCount = 0 ;
			//cout << "Divisible by " << pr[i] << endl;
			while(n%pr[i]==0)
			{
				//cout << "count " << n << endl ;
				powCount++;
				n /= pr[i];
			}
			fact.pb(mp(pr[i],powCount));
		}
		i++ ;
	}
	if(n != 1)
		fact.pb(mp(n,1));
	return fact;
}

ull playerA(ull chances,ull n)
{
	// cout << "Player A turn " << n << " : " << chances << endl;
	if(gNum(n))
		return 1+chances;

	//Finding all prime factors of number n
	vector< pair<ull,ull> > fact = getFact(n);

	// fr(i,0,fact.size())
	// 	cout << fact[i].F << " => " << fact[i].S << endl ;

	if(fact.size()==1)
		return playerB(1+chances,1);
	fr(i,0,fact.size())
	{
		ull num = n/(ull)pow(fact[i].F,fact[i].S);
		ull newChances = playerB(1+chances,num);
		// cout << "newChances " << newChances << endl ;
		if( newChances%2==0 )
		{
			// cout << " found suitalble " << newChances << endl ;
			return newChances;
		}
	}
	return -1;
}


ull playerB(ull chances,ull n)
{
	// cout << "Player B turn " << n << " : " << chances << endl;

	if(gNum(n))
		return 1+chances;

	//Finding all prime factors of number n
	vector< pair<ull,ull> > fact = getFact(n);

	// fr(i,0,fact.size())
	// 	cout << fact[i].F << " => " << fact[i].S << endl ;
		
	if(fact.size()==1)
		return playerA(1+chances,1);
	fr(i,0,fact.size())
	{
		ull num = n/(ull)pow(fact[i].F,fact[i].S);
		ull newChances = playerA(1+chances,num);
		if( newChances%2==0 )
			return newChances;
	}
}

int main()
{
	ull test;
	cin >> test;
	genPrimes();
	fr(t,0,test)
	{
		ull n;
		cin >> n ; 
		ull resp = playerA(0,n); 
		cout << "Case #" << t+1 << ": " ;
		if(resp==-1 || resp%2==1)
			cout << "Seymour" << endl;
		else
			cout << "Laurence" << endl ;
	}
	return 0;
}