#include <bits/stdc++.h>
using namespace std;

#define S second 
#define F first 

pair<int,int> getNew(pair<int,int> a,int n,int m,int r)
{
	// cout << a.F << " " << a.S << " " << n << " " << m <<  " " << r << endl ;
	if(r==0)
		return a;

	r = r%(2*n+2*m-4);
	
	//If row
	if(a.S==0 && a.F != n-1)
	{
		// cout << "left" << endl;
		int change = a.F;
		a.F = min(a.F+r,n-1);
		return getNew(a,n,m,r-(a.F-change));
	}
	else if(a.F==n-1 && a.S!=m-1)
	{
		// cout << "down" << endl;
		int change = a.S;
		a.S = min(a.S+r,m-1);
		return getNew(a,n,m,r-(a.S-change));
	}
	else if(a.S==m-1 && a.F != 0)
	{
		// cout << "right" << endl;
		int change = a.F;
		a.F = max(a.F-r,0);
		return getNew(a,n,m,r-(-a.F+change));
	}
	else
	{
		// cout << "top" << endl;
		int change = a.S;
		a.S = max(a.S-r,0);
		return getNew(a,n,m,r-(-a.S+change));
	}
}

int getrowcols(pair<int,int> a,int n,int m)
{
	int x = min(min(a.F,n-1-a.F),min(a.S,m-1-a.S));
	return x;
}

int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	vector< vector<int> > mat;
	vector< vector<int> > rot;
	for(int i=0;i<n;i++)
	{
		vector<int> temp(m);
		for(int j=0;j<m;j++)
			cin >> temp[j];
		mat.push_back(temp);
		rot.push_back(temp);
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x = getrowcols(make_pair(i,j),n,m);
			// cout << x << " " << x << " | " ;
			pair<int,int> dst = getNew(make_pair(i-x,j-x),n-2*x,m-2*x,k);
			// cout << i-x << " " << j-x << " " << " -> " << dst.F << " " << dst.S << " | ";
			rot[dst.F+x][dst.S+x] = mat[i][j];
		}
		// cout << endl ;
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout << rot[i][j] << " ";
		cout << endl ;
	}

	return 0;
}