#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define frr(i,k,n) for(int i = k ; i >= n ; i-- )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
#define point pair<int,int>
#define pii pair<int,int>
#define pib pair<int,bool>
#define arr vector<int> 
#define vectin(a,n) fr(i,0,n) { cin >> a[i] ; }
typedef unsigned long long int ull;
typedef long long int ll;

struct TrieNode
{
    struct TrieNode *child[2];	
};

class BinTrie
{
public:
	BinTrie();
	void insert(string key);
	ll findXORMax(string key);
private:
	struct TrieNode *getNode();
	struct TrieNode *root;
};

BinTrie::BinTrie()
{
	root = getNode();	
}

struct TrieNode *BinTrie::getNode()
{
    struct TrieNode *pNode = NULL;
 
    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
 
    if(pNode)
    {
 		pNode->child[0] = NULL;
 		pNode->child[1] = NULL;
    }
 
    return pNode;
}
 
void BinTrie::insert(string key)
{   
	int index; 
    struct TrieNode *pCrawl = root;
 
    fr(level,0,key.length())
    {
        index = (int)(key[level]-'0');
        if (!pCrawl->child[index])
            pCrawl->child[index] = getNode();
 
        pCrawl = pCrawl->child[index];
    }
}
 
ll BinTrie::findXORMax(string key)
{
    int index;
    struct TrieNode *pCrawl = root;
    string sol(key.length(),' ');
 
    fr(level,0,key.length())
    {
        index = (int)(key[level]-'0');
        index = (index+1)%2; 

        if(!pCrawl->child[index])
        {
            sol[level] = '0';
            pCrawl = pCrawl->child[(index+1)%2];
        }
        else
        {
        	sol[level] = '1';
        	pCrawl = pCrawl->child[index];
        }
    }
 
    return bitset<40>(sol).to_ulong();
}

ll brute(vector<ll> pre,vector<ll> suf)
{	
	ll xor_max = 0 ;
	fr(i,0,pre.size())
	{
		fr(j,i,pre.size())
		{
			xor_max = max(xor_max,pre[i]^suf[j]);
		}
	}
	return xor_max ;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n ;
	vector<ll> data(n);
	fr(i,0,n)
		cin >> data[i] ;

	//Getting Prefix and Suffix Array
	vector<ll> pre(n+1);
	vector<ll> suf(n+1);
	pre[0] = 0;
	suf[n] = 0;
	fr(i,1,n+1)
		pre[i] = pre[i-1]^data[i-1];
	frr(i,n-1,0)
		suf[i] = suf[i+1]^data[i];

	//Test Printing
	// printvect(pre,n+1); cout << endl;
	// printvect(suf,n+1); cout << endl;

	//Finding two max numbers using Trie
	string num ;
	ll max_xor = 0 ; 
	BinTrie t;
	fr(i,0,n+1)
	{
		num = bitset<40>(pre[i]).to_string();
		t.insert(num);

		num = bitset<40>(suf[i]).to_string();
		max_xor = max(max_xor,t.findXORMax(num));
	}
 
 	// cout << "True: " << brute(pre,suf) << endl ;	
	cout << max_xor << endl;
	return 0;
}