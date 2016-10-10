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

vector<int> getNext(int n,int s)
{
	vector<int> res(s);
	fr(i,0,s)
	{
		res[i] = n%4;
		n /= 4;
	}
	return res ;
}

vector< vector<double> > getCopy(vector< vector<int> > board,double p,double q)
{
	vector< vector<double> > mat;
	fr(i,0,board.size())
	{
		vector<double> row(board[i].size());
		fr(j,0,board[i].size())
		{
			if(board[i][j]==0)
				row[j] = q ;
			else
				row[j] = p ;
		}
		mat.pb(row);
	}
	return mat ;	
}

int main()
{
	ull test;
	cin >> test;
	fr(t,0,test)
	{	
		int r,c,rs,cs,s;
		cin >> r >> c >> rs >> cs >> s ;

		double p,q ;
		cin >> p >> q ;

		vector< vector<int> > mat;
		char tmp;
		fr(i,0,r)
		{
			vector<int> row(c);
			fr(j,0,c)
			{
				cin >> 	tmp ;
				if(tmp=='.')
					row[j] = 0 ;
				else
					row[j] = 1 ;
			}
			mat.pb(row);
		}
		
		int k = pow(2,s*2);
		double answer = 0 ;
		fr(i,0,k)
		{
			vector<int> sol = getNext(i,s) ;
			
			double ans = 0;
			int startR = rs ;
			int startC = cs ;
			vector< vector<double> > board = getCopy(mat,p,q); 
			fr(j,0,sol.size())
			{
				if(sol[j]==0)
				{
					if(startC+1<c)
					{
						ans += board[startR][startC+1] ; 
						if(mat[startR][startC+1]==0)	
							board[startR][startC+1]=board[startR][startC+1]*(1-q);  
						else
							board[startR][startC+1]=board[startR][startC+1]*(1-p); 
						startC++;
					}
					else
						ans = -1*INT_MAX ;
				}
				if(sol[j]==1) 
				{
					if(startR+1<r)
					{
						ans += board[startR+1][startC] ; 
						if(mat[startR+1][startC]==0)	
							board[startR+1][startC]=board[startR+1][startC]*(1-q);  
						else
							board[startR+1][startC]=board[startR+1][startC]*(1-p); 
						startR++;
					}
					else
						ans = -1*INT_MAX ;
				}
				if(sol[j]==2)
				{
					if(startC-1>=0)
					{
						ans += board[startR][startC-1] ; 
						if(mat[startR][startC-1]==0)	
							board[startR][startC-1]=board[startR][startC-1]*(1-q);  
						else 
							board[startR][startC-1]=board[startR][startC-1]*(1-p); 
						startC--;
					}
					else
						ans = -1*INT_MAX ;
				}
				if(sol[j]==3)
				{
					if(startR-1>=0)
					{
						ans += board[startR-1][startC] ; 
						if(mat[startR-1][startC]==0)	
							board[startR-1][startC]=board[startR-1][startC]*(1-q);  
						else 
							board[startR-1][startC]=board[startR-1][startC]*(1-p); 
						startR--;
					}
					else
						ans = -1*INT_MAX ;
				}
			} 
		
			if(ans > answer)
				answer = ans ;
		}

		cout << "Case #" << t+1 << ": " << fixed << setprecision(10) << answer << endl ;
	}
	return 0;
}