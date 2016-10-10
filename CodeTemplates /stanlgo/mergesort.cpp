//merge sort algo
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<unsigned long long int> vull;
#define pb push_back
#define sz(a) a.size()
#define printarr(array,n) for(int i = 0 ; i < n ; i++){cout << array[i] << " " ; } cout << endl ;

void merge_helper(int *array,int begin,int end,int *scratch)
{
	
	if(1 == end - begin){}
	else
	{
		int mid = (end-begin)/2 ;
		merge_helper(array,begin,begin+mid,scratch);
		merge_helper(array,begin+mid,end,scratch);
		int i = begin; 
		int j = begin + mid; 
		int k = 0;
		for(int k = 0 ; k < (end-begin) ; k++ )
		{
			if(i > begin + mid - 1)
			{
				scratch[k] = array[j];
				j++ ;
			}
			else if( j > end - 1 || array[i] < array[j])
			{
				scratch[k] = array[i];
				i++;
			}
			else
			{
				scratch[k] = array[j];
				j++ ;
			}
		}
		//copying back to main array
		for(int k = begin ; k < end ; k ++ )
			array[k] = scratch[k-begin];
	}
	
}

void mergesort(int *array,int n)
{
	int *copy = (int*)malloc(n*sizeof(int));
	merge_helper(array,0,n,copy);
	free(copy);
}

int main()
{
	int n;
	cin >> n ;
	int array[n];
	for(int i = 0 ; i < n ; i++ )
		cin >> array[i];
	mergesort(array,n);
	printarr(array,n);
	return 0 ;
}