/* Program to find LCA of n1 and n2 using one traversal of Binary Tree */
#include <bits/stdc++.h>
using namespace std;

map< pair< pair<int,int> ,bool> , int > memo;

int calc(vector<char> c,int start,int end,bool b)
{
	if(start==end)
	{
		if(c[start]=='T' && b)
			return 1;
		else if(c[start]=='F' && !b)
			return 1;
		else 
			return 0;
	}

	int maxval = 0 ;
	int newval,u,v,w,x;

	for(int i = start+1;i<=end;i+=2)
	{
		if(memo.find( make_pair(make_pair(start,i-1),0) ) == memo.end() )
			memo[make_pair(make_pair(start,i-1),0)] = calc(c,start,i-1,0) ;
		if(memo.find( make_pair(make_pair(start,i-1),1) ) == memo.end() )
			memo[make_pair(make_pair(start,i-1),1)] = calc(c,start,i-1,1) ;
		if(memo.find( make_pair(make_pair(i+1,end),0) ) == memo.end() )
			memo[make_pair(make_pair(i+1,end),0)] = calc(c,i+1,end,0) ;
		if(memo.find( make_pair(make_pair(i+1,end),1) ) == memo.end() )
			memo[make_pair(make_pair(i+1,end),1)] = calc(c,i+1,end,1) ;

		u = memo[make_pair(make_pair(start,i-1),0)];
		v = memo[make_pair(make_pair(start,i-1),1)];
		w = memo[make_pair(make_pair(i+1,end),0)];
		x = memo[make_pair(make_pair(i+1,end),1)];

		if(c[i]=='^')
		{
			if(b)
				newval = u*x+v*w;
			else
				newval = u*w+v*x;
		}
		else if(c[i]=='&')
		{
			if(b)
				newval = v*x;
			else
				newval = u*w+u*x+v*w;
		}
		else
		{
			if(!b)
				newval = u*w;
			else
				newval = v*x+u*x+v*w;	
		}
		maxval = (maxval+newval)%1003;
		// cout << c[i] << " " << newval << endl ;
	}
	return maxval;
}

int main()
{
	int t ;
	cin >> t ;
	while(t--)
	{
		int n;
		cin >> n ;
		vector<char> c(n) ;
		for( int i = 0 ; i < n ;i++ )
			cin >> c[i] ;

		//Sol
		cout << calc(c,0,n-1,1)%1003 << endl;
	}
}