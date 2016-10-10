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

int max_v,n,m;
vector<int> max_i,max_j;
vector< vector<int> > hor,ver,plot,mine;

void createAux()
{
	//Filing vects hor
	fr(i,0,n)
	{
		fr(j,0,m)
		{
			if(j>0)
				hor[i][j] = plot[i][j] + hor[i][j-1];
			else
				hor[i][j] = plot[i][j];

			if(i>0)
				ver[i][j] = plot[i][j] + ver[i-1][j];
			else
				ver[i][j] = plot[i][j];
		}
	}

	// fr(i,0,n)
	// {
	// 	fr(j,0,m)
	// 		cout << hor[i][j] << " " ;
	// 	cout << endl ;
	// }
	// cout << endl ;
	// fr(i,0,n)
	// {
	// 	fr(j,0,m)
	// 		cout << ver[i][j] << " " ;
	// 	cout << endl ;
	// }
	// cout << endl ;
}

vector< vector<int> > getDamage()
{	
	vector< vector<int> > damage;
	fr(i,0,n)
	{
		vector<int> tmp(m);
		damage.pb(tmp);
	}

	int x,y,v,w;
	max_v = -1;
	fr(i,0,n)
	{
		fr(j,0,m)
		{
			x = 0; y = hor[i][m-1] ; v = 0 ; w = ver[n-1][j] ; 
			if(j-mine[i][j]-1 >= 0)
				x = hor[i][j-mine[i][j]-1];
			if(j+mine[i][j] < m)
				y = hor[i][j+mine[i][j]];
			if(i-mine[i][j]-1 >= 0)
				v = ver[i-mine[i][j]-1][j];
			if(i+mine[i][j] < n)
				w = ver[i+mine[i][j]][j];
			damage[i][j] = y-x+w-v;
			if(plot[i][j]==1)
				 damage[i][j]--;

			if(damage[i][j]>max_v)
			{
				max_i.clear();
				max_j.clear();
				max_v = damage[i][j];
			}
			if(damage[i][j]==max_v)
			{
				max_i.pb(i);
				max_j.pb(j);
			}
			
		}
	}
	return damage;
}

void modifyPlot(int x)
{
	//hor
	fr(j,0,m)
	{	
		if(j <= max_j[x]+mine[max_i[x]][max_j[x]] && j >= max_j[x]-mine[max_i[x]][max_j[x]])
			plot[max_i[x]][j] = 0 ;
	}

	//Vert
	fr(i,0,n)
	{	
		if(i <= max_i[x]+mine[max_i[x]][max_j[x]] && i >= max_i[x]-mine[max_i[x]][max_j[x]])
			plot[i][max_j[x]] = 0 ;
	}

	// fr(i,0,n)
	// {
	// 	fr(j,0,m)
	// 		cout << plot[i][j] << " " ;
	// 	cout << endl ;
	// }
	// cout << endl ;
}

int main()
{
	ull test;
	cin >> test;
	fr(t,0,test)
	{
		cin >> n >> m ; 
		fr(i,0,n)
		{
			vector<int> tmp(m);
			fr(j,0,m)
				cin >> tmp[j];
			plot.pb(tmp);
		}
		fr(i,0,n)
		{
			vector<int> tmp(m);
			fr(j,0,m)
				cin >> tmp[j];
			mine.pb(tmp);
		}

		//Prog Start
		fr(i,0,n)
		{
			vector<int> tmp(m);
			hor.pb(tmp);
			ver.pb(tmp);
		}

		max_v = 10000000;
		vector< pair<int,int> > sol;
		while(max_v != 0)
		{
			createAux();
			vector< vector<int> > damage = getDamage();
			// fr(i,0,n)
			// {
			// 	fr(j,0,m)
			// 		cout << damage[i][j] << " ";
			// 	cout << endl ;
			// }
			// cout << endl ;
			// cout << max_v << endl ;
			if(max_v==0)
				break;
			int siz = 3;
			if(max_i.size()<3)
				siz = max_i.size();
			fr(x,0,siz)
			{
				// cout << max_i[x] << " " << max_j[x] << endl;
				sol.pb(mp(max_i[x],max_j[x]));
				modifyPlot(x);
			}
			max_i.clear();max_j.clear();
		}

		cout << sol.size() << endl ;
		fr(i,0,sol.size())
			cout << sol[i].F << " " << sol[i].second << endl ;	

		plot.clear();mine.clear();hor.clear();ver.clear();
	}
	return 0;
}