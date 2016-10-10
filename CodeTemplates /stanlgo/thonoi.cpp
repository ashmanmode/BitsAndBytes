//tower of honoi
#include <iostream>
#include <fstream>
#include <vector>
#include "time.h"
using namespace std;

ofstream file("th.txt");
vector<int> a;    //tower 1
vector<int> b;    //tower 2
vector<int> c;    //tower 3
vector<int> temp;
unsigned long long int count = 0 ;

void print(int flag)
{
	file << "state " << count << endl; count ++ ;
	if(flag == 0)
	{
		file << "> " ;
		for(int i = 0 ; i < a.size() ;i++)
			file <<  a[i] << " ";
		file << endl << "> " ;
		for(int i = 0 ; i < b.size() ;i++)
			file <<  b[i] << " ";
		file << endl << "> ";
		for(int i = 0 ; i < c.size() ;i++)
			file <<  c[i] << " ";
		file << endl ;
	}
	else if(flag == 1)
	{
		file << "> " ;
		for(int i = 0 ; i < c.size() ;i++)
			file <<  c[i] << " ";
		file << endl << "> ";
		for(int i = 0 ; i < a.size() ;i++)
			file <<  a[i] << " ";
		file << endl << "> ";
		for(int i = 0 ; i < b.size() ;i++)
			file <<  b[i] << " ";
		file << endl ;
	}
	else
	{
		file << "> " ;
		for(int i = 0 ; i < b.size() ;i++)
			file <<  b[i] << " ";
		file << endl << "> ";
		for(int i = 0 ; i < c.size() ;i++)
			file <<  c[i] << " ";
		file << endl << "> ";
		for(int i = 0 ; i < a.size() ;i++)
			file <<  a[i] << " ";
		file << endl ;
	}
}

void t_honoi(int n,int flag)
{
	if(n == 1) //base case
		{ a.pop_back(); b.push_back(1); print(flag); }
	else
	{
		t_honoi(n-1,flag);
		if( a[a.size()-1]%2 == 0 )
			{
				a.pop_back(); c.push_back(n); print(flag);
				temp = a ; a = b ;b = c ; c = temp ;
				t_honoi(n-1,(1+flag)%3);
				temp = a ; a = c ;c = b ; b = temp ;
			}
		else
			{
				a.pop_back(); b.push_back(n); print(flag);
				temp = a ; a = c ;c = b ; b = temp ;
				t_honoi(n-1,(2+flag)%3);
				temp = a ; a = b ;b = c ; c = temp ;
			}
	}
}

int main()
{
	int n;
	cin >> n ;
	clock_t start_t = clock();
	file << "Tower of Hanoi (" << n << ")" << endl;
	for(int i = 0 ; i < n ; i++)
		a.push_back(n-i);
	print(0);
	t_honoi(n,0);
	cout << "Steps " << count - 1 << endl ;
	cout << "time " << (float)(clock() - start_t)*1000/CLOCKS_PER_SEC << " ms" << endl;
	return 0;
}