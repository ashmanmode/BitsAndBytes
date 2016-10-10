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

int main()
{
	ull test;
	cin >> test;
	fr(t,0,test)
	{
		string s;
		cin >> s ;
		int alpha[26];
		fr(i,0,26)
			alpha[i] = 0 ;
		fr(i,0,s.length())
			alpha[(int)(s[i]-'A')]++ ;

		int numbers[10];
		fr(i,0,10)
			numbers[i] = 0 ;

		//Detecting 0
		numbers[0] = alpha[(int)('Z'-'A')] ;
		alpha[(int)('E'-'A')] -= numbers[0];
		alpha[(int)('R'-'A')] -= numbers[0];
		alpha[(int)('O'-'A')] -= numbers[0];

		//Detecting 2
		numbers[2] = alpha[(int)('W'-'A')] ;
		alpha[(int)('T'-'A')] -= numbers[2];
		alpha[(int)('O'-'A')] -= numbers[2];

		//Detecting 4
		numbers[4] = alpha[(int)('U'-'A')] ;
		alpha[(int)('F'-'A')] -= numbers[4];
		alpha[(int)('R'-'A')] -= numbers[4];
		alpha[(int)('O'-'A')] -= numbers[4];

		//Detecting 4
		numbers[6] = alpha[(int)('X'-'A')] ;
		alpha[(int)('I'-'A')] -= numbers[6];
		alpha[(int)('S'-'A')] -= numbers[6];

		//Detecting 4
		numbers[8] = alpha[(int)('G'-'A')] ;
		alpha[(int)('E'-'A')] -= numbers[8];
		alpha[(int)('I'-'A')] -= numbers[8];
		alpha[(int)('H'-'A')] -= numbers[8];
		alpha[(int)('T'-'A')] -= numbers[8];

		//Detecting 1
		numbers[1] = alpha[(int)('O'-'A')] ;
		alpha[(int)('N'-'A')] -= numbers[1];
		alpha[(int)('E'-'A')] -= numbers[1];

		//Detecting 1
		numbers[3] = alpha[(int)('H'-'A')] ;
		alpha[(int)('T'-'A')] -= numbers[3];
		alpha[(int)('R'-'A')] -= numbers[3];
		alpha[(int)('E'-'A')] -= numbers[3];
		alpha[(int)('E'-'A')] -= numbers[3];

		//Detecting 1
		numbers[5] = alpha[(int)('F'-'A')] ;
		alpha[(int)('I'-'A')] -= numbers[5];
		alpha[(int)('V'-'A')] -= numbers[5];
		alpha[(int)('E'-'A')] -= numbers[5];

		//Detecting 1
		numbers[7] = alpha[(int)('S'-'A')] ;
		alpha[(int)('V'-'A')] -= numbers[7];
		alpha[(int)('E'-'A')] -= numbers[7];
		alpha[(int)('N'-'A')] -= numbers[7];
		alpha[(int)('E'-'A')] -= numbers[7];

		//Detecting 9
		numbers[9] = alpha[(int)('I'-'A')] ;

		cout << "Case #" << t+1 << ": " ;
		fr(i,0,10)
		{
			if(numbers[i])
			{
				fr(j,0,numbers[i])
					cout << i ;
			}
		}
		cout << endl ;
	}
	return 0;
}