//closest pair
#include <iostream>
#include <algorithm>
using namespace std;

struct point {
	int x;
	int y;
};

int main()
{
	int no_of_points;
	cin >> no_of_points ;
	point pts[no_of_points];
	for ( int i = 0 ; i < no_of_points ; i++ )
		cin >> pts[i].x >> pts[i].y ;
	sort(&pts[0].x,&pts[no_of_points].x,);
	for ( int i = 0 ; i < no_of_points ; i++ )
	{
		cout << pts[i].x << " " << pts[i].y << endl ;
	}
	return 0 ;
}