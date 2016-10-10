//FB-01
#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
#define point pair<int,int>
#define pii pair<int,int>
#define pib pair<int,bool>
#define arr vector<int> 
#define vectin(a,n) fr(i,0,n) { cin >> a[i] ; }
typedef unsigned long long int ull;
const unsigned long long N =  1000006;
bitset<N+1> *bs = new bitset<N+1>();
vector<int> primes;
 
void sieve(){
    bs->set();
    (*bs)[0] = false;
    (*bs)[1] = false;
    for(int i = 2; i <= N; i++){
        if((*bs)[i]){
            for(int j = i; i * j <= N; j++){
                (*bs)[i*j] = false;
            }
            primes.push_back(i);
        }
    }
}

int getplease(int n)
{
	if(n == 1 || n == 0)
		return 0;

	int please = 0 ;
	bool brealme = false ;
	for(int j = 0 ; j < primes.size() ; j++ )
	{
		// cout << n << " " << primes[j] << endl ;
		if(n == primes[j])
		{
			please++ ;
			break;
		}
		while(n%primes[j] == 0)
		{
			please++ ;
			if(n == primes[j])
				brealme = true;
			n /= primes[j];
		}
		if(brealme)
			break;
	}
	return please ;
}

vector<int> preprocess(vector<int> a)
{
	vector<int> out ;
	vector<int> ret ;
	int max = a[0];
	for(int i = 1 ; i < a.size() ; i++ )
	{
		if(a[i] > max)
			max = a[i];
	}

	for(int i = 0 ; i < max+1 ; i++ )
		out.pb(getplease(i));

	// printvect(out,out.size());
	// cout << endl;

	int please = 0 ;
	for(int i = 0 ; i < a.size() ;i++)
	{
		please = 0 ;
		for(int j = 1 ; j <= a[i] ; j++ )
			please += out[j];
		ret.pb(please);
	}
	return ret ;
}

int main()
{
	sieve();
	int n ;
	cin >> n ;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];

	int total = 0 ;
	vector<int> prepop = preprocess(a);
	for(int i= 1 ; i < pow(2,n) ; i++ )
	{
		int please = 0 ;
		for(int j = 0 ; j < n ; j++ )
		{
			if( (i/(int)pow(2,j))%2 == 1)
				please += prepop[j];
		}
		if(please%2 == 0)
			total += please ;
	}
	cout << total << endl ;
}
