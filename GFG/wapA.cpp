#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define frr(i,k,n) for(int i = k ; i >= n ; i-- )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
#define point pair<int,int>
#define pii pair<int,int>
#define pib pair<int,bool>
#define arr vector<int> 
#define vectin(a,n) fr(i,0,n) { cin >> a[i] ; }
typedef unsigned long long int ull;
typedef long long int ll;

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m,k;
	cin >> n >> m >> k ;
	vector<string> syms(k);

	string temp;
	fr(i,0,k)
	{
		syms[i] = "";
		fr(j,0,n)
		{
			cin >> temp ;
			syms[i] += temp;
		}
	} 

	if(k==2)
	{
		cout << 1 << endl;
		return 0;
	}

	//Test Print
	// fr(i,0,k)
	// 	cout << syms[i] << endl;


	vector<int> count_1(n*m);
	fr(i,0,n*m)
	{
		count_1[i] = 0;
		fr(j,0,k)
		{
			if(syms[j][i]=='1')
				count_1[i]++;
		}
	}
	// fr(i,0,n*m)
	// 	cout << count_1[i] << " " ;
	// cout << endl ;

	//Different Approach
	int min_val = 10 ;
	int min_index = -1 ;
	fr(i,0,n*m)
	{
		// cout << abs(2*count_1[i]-k) << " " ;
		if(abs(2*count_1[i]-k) < min_val)
		{
			min_val = abs(2*count_1[i]-k);
			min_index = i ;
		}
	}
	// cout << min_index << endl;

	//Something start from min index
	vector<int> groups(k);
	vector<int> groupsTemp(k);
	fr(i,0,k)
		groups[i] = (int)(syms[i][min_index]-'0');

	// fr(i,0,k)
	// 	cout << groups[i] << " ";
	// cout << endl ;

	vector<bool> selected_col(n*m,false);
	selected_col[min_index] = true;
	int max_till = 2; //two groups generated
	int max_all_index = min_index ;
	int max_all = 2 ;
	int final_sol = 1;
	while(1)
	{
		// cout << "new Iter" << endl ;
		fr(i,0,n*m)
		{
			if(!selected_col[i])
			{
				vector<int> groupsN(k);
				fr(j,0,k)
					groupsN[j] = groups[j] ;

				int current = 0 ;
				fr(j,0,max_till)
				{
					int forZero = -1;
					int forOne = -1;
					fr(m,0,k)
					{	
						if(groups[m]==j)
						{
							// cout << "check "	 << j << " " << m << " "<< syms[m][i]<< endl;
							if(syms[m][i]=='0')
							{
								if(forZero==-1)
								{
									if(forOne!=-1)
										forZero = forOne+1;
									else
										forZero = current;
								}
								groupsN[m] = forZero ;
							}
							else
							{
								if(forOne==-1)
								{
									if(forZero!=-1)
										forOne = forZero+1;
									else
										forOne = current;
								}
								groupsN[m] = forOne;
							}

							// printvect(groupsN,k);
							// cout << endl ;
						}
					}
					if(forOne!=-1 && forZero!=-1)
						current += 2;
					else
						current++;
					// cout << "next " << current << endl ;
				}

				//Check if max 
				int max_now = groupsN[0];
				fr(j,1,k)
					max_now = max(max_now,groupsN[j]);
				// cout << "Max with this -> " << max_now << endl ;
				if(max_all < max_now)
				{
					max_all = max_now ;
					max_all_index = i ;
					fr(j,0,k)
						groupsTemp[j] = groupsN[j] ;
				}
			}
		}
		// cout << max_all << " " << max_all_index << endl ;
		selected_col[max_all_index] = true;
		fr(j,0,k)
			groups[j] = groupsTemp[j] ;
		// fr(j,0,k)
		// 	cout << groups[j] << " ";
		// cout << endl;
		max_till = max_all+1;
		final_sol++;
		if(max_all==k-1)
			break;
	}

	cout << final_sol << endl ;
	return 0;
}