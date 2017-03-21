#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;

vector<bool> solve(int n,int m, int k)
{
	vector<bool> a;
	for(int i=0;i<n;i++)
		a.push_back(0);
	for(int i=0;i<m;i++)
		a.push_back(1);
	while(k--)
		next_permutation(a.begin(),a.end());
	return a;
}

ull getfact(int n,int m)
{
	double ans = 1 ;
	if(n<m)
		swap(n,m);

	for(int i=0;i<m;i++)
	{
		ans *= (n+m-i) ;
		ans /= (m-i) ;
		if(ans > INT_MAX)
			return INT_MAX;	
	}	
	return (ull)ans;
}

string fun(int n,int m,ull k)
{
	// cout << n << " " << m << " " << k << endl ;
	if(n==0)
	{
		string a(m,'1');
		return a;
	}
	if(m==0)
	{
		string b(n,'0');
		return b;
	}

	ull count = getfact(n-1,m);
	if(k<=count)
		return "0"+fun(n-1,m,k);
	else
		return "1"+fun(n,m-1,k-count);
}

int main()
{
	int n,m;
	ull k;
	cin >> n >> m  >> k; 

	clock_t t = clock();

	vector<bool> sol = solve(n,m,--k);
	// for(int i=0;i<n+m;i++)
	// 	cout << sol[i] ;
	// cout << endl ;
	cout << "Time " << clock() -t << endl ;
	clock_t q = clock();

	string out = fun(n,m,++k);
	// cout << out << endl ;
	cout << "Time " << clock() -q << endl ;

	bool same = true;
	for(int i=0;i<n+m;i++)
	{
		if(out[i]=='1' && !sol[i])
			same = false;
		if(out[i]=='0' && sol[i])
			same = false;
	}
	if(same)
		cout << "Sahi re " << endl ;
	else
		cout << "EROOR" << endl ;
	return 0;
}