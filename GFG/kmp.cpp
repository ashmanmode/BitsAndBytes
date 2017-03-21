#include <bits/stdc++.h>
using namespace std;

class kmp
{
private:
	string pattern;
	string text;
	int *preprocess;
	void getProperPrefix()
	{
		preprocess[0] = -1 ;
		preprocess[1] = 0 ;
		for(int i=2;i<pattern.length()+1;i++)
		{
			if(pattern[i-1]==pattern[preprocess[i-1]])
				preprocess[i] = preprocess[i-1] + 1 ; 
			else
				preprocess[i] = 0 ;
		}
	}
public:
	kmp(string pattern,string text)
	{
		this->pattern = pattern;
		this->text = text;
		preprocess = (int *)malloc(sizeof(int)*(pattern.length()+1));
	}
	void find()
	{
		this->getProperPrefix();

		//Search the pattern after preprocess in given text
		int i=0,j=0;
		while(i<text.length()+1)
		{
			if(j==pattern.length())
			{ 
				cout << "Match Found at " << i - pattern.length() << endl;
				j = preprocess[j];
			}
			else if(text[i]==pattern[j])
			{
				i++;
				j++;
			}
			else 
			{
				if(j==0)
					i++;
				else
					j = preprocess[j] ;
			}
		}
	}
};

int main()
{
	string pattern,text;
	cin >> pattern >> text ;

	kmp instance(pattern,text);
	instance.find();
	return 0;
}