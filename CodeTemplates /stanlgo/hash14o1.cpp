//2sum problem (214 from -10000 to -1 inclusive (time 796972 ms))
//(213 from 0 to 10000 inclusive (time 798530 ms))
//total 2-sums 427 and time 26 minutes
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include "time.h"
using namespace std;
typedef signed long long int si;

si hashf(si num)
{
	return (si)(abs(num)/20000) ; 
}

int main()
{
	ifstream file("F2suminp.txt");
	si num ;
	//hashing the data
	vector<si> data;
	vector< vector<si> > table;
	vector<si> list ; 
	for(int i = 0 ;i < 5000000 ; i++ )
		table.push_back(list);
	while(file >> num)
	{
		table[hashf(num)].push_back(num);
		data.push_back(num);
	}

	//checking 2 sum 
	clock_t start = clock();
	bool found ;
	int count = 0 ;
	si required;
	for(int a = -10000 ; a < 10001 ; a++ )
	{
		found = false;
		for(int i = 0 ; i < data.size() ; i++ )
		{
			required = a - data[i] ;
			for(int j = 0 ; j < table[hashf(required)].size() ; j++ )
			{
				if(table[hashf(required)][j] == required)
				{
					cout << "found" << a << endl ; 
					found = true ;  count++ ;
					break ;
				}
			}
			if(found)
				break ;
		}
	}
	cout << "total " << count << endl ; 
	cout << "time total " << (float)(clock() - start)*1000/CLOCKS_PER_SEC << " ms" << endl;
	return 0;
}