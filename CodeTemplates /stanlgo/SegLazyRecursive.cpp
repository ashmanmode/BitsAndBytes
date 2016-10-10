//Normal Segment tree
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

// maximum size of t needed is 2^(x+1) if n <= 2^x so 
//in general max size needed is 2*n if n = 2^x else 4*n
ull t[1234567] ;
ull l[1234567] ;
ull a[123456];
int n ;

ull fun(ull a,ull b)
{
	return a+b ;
}

void build(int index,int start,int end)
{	
	if(start > end)
		return;
	if(start == end)
	{
		t[index] = a[start];
		return ;
	}

	build(index*2 + 1, start , (start+end)/2 );
	build(index*2 + 2, (start+end)/2 + 1 , end );

	t[index] = fun(t[index*2 + 1],t[index*2 + 2]) ;
}

//adding / using function value over a interval
//increment elements in range [x,y]
//where the current range is [a,b]
void set_tree(int index, int a,int b, int x,int y,ull v)
{ 
	if(l[index] !=0 ) //node was lazyly updated so now needs to be considered 
	{
		t[index] += l[index]*(b-a+1);
		if(a != b )
		{
			l[2*index+1] = fun(l[index],l[index*2 + 1 ]);
			l[2*index+2] = fun(l[index],l[index*2 + 2 ]);
		}
		l[index] = 0  ;
	}

	if(a > b || a > y || b < x )
		return ;

	if(a >= x && b <= y) { 
    	t[index] += v*(b-a+1);

		if(a != b) 
		{ 
			l[index*2+1] = fun(l[index*2+1],v);
			l[index*2+2] = fun(l[index*2+2],v);
		}
    	return;
	}

	set_tree(2*index+1 , a , (a+b)/2 , x,y,v);
	set_tree(2*index+2 , (a+b)/2 +1 , b ,x,y,v);

	t[index] = fun(t[index*2 + 1],t[index*2 + 2]) ;
}

ull get_tree(int index,int a,int b,int x,int y)
{
	//cout << "get " << index << " " << a << " " << b << " " << x << " " << y << endl ;
	if(a > b || a > y || b < x )
		return 0;

	if(l[index] !=0 ) //node was lazyly updated so now needs to be considered now
	{
		t[index] += l[index]*(b-a+1);
		if(a !=b )
		{
			l[2*index+1] = fun(l[index],l[index*2 + 1 ]);
			l[2*index+2] = fun(l[index],l[index*2 + 2 ]);
		}
		l[index] = 0  ;
	}

	if( a >= x && b <= y)
		return t[index];

	return fun(get_tree(2*index+1 , a , (a+b)/2 , x,y ),get_tree(2*index+2 , (a+b)/2 +1 , b ,x,y ));
}

int main()
{
	int test;
	cin >> test ;
	while(test--)
	{
		ull c,q,x,y,v;
		cin >> n >> c; 
		fr(i,0,n)
			a[i] = 0 ;

		build(0,0,n-1);
		memset( l,0,sizeof(l) );

		fr(i,0,c)
		{
			cin >> q ;
			if(q == 0)
			{
				cin >> x >> y >> v ;
				set_tree(0,0,n-1,x-1,y-1,v);
			}
			else
			{
				cin >> x >> y ;
				cout << get_tree(0,0,n-1,x-1,y-1) << endl ;
			}
		}
	}
	return 0 ;
}