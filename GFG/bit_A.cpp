#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define mod 1000000007
#define F first
#define S second
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%llu",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%llu",a)
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << fixed << a[i] << " " ;
typedef unsigned long long int ull;
  
struct sTree 
{
    struct sTree *children[256];
    struct sTree *sLink;
    int start;
    int *end;
    int sIndex;
};
  
typedef struct sTree Node;
  
string text; 
Node *root = NULL; 
Node *lastNewNode = NULL;
Node *activeNode = NULL;
  
int activeEdge = -1;
int activeLength = 0;
  
int remainingSuffixCount = 0;
int leafEnd = -1;
int *rootEnd = NULL;
int *splitEnd = NULL;
int size = -1; 
int size1 = 0; 
  
Node *newNode(int start, int *end)
{
    Node *node =(Node*) malloc(sizeof(Node));
    int i;
    for (i = 0; i < 256; i++)
          node->children[i] = NULL;
 
    node->sLink = root;
    node->start = start;
    node->end = end;

    node->sIndex = -1;
    return node;
}
  
int edgeLength(Node *n) 
{
    if(n == root)
        return 0;
    return *(n->end) - (n->start) + 1;
}
  
int walkDown(Node *currNode)
{
    if (activeLength >= edgeLength(currNode))
    {
        activeEdge += edgeLength(currNode);
        activeLength -= edgeLength(currNode);
        activeNode = currNode;
        return 1;
    }
    return 0;
}
  
void extendTree(int pos)
{
    leafEnd = pos;
    remainingSuffixCount++;
    lastNewNode = NULL;
  
    while(remainingSuffixCount > 0) {
  
        if (activeLength == 0)
            activeEdge = pos; 
        
        if (activeNode->children[text[activeEdge]] == NULL)
        {
            activeNode->children[text[activeEdge]] =
                                          newNode(pos, &leafEnd);
            if (lastNewNode != NULL)
            {
                lastNewNode->sLink = activeNode;
                lastNewNode = NULL;
            }
        }
        else
        {

            Node *next = activeNode->children[text[activeEdge]];
            if (walkDown(next))
                continue;

            if (text[next->start + activeLength] == text[pos])
            {

                if(lastNewNode != NULL && activeNode != root)
                {
                    lastNewNode->sLink = activeNode;
                    lastNewNode = NULL;
                }
                activeLength++;
                break;
            }
  
            splitEnd = (int*) malloc(sizeof(int));
            *splitEnd = next->start + activeLength - 1;
            Node *split = newNode(next->start, splitEnd);
            activeNode->children[text[activeEdge]] = split;
            split->children[text[pos]] = newNode(pos, &leafEnd);
            next->start += activeLength;
            split->children[text[next->start]] = next;

            if (lastNewNode != NULL)
                lastNewNode->sLink = split;
            lastNewNode = split;
        }

        remainingSuffixCount--;
        if (activeNode == root && activeLength > 0) 
        {
            activeLength--;
            activeEdge = pos - remainingSuffixCount + 1;
        }
        else if (activeNode != root) 
        {
            activeNode = activeNode->sLink;
        }
    }
}

void setSIndex(Node *n, int labelHeight)
{
    if (n == NULL)  return;
    int leaf = 1;
    int i;
    for (i = 0; i < 256; i++)
    {
        if (n->children[i] != NULL)
        {
            leaf = 0;
            setSIndex(n->children[i], labelHeight + edgeLength(n->children[i]));
        }
    }
    if (leaf == 1)
    {
        for(i= n->start; i<= *(n->end); i++)
        {
            if(text[i] == '-')
            {
                n->end = (int*) malloc(sizeof(int));
                *(n->end) = i;
            }
        }
        n->sIndex = size - labelHeight;
    }
}
  
void freeSTREE(Node *n)
{
    if (n == NULL)
        return;
    int i;
    for (i = 0; i < 256; i++)
    {
        if (n->children[i] != NULL)
        {
            freeSTREE(n->children[i]);
        }
    }
    if (n->sIndex == -1)
        free(n->end);
    free(n);
}

void creatSTREE()
{
    size = text.length();
    int i;
    rootEnd = (int*) malloc(sizeof(int));
    *rootEnd = - 1;
    root = newNode(-1, rootEnd);
  
    activeNode = root; 
    for (i=0; i<size; i++)
        extendTree(i);
    int labelHeight = 0;
    setSIndex(root, labelHeight);
}

int traverse(Node *n, int labelHeight, int* maxHeight, int* substringStartIndex)
{
    if(n == NULL)
    {
        return 0;
    }
    int i=0;
    int ret = -1;
    if(n->sIndex < 0) 
    {
        for (i = 0; i < 256; i++)
        {
            if(n->children[i] != NULL)
            {
                ret = traverse(n->children[i], labelHeight + 
                    edgeLength(n->children[i]), 
                    maxHeight, substringStartIndex);
                 
                if(n->sIndex == -1)
                    n->sIndex = ret;
                else if((n->sIndex == -2 && ret == -3) ||
                    (n->sIndex == -3 && ret == -2) || 
                    n->sIndex == -4)
                {
                    n->sIndex = -4;
                    if(*maxHeight < labelHeight)
                    {
                        *maxHeight = labelHeight;
                        *substringStartIndex = *(n->end) - 
                            labelHeight + 1;
                    }
                }
            }
        }
    }
    else if(n->sIndex > -1 && n->sIndex < size1)
        return -2;
    else if(n->sIndex >= size1)
        return -3;
    return n->sIndex;
}
 
int lcs()
{
    int maxHeight = 0;
    int substringStartIndex = 0;
    traverse(root, 0, &maxHeight, &substringStartIndex);
    return maxHeight;
}

int main()
{
    int n,q,temp;
	string test;
	vector<string> s;
	cin >> n ;
	fr(i,0,n)
	{
		cin >> test;
		s.pb(test);
	}
	cin >> q ;
	fr(i,0,q)
	{
		cin >> test ;
		int max = 0 ;
		fr(i,0,n)
		{
			size1 = test.length() + 1 ;
			text = test+'-'+s[i]+'@';
			creatSTREE();
			temp = lcs();
			freeSTREE(root);
			if(temp > max)
				max = temp;
		}
		cout << max << endl ;
	}
    return 0;
}

