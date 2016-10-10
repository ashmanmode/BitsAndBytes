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


//#define cout fout
int main()
{
	int T;
	string s;
	int k,ans,temp;
	cin>>T;
	while(T--)
	{
		ans = 0;
		cin >> s >> k;
		vector<int> a(26);

		for(int i=0;i<s.length();i++){
			a[s[i]-'a']++;
		}
		
		sort(a.begin(),a.end());

		fr(i,0,26)
		{
			if(a[i]!=0)
			{
				fr(j,i+1,26)
				{
					if(a[j]-a[i] > k)
					{
						cout << a[i] << " " << a[j] << endl;
						temp = a[j]-a[i]-k;
						a[j] -= temp;
						ans += temp;
					}
				}
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}