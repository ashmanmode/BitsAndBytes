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
typedef signed long long int sll;

vector<ull> primes;

sll change_base(sll n,sll base)
{
	sll a = 0 ;
	sll counter = 0 ;
	while(n)
	{
		if(n%2)
			a += pow(base,counter);
		n /= 2 ;
		counter++;
	}
	return a ;
}

sll check_prime(sll a)
{
	int i=0;
	while(primes[i] <= sqrt(a))
	{
		if(a%primes[i]==0)
			return primes[i];
		i++;
	}
	return -1;
}

bool SieveOfEratosthenes(int a)
{
    int i=0;
	while(primes[i] <= sqrt(a))
	{
		if(a%primes[i]==0)
			return false;
		i++;
	}
	return true;
}

void pre()
{
	primes.pb(2);
	primes.pb(3);
	primes.pb(5);
	ull n = pow(10,16)+1;
	fr(i,7,n)
	{
		if(SieveOfEratosthenes(i))
			primes.pb(i);
	}

	//Saving all the primes to file
	fr(i,0,primes.size())
		cout << primes[i] << endl;
}

void loadprimes()
{
	ull a ;
	ifstream file("allPrimes.txt");
    if(file.is_open())
    {
        for(int i = 0; i < 5761455; ++i)
        {
            file >> a;
            primes.pb(a);
        }
    }
}

int main()
{
	pre(); return 0;
	//loadprimes();
	ull test;
	cin >> test;
	fr(t,0,test)
	{
		sll n,k;
		cin >> n >> k ;

		sll num = 1+pow(2,n-1); //num in binary
		cout << "Case #" << t+1 << ": " << endl;
		fr(i,0,pow(2,n-2))
		{
			// cout << num+2*i << endl ; //num in binary
			vector<sll> divs;
			sll base_num;
			fr(j,2,11)
			{
				base_num = change_base(num+2*i,j);
				// cout << "base_num " << base_num << endl ;
				//Find divisor for every no.
				if(check_prime(base_num)==-1)
					break;
				else
					divs.pb(check_prime(base_num));
			}

			//No. is jam coin
			if(divs.size()==9)
			{
				cout << base_num << " ";
				fr(m,0,divs.size())
					cout << divs[m] << " ";
				cout << endl;
				k--;
			}
			if(k==0)
				break;
		}
	}
	return 0;
}