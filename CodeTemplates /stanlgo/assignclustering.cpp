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
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
typedef unsigned long long int ull;
typedef signed long long int sll;

//global DS container
vector<int> rank;   //here rank is the size of set	
vector<int> parent;	//parent denotes root as well as parent
int sol;

int findroot(int x)
{
	if(x != parent[x])
		return findroot(parent[x]);
	return x;
}

void mergeset(int x,int y)
{
	int px = findroot(x);
	int py = findroot(y);
	if(px != py)
	{
		sol-- ;
		if(rank[px] > rank[py])
		{
			parent[py] = px ;
			rank[px] += rank[py];  
		}
		else
		{
			parent[px] = py ;
			rank[py] += rank[px];
		}
	}
}

int main()
{
	clock_t start = clock();
	int nodes,bits;
	cin >> nodes >> bits;
	sol = nodes ;
	
	//initialise all the nodes to be separate;
	int n = pow(2,bits);
	fr(i,0,n) 
	{
		rank.pb(1);
		parent.pb(i);
	}

	//Graph input
	vector<int> vert ;
	vector<bool> hashm(n);
	fr(i,0,n) hashm[i] = false;

	int x,num,y;
	fr(j,0,nodes)
	{
		y = bits - 1 ;
		num = 0 ;
		fr(i,0,bits) 
		{
			cin >> x ;
			num += pow(2,y)*x ;
			y-- ;
		}
		if(hashm[num])
			sol--;
		else
			hashm[num] = true;
		vert.pb(num);
	}
	
	//cluster making
	int x_or,x_or1,xx;
	for(int i = 0 ; i < nodes ; i++ )
	{
		x_or = 1 ;
		for(int j = 0 ; j < bits ; j++ )
		{
			x_or1 = x_or ;
			for(int k = j ; k < bits  ; k++ )
			{
				xx = x_or | x_or1 ; 
				if(hashm[ xx^vert[i] ])
					mergeset(vert[i],vert[i]^xx);
				x_or1 *= 2 ;
			}
			x_or *= 2 ;
		}
	}

	cout << sol << endl ;
	cout << "time " << (float)(clock() - start)*1000/CLOCKS_PER_SEC << " ms" << endl;
	return 0;
}