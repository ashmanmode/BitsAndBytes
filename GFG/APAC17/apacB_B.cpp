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
		return 1;
	ull ans = power(a,b/2,k);
	if(b%2==0)
		return (ans*ans)%k;
	else
		return (((ans*ans)%k)*a)%k;
	return ans ;
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

		vector<ull> arrA(k);
		vector<ull> arrB(k);
		map<ull,ull> mapB;
		map<ull,ull> mapBpartial;
		fr(i,0,k)
		{
			arrA[i] = power(i+1,a,k);
			ull val = power(i+1,b,k);
			arrB[i] = val ;
			if(mapB.find(val) == mapB.end())
				mapB[val] = 1 ;
			else
				mapB[val]++;

			if(i < remains) //check this
			{
				if(mapBpartial.find(val) == mapBpartial.end())
					mapBpartial[val] = 1 ;
				else
					mapBpartial[val]++;
			}
		}

		// fr(i,0,k)
		// 	cout << arrA[i] << " " ; 
		// cout << endl ;
		// cout << "Full" << endl;

		// for (std::map<ull,ull>::iterator it=mapB.begin(); it!=mapB.end(); ++it)
  //   		std::cout << it->first << " => " << it->second << '\n';
  //   	cout << "Partial" << endl ;

  //   	for (std::map<ull,ull>::iterator it=mapBpartial.begin(); it!=mapBpartial.end(); ++it)
  //   		std::cout << it->first << " => " << it->second << '\n';

    	//Now finding
    	ull total = 0 ; 
    	ull totaltmp = 0 ; 
    	fr(i,0,k)
    	{
    		ull bval = (k-arrA[i])%k;
    		ull bvaltmp = k-arrA[i];
    		if(i<remains)
    			total = total + ((divs+1)*((divs*mapB[bval])%mod + mapBpartial[bval]))%mod;
    		else
    			total = total + (divs*( (divs*mapB[bval])%mod +mapBpartial[bval]))%mod;
    		if(i<remains)
    			total = total + ((divs+1)*((divs*mapB[bvaltmp])%mod + mapBpartial[bvaltmp]))%mod;
    		else
    			total = total + (divs*( (divs*mapB[bvaltmp])%mod +mapBpartial[bvaltmp]))%mod;
    	}
    	cout << total << endl ;
    	total = max(total,totaltmp);

    	//Subtracting part
    	fr(i,0,k)
    	{
    		if( (arrB[i]+arrA[i])%k==0 )
    		{
    			if(i < remains)
    				total = (total-divs-1)%mod;
    			else
    				total = (total-divs)%mod;
    		}
    	}

		cout << "Case #" << t+1 << ": " <<  total%mod << endl ;
	}
	return 0;
}