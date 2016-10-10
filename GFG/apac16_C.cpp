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

double a,b,c;
ull k;
map<ull,double> compute(map<ull,double> mymap)
{
	map<ull,double> finalmap;
	for (std::map<ull,double>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	{
    	if(finalmap.find(it->first&k)==finalmap.end())
    		finalmap[it->first&k] = mymap[it->first]*(a/100);
    	else
    		finalmap[it->first&k] += mymap[it->first]*(a/100);

    	if(finalmap.find(it->first|k)==finalmap.end())
    		finalmap[it->first|k] = mymap[it->first]*(b/100);
    	else
    		finalmap[it->first|k] += mymap[it->first]*(b/100);

    	if(finalmap.find(it->first^k)==finalmap.end())
    		finalmap[it->first^k] = mymap[it->first]*(c/100);
    	else
    		finalmap[it->first^k] += mymap[it->first]*(c/100);
	}
    return finalmap;
}

int main()
{
	ull test,n;
	cin >> test;
	fr(t,0,test)
	{
		ull n,x;
		cin >> n >> x >> k >> a >> b >> c ;
		map<ull,double> temp;
		temp[x] = 1 ;
		fr(i,0,n)
			temp = compute(temp); 
		//cout << "finale" << endl ;
		double answer = 0 ;
		int count = 0 ;
		for (std::map<ull,double>::iterator it=temp.begin(); it!=temp.end(); ++it)
		{
	    	//std::cout << it->first << " => " << it->second << '\n';
	    	count++;
	    	answer += it->first*it->second;
	    }
		cout << "Case #" << t+1 << ": " << fixed << std::setprecision(15) << answer << endl;
		cout << count << endl ;

	}
	return 0;
}