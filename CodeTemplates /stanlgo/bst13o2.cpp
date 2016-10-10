//binary search trees complete implementation
//have some bugs for repeated no. deletion
#include <iostream>
#define Err 789
using namespace std;

typedef struct n
{
	int key;
	struct n *parent; 
	struct n *right; 
	struct n *left; 
}node;

class bst
{
public:
	bst();
	void insert(int);
	void tdelete(int);
	bool search(int);
	int predecessor(int);
	int successor(int);
	int max();
	int min();
	void printtree(node*);
private:
	node *root;
	node* searchhelper(node*,int);
};

bst::bst()
{
	root = NULL;
}

void bst::insert(int k)
{
	node *a = new node;
	a->key = k;
	a->right = NULL;
	a->left = NULL;
	if(root == NULL)
	{
		root = a ;
		root->parent = NULL;
	}
	else
	{
		node* parent = searchhelper(root,k); //cout << parent->key << endl ;
		if(k <= parent->key)
		{
			if(parent->left == NULL)
			{
				parent->left = a ;
				a->parent = parent ;
			}
			else
			{
				(parent->left)->parent = a ;
				a->left = parent->left ;
				a->parent = parent ;
				parent->left = a ;
			}
		}
		else if(k > parent->key )
		{
			if(parent->right == NULL)
			{
				parent->right = a;
				a->parent = parent ;
			}
			else
			{
				(parent->right)->parent = a ;
				a->right = parent->right ;
				a->parent = parent ;
				parent->right = a ;
			}

		}
	}
}

void bst::tdelete(int k)
{
	node *tmp = searchhelper(root,k); 
	if(tmp->key != k)
		cout << "ERROR: Key not present" << endl;
	else
	{	
		//no child case
		if(tmp->left == NULL && tmp->right == NULL)
		{
			if(tmp->parent == NULL)
				root = NULL;
			else if((tmp->parent)->key > tmp->key )
				(tmp->parent)->left = NULL ;
			else
				(tmp->parent)->right = NULL ;
		}
		//one child case
		else if(tmp->right == NULL && tmp->left != NULL)
		{
			if(tmp->parent == NULL)
				root = tmp->left ;
			else if((tmp->parent)->key > tmp->key )
			{
				(tmp->parent)->left = tmp->left;
				(tmp->left)->parent = tmp->parent ;
			}
			else
			{
				(tmp->parent)->right = tmp->left;
				(tmp->left)->parent = tmp->parent ;
			}
		}
		else if(tmp->left == NULL && tmp->right != NULL)
		{
			if(tmp->parent == NULL)
				root = tmp->right;
			else if((tmp->parent)->key > tmp->key )
			{
				(tmp->parent)->left = tmp->right;
				(tmp->right)->parent = tmp->parent ;
			}
			else
			{
				(tmp->parent)->right = tmp->right;
				(tmp->right)->parent = tmp->parent ;
			}
		}
		//both child case
		else
		{
			int pre = bst::predecessor(k);
			bst::tdelete(pre);
			tmp->key = pre ;
		}
	}
}

node* bst::searchhelper(node* n,int k)
{
	if(n->key == k)
		return n;
	else if(n->key > k)
	{
		if(n->left == NULL || (n->left)->key < k)
			return n;
		else
			return searchhelper(n->left,k);
	}
	else
	{
		if(n->right == NULL || (n->right)->key > k)
			return n;
		else
			return searchhelper(n->right,k);
	}
}

bool bst::search(int k)
{
	if(searchhelper(root,k)->key == k)
		return true;
	else
		return false;
}

int bst::min()
{
	node* tmp = root ;
	while(tmp->left != NULL)
		tmp = tmp->left;
	return tmp->key ;
}

int bst::max()
{
	node* tmp = root ;
	while(tmp->right != NULL)
		tmp = tmp->right;
	return tmp->key;
}

int bst::predecessor(int k)
{
	node* tmp = searchhelper(root,k);
	if(tmp->key < k )
		return tmp->key ; 
	if(tmp->left != NULL)
	{
		tmp = tmp->left;
		while(tmp->right != NULL)
			tmp = tmp->right;
		return tmp->key ;
	}
	else
	{
		while(tmp->parent != NULL)
		{
			if((tmp->parent)->key < k )
				return (tmp->parent)->key ;
			else
				tmp = tmp->parent;

		}
		return Err ;
	}	
}

int bst::successor(int k)
{
	node* tmp = searchhelper(root,k);
	if(tmp->key > k )
		return tmp->key ; 
	if(tmp->right != NULL)
	{
		tmp = tmp->right;
		while(tmp->left != NULL)
			tmp = tmp->left;
		return tmp->key ;
	}
	else
	{
		while(tmp->parent != NULL)
		{
			if((tmp->parent)->key > k )
				return (tmp->parent)->key ;
			else
				tmp = tmp->parent;

		}
		return Err ;
	}	
}

void bst::printtree(node* x)
{
	// prints elements in an increasing order
	if(x == NULL)
		bst::printtree(root);
	else
	{
		if (x->left != NULL)
			bst::printtree(x->left);
		cout << x->key << " " ; 
		if (x->right != NULL)
			bst::printtree(x->right);
	}
}

int main()
{
	bst b;
	int n,a;
	cin >> n;
	for(int i = 0 ; i < n ; i++ )
	{
		cin >> a;
		b.insert(a);
		//b.printtree(NULL); cout << endl ;
	}
	cout << "final tree" << endl;
	b.printtree(NULL); cout << endl ;

	cin >> a ; 
	b.tdelete(a);
	b.printtree(NULL) ; cout << endl ;
	return 0;
}