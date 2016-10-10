//quicksort
#include <iostream>
using namespace std;

void qs(int array[],int first,int last)
{
	int temp = array[last-1];
	array[last-1] = array[first];
	array[first] = temp;

	//partition subroutine
	int i = first+1, temp;
	int pivot = array[first];
	for(int j = first + 1; j < last; j++)
	{
		if(array[j] <= pivot)
		{
			if(i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			i++ ;
		}
	}
	temp = array[i-1];
	array[i-1] = array[first];
	array[first] = temp;
	if(i-1-first > 1)
		qs(array,first,i-1);
	if(last-i > 1)
		qs(array,i,last);
}

int main()
{
	int n;
	cin >> n ;
	int array[n];
	for(int i= 0;i<n;i++) 
		cin >> array[i];
	qs(array,0,n);
	for(int i= 0;i<n;i++) 
		cout << array[i] << " ";
	cout << endl; 
	return 0;
}