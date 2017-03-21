#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

void serialize(Node *root,vector<int> &);



Node * deSerialize(vector<int> &);

void serialize(Node *root,vector<int> &A)
{
	// cout << "Call " << A.size() << endl;
    if(root==NULL)
        return ;
    A.push_back(root->data);
    serialize(root->left,A);
    serialize(root->right,A);
}

int pointer = 0 ;

Node * deSerialize(vector<int> &A)
{
	// cout << " pointer  " << pointer << endl ;
    if(pointer==A.size())
    {
    	// pointer = 0 ;
        return NULL;
    }
    else if(pointer > A.size())
    	{
    		pointer = 0 ;
    		return NULL;
    	}
    Node *head = new Node();
    head->data = A[pointer]; pointer++; 
    // cout << "Head " << head->data << endl ;
    head->left = deSerialize(A) ;
    head->right = deSerialize(A) ;
    return head;
}


/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     int N = n;
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
    vector<int> A;
    A.clear();
    serialize(root,A);
   for(int i=0;i<A.size();i++)
       cout<<A[i]<<" ";
       cout<<endl;
    inorder(root);
     cout<<endl;
    Node *tree_made = deSerialize(A);
    inorder(tree_made);
    cout<<endl;
  }
  return 0;
}
