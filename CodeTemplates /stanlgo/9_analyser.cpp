#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ifstream file("mincutdata.txt");
	string str;
	getline(file,str);
	istringstream ss(str);
	int x;
	vector<int> data;
	while(ss >> x )
		data.push_back(x);
	sort(data.begin(),data.end());
	cout << "MinCut Result " << data[0] << endl ;
}