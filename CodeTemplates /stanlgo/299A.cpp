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

string prinr(int n)
{
	if(n==0)
		return "zero" ;
	else if(n == 1)
		return "one" ;
	else if (n==2)
		return "two" ;
	else if (n==3)
		return "three" ;
	else if (n==4)
		return "four" ;
	else if (n==5)
		return "five" ;
	else if (n==6)
		return "six" ;
	else if (n==7)
		return "seven" ;
	else if (n==8)
		return "eight" ;
	else if (n==9)
		return "nine" ;
	else if (n==10)
		return "ten" ;
	else if (n==11)
		return "eleven" ;
	else if (n==12)
		return "twelve" ;
	else if (n==13)
		return "thirteen" ;
	else if (n==14)
		return "fourteen" ;
	else if (n==15)
		return "fifteen" ;
	else if (n==16)
		return "sixteen" ;
	else if (n==17)
		return "seventeen" ;
	else if (n==18)
		return "eighteen" ;
	else if (n==19)
		return "nineteen" ;
	else if (n==20)
		return "twenty" ;
	else if (n==30)
		return "thirty" ;
	else if (n==40)
		return "forty" ;
	else if (n==50)
		return "fifty" ;
	else if (n==60)
		return "sixty" ;
	else if (n==70)
		return "seventy" ;
	else if (n==80)
		return "eighty" ;
	else if (n==90)
		return "ninety" ;
	else
		return prinr( (n/10)*10 ) + "-" + prinr(n%10) ;
}

int main()
{
	int n ;
	cin >> n ;
	cout << prinr(n) << endl;
}