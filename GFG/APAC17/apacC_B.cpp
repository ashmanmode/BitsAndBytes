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

vector< vector<int> > getAux(vector<vector<int> > mat, int R, int C)
{
	vector< vector<int> > mmat;
	fr(i,0,R)
	{
		vector<int> tmp(C);
		mmat.pb(tmp);
	}

	fr(i,0,R)
	    mmat[i][0] = mat[i][0];
	fr(i,0,C)
	    mmat[0][i] = mat[0][i];
	
	fr(i,1,R)
	{
		fr(j,1,C)
		{
			if(mat[i][j]==1)
				mmat[i][j] = min(mmat[i][j-1], min(mmat[i-1][j], mmat[i-1][j-1])) + 1;
			else
				mmat[i][j] = 0 ;
		}
  	}
  	return mmat;
}

int main()
{
	ull test;
	cin >> test;
	fr(t,0,test)
	{	
		int r,c,k,a,b;
		cin >> r >> c >> k ;
		
		vector< vector<int> > mat;
		fr(i,0,r)
		{
			vector<int> tmp(c);
			fr(j,0,c)
				tmp[j] = 1 ;
			mat.pb(tmp);
		}

		fr(i,0,k)
		{
			cin >> a >> b ; 
			mat[a][b] = 0 ;
		}

		//Make Auxilary mat
		vector< vector<int> > mmat = getAux(mat,r,c);
		ull total = 0 ;
		fr(i,0,r)
		{
			fr(j,0,c)
				total += mmat[i][j] ; 
		}

		cout << "Case #" << t+1 << ": " << total << endl ;
	}
	return 0;
}