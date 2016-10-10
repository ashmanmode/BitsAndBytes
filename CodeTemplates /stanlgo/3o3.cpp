// straseen's matrix multiplication for same ordered n*n matrices 
// yet to be completed
#include <iostream>
using namespace std;


int** multi(int** matA,int** matB,int n)
{
	int half = n/2 ;
	int a[n/2 + n%2][n/2 + n%2];
	int b[n/2 + n%2][n/2];
	int c[n/2][n/2 + n%2];
	int d[n/2][n/2];
	int e[n/2 + n%2][n/2 + n%2];
	int f[n/2 + n%2][n/2];
	int g[n/2][n/2 + n%2];
	int h[n/2][n/2];
	int p1 = 

	  

}

int main()
{
	int n;
	cin >> n ;
	int matA[n][n];
	int matB[n][n];
	int matC[n][n];
	for(int i = 0 ; i  < n ; i++)
	{
		for ( int j = 0 ; j < n ; j ++ )
			cin >> matA[i][j];
	}
	for(int i = 0 ; i  < n ; i++)
	{
		for ( int j = 0 ; j < n ; j ++ )
			cin >> matB[i][j];
	}

	// finding the multilplication
	matC = multi(matA,matB,n)
}
