#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n ;
	char sex;
	int start,endvar;


	int dayM[370];
	int dayF[370];
	for(int i=0;i<370;i++)
	{
		dayM[i] =0 ;
		dayF[i] =0 ;
	}


	for(int i = 0 ; i < n ;i++)
	{
		cin >> sex ;
		cin >> start >> endvar ; 
		if(sex == 'M')
		{
			dayM[start]++ ;
			dayM[endvar+1]-- ;
		}
		else
		{
			dayF[start]++ ;
			dayF[endvar+1]-- ;
		}
	}


	for(int i=1;i<370;i++)
		dayM[i] = dayM[i-1] + dayM[i] ;
	for(int i=1;i<370;i++)
		dayF[i] = dayF[i-1] + dayF[i] ;



	int max = 0 ;
	for(int i=0;i<370;i++)
	{
		if(min(dayM[i],dayF[i]) > max)
			max = min(dayM[i],dayF[i]);
	}

	cout << 2*max << endl ;
}