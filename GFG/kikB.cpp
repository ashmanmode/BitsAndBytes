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

bool isStar(string a)
{
	for(int i=0;i<a.length();i++)
		if(a[i]!='*')
			return false;
	return true;
}

int main()
{
	ull test,n;
	cin >> test;
	fr(t,0,test)
	{
		string a,b;
		cin >> a >> b ;
		bool pos = true;
		if(isStar(a) || isStar(b))
			pos = true;
		else
		{
			int i=0;
			int j=0;
			int starCount = -1 ;
			int StarIn = -1;
			while(i<=a.length()&&j<=b.length())
			{
				// cout << a[i] << " " << b[j] << " " << starCount << endl ;
				if(a[i]=='*')
				{
					i++;
					starCount = 0;
					StarIn = 1;
				}
				else if(b[j]=='*')
				{
					j++;
					starCount = 0 ;
					StarIn = 2;
				}
				else if(a[i]==b[i] && starCount == -1)
				{
					i++;
					j++;
				}
				else if(starCount!=-1 && starCount <6)
				{
					// cout << "A " << a[i] << " " << b[j] << " " << starCount << endl ;
					if(a[i]!=b[j])
					{
						if(StarIn==1)
							j++;
						else
							i++;
						starCount++;
					}
					else
					{
						i++; j++;
						starCount = -1 ;
					}
				}
				else 
				{
					pos = false;
					break;
				}
			}
		}
		if(pos)
			cout << "Case #" << t+1 << ": " << "TRUE" << endl;
		else
			cout << "Case #" << t+1 << ": " << "FALSE" << endl;
	}
	return 0;
}