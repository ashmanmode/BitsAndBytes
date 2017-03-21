#include <iostream>
using namespace std;

int main () 
{
  try
  {
    int n ;
    cin >> n ;
    if(n!=15)
    	throw 1;
    cout << "some " << n << endl ;
  }
  catch (int e)
  {
  	if(e==1)
    	cout << "An exception occurred. Exception Nr. " << e << '\n';
    else
    	cout << "NO errors" << endl ;
  }
  catch (...)
  {
    cout << "An Default exception occurred.\n";
  }
  return 0;
}