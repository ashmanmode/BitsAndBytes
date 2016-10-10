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
#define vectin(a,n)
typedef unsigned long long int ull;

int main()
{
	int n,a,b;
	 cin >> n ;
	 vector< pair<int,int> > possum ;
	 vector< pair<int,int> > negsum ;
	 fr(i,0,n)
	 {
	 	cin >> a >> b ; 
	 	if (a > 0)
	 		possum.pb(mp(a,b));
	 	else
	 		negsum.pb(mp(-1*a,b));
	 }
	 if(possum.size() > 0)
	 {
		 sort(possum.begin(),possum.end());
		 fr(i,1,possum.size())
		 	possum[i].S = possum[i-1].S + possum[i].S ;
	 }
	 if(negsum.size() > 0)
	 {
		 sort(negsum.begin(),negsum.end());
		 fr(i,1,negsum.size())
		 	negsum[i].S = negsum[i-1].S + negsum[i].S ;
	 }

	 if(possum.size() > negsum.size())
	 {
	 	if(negsum.size() != 0)
	 	cout << possum[negsum.size()].S + negsum[negsum.size()-1].S << endl;
	 	else
	 		cout << possum[0].S << endl ;
	 }
	 else if (possum.size() < negsum.size())
	 {
	 	if(possum.size() != 0)
	 	cout << possum[possum.size()-1].S + negsum[possum.size()].S << endl;
	 else
	 	cout << negsum[0].S << endl;
	 }
	 else
	 	cout << possum[possum.size()-1].S + negsum[possum.size()-1].S << endl;

	return 0;
}