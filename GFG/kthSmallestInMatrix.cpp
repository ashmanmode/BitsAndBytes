#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > mat; 

struct ELE
{
	int val;
	int x;
	int y;
};

struct myComp
{
	bool operator()(const ELE &a, const ELE &b)
	{
		return a.val > b.val ;
	}
};

int findKth(int k)
{
	priority_queue< ELE , vector<ELE> , myComp > q;

	//Inserting all column's first element
	int n = mat.size();
	for(int i=0;i<n;i++)
	{
		ELE temp ;
		temp.val = mat[i][0];
		temp.x = i ;
		temp.y = 0 ;
		q.push(temp);
	}

	while(--k)
	{
		//Remove elemetns
		ELE topElement = q.top() ;
		q.pop();
		
		// cout << topElement.val << endl ;

		if(++topElement.y < n)
		{
			topElement.val = mat[topElement.x][topElement.y];
			q.push(topElement);
		}
	}
	return q.top().val;
}

int main()
{
	int n,k;
	cin >> n ;

	vector<int> temp(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin >> temp[j] ;
		mat.push_back(temp);
	}

	cin >> k ;
	cout << "Ans " << findKth(k) << endl ;
}