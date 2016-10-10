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
int t[423456] ;
//int l[1234567] ;
bool up[423456];
int a[123456];
int n ;

//adding / using function value over a interval
//increment elements in range [x,y]
//where the current range is [a,b]
void set_tree(int index, int a,int b, int x,int y)
{ 
	//cout << "set " << index << " " << a << " " << b << " " << x << " " << y << endl ;
	if(up[index]) //node was lazyly updated so now needs to be considered 
	{
		t[index] = (b-a+1) - t[index];
		if(a != b )
		{
			//l[index*2+1] = (a+b)/2 - a + 1 - l[index*2+1]; 
			up[index*2+1]  = !up[index*2+1]; 
			//l[index*2+2] = b - (a+b)/2 - l[index*2+2] ; 
			up[index*2+2] = !up[index*2+2]; 
		}
		up[index] = false ;
	}

	if(a > b || a > y || b < x )
		return ;

	if(a >= x && b <= y) { 
    	t[index] = (b-a+1) - t[index];

		if(a != b) 
		{ 
			//l[index*2+1] = (a+b)/2 - a + 1 - l[index*2+1]; 
			up[index*2+1]  = !up[index*2+1];
			//l[index*2+2] = b - (a+b)/2 - l[index*2+2] ; 
			up[index*2+2] = !up[index*2+2];
		}
    	return;
	}

	set_tree(2*index+1 , a , (a+b)/2 , x,y);
	set_tree(2*index+2 , (a+b)/2 +1 , b ,x,y);

	t[index] = t[index*2 + 1] + t[index*2 + 2] ;
}

int get_tree(int index,int a,int b,int x,int y)
{
	//cout << "get " << index << " " << a << " " << b << " " << x << " " << y << endl ;
	if(a > b || a > y || b < x )
		return 0;

	if(up[index]) //node was lazyly updated so now needs to be considered 
	{
		t[index] = (b-a+1) - t[index];
		if(a != b )
		{
			//l[index*2+1] = (a+b)/2 - a + 1 - l[index*2+1]; 
			up[index*2+1]  = !up[index*2+1];
			//l[index*2+2] = b - (a+b)/2 - l[index*2+2] ; 
			up[index*2+2] = !up[index*2+2];
		}
		up[index] = false ;
	}

	if( a >= x && b <= y)
		return t[index];

	return get_tree(2*index+1 , a , (a+b)/2 , x,y ) + get_tree(2*index+2 , (a+b)/2 +1 , b ,x,y ) ;
}

int main()
{
	int c,q,x,y;
	scanf("%d%d",&n,&c);

	// fr(i,0,n)
	// 	a[i] = 0 ;
	//build(0,0,n-1);

	memset( t,0, 4*n*sizeof(int) );
	memset( up,false, 4*n*sizeof(bool) );


	fr(i,0,c)
	{
		scanf("%d%d%d",&q,&x,&y);
		if(q == 0)
			set_tree(0,0,n-1,x-1,y-1);
		else
			printf("%d\n",get_tree(0,0,n-1,x-1,y-1) );
	}
	return 0 ;
}