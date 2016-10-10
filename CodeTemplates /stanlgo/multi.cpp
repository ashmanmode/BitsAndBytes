// recursive approach to multiplication for no. with n digits
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
using namespace std;

typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<unsigned long long int> vull;
#define pb push_back
#define sz(a) a.size()

int digits(int a)
{
	int count = 0 ;
	while(a/10 != 0)
	{
		a /= 10 ;
		count++ ;
	}
	return count+1;
}

int multiply(int A, int B)
{
	int digi = digits(A) ;
	//cout << "digi " << digi << endl; 
	if(digi == 1)
		return A*B;
	else
	{
		int a = A/pow(10,digi/2) ;
		int b = A - a*pow(10,digi/2) ;
		int c = B/pow(10,digi/2) ;
		int d = B - c*pow(10,digi/2) ;
		//cout << "stream" << a << "  " <<  b << "  " <<  c << "  " <<  d << endl ;
		int x = multiply(a,c) ; 
		int y = multiply(a+b,c+d) ; 
		int z = multiply(b,d) ; 
		return pow(10,2*(digi/2))*x + pow(10,digi/2)*(y-x-z) + z ;	
	}
}

int main()
{
	int a,b ;
	cin >> a >> b ;
	clock_t t = clock(); 
	cout << "multi 1 " << a*b  << endl;
	cout << "time " << (float)(clock()-t)/CLOCKS_PER_SEC << endl  ;
	cout << "multi 2 " << multiply(a,b) << endl ;
	cout << "time " << (float)(clock()-t)/CLOCKS_PER_SEC << endl  ;
	return 0;
}

