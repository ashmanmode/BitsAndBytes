//randomised selection using pivoting 
#include <iostream>
#include <stdlib.h>
using namespace std;

int qs(int array[],int first,int last,int order)
{
	int temp;
	srand(time(NULL));
	int randex = rand() % (last - first) + first ;  cout << randex << endl ;//random pivot
	temp = array[randex];
	array[randex] = array[first];
	array[first] = temp;

	//partition subroutine
	int i = first+1;
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
	if(i == order)
		return pivot;
	else if(order > i)
		return qs(array,i,last,order);
	else
		return qs(array,first,i-1,order);
}

int main()
{
	int n,order_statistic;
	cin >> n >> order_statistic ;
	if(order_statistic > n || order_statistic < 1)
	{
		cout << "Order Statistic out of bounds" << endl ;
		return 0 ;
	}
	int array[n];
	for(int i= 0;i<n;i++) 
		cin >> array[i];
	cout << qs(array,0,n,order_statistic) << endl;
	return 0;
}