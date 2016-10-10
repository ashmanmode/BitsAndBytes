#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

int main()
{
	clock_t t = clock();
	int sum = 0;
	string line;
	ifstream file("input.txt");
	vector<string> dict(7000);
	if(file.is_open())
	{
		getline (file,line);
    	file.close();
	}
	int i = 1 ; 
	int j = 0; 
	while((int)line[i] != 0)
	{
		while( 34 != (int)line[i])
		{
			dict[j].append(1,line[i]);
			i++ ; 
		}
		j++ ;
		i += 3;
	}
	int k ;
	sort(dict.begin(),dict.begin() + j);
	for(i = 0 ; i < j ; i++ )
	{
		k = 0 ;
		while(dict[i][k] != 0)
		{
			sum = sum + (i+1)*((int)dict[i][k] - 64) ; 
			k++ ;
		}
	}
	cout << sum << endl ;
	cout << "time required " << ((float)(clock() - t)/CLOCKS_PER_SEC)*1000 << " ms" <<  endl ;
	return 0 ;
}