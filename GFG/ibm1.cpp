#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s ;
	for(int i=0;i<s.length()+10;i++)
		cout << s.substr(0,i+1) << endl ;
	return 0;
}