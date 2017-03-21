#include <bits/stdc++.h>
using namespace std;

class strShift
{
private:
	string s;
public:
	void operator= (string a)
	{
		this->s = a ;
	}
	char* operator<< (int a)
	{
		s = s.substr(s.length()-a) + s.substr(0,s.length()-a);
		return (char*)s.c_str() ;
	}
};

int main()
{
	strShift k;
	k = "MicroSoft";
	printf("%s\n",k<<1);
	printf("%s\n",k<<3);
	return 0;
}