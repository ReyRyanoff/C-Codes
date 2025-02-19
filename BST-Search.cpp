/* Binary Search Tree(BST) */

#include<bits/stdc++.h>
using namespace std;
struct nodeType
{
	int info;
	struct nodeType *left;
	struct nodeType *right;
 };
typedef struct nodeType *nodeptr;
nodeptr root;

void insertNode(int Item)
{
	nodeptr p , newNode, back;

	p = root;
	back=NULL;

	newNode = (nodeType *) malloc(sizeof(nodeType));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->info = Item;

	while (p!=NULL)
	{
		back=p;
		if (p->info > Item)
			p = p->left;
		else
			p = p->right;
	}

	if(back == NULL)
		root = newNode;
	else if (back->info > Item)
		back->left  = newNode;
	else back->right  = newNode;
}

void inOrder(nodeptr p)
{
	 if(p!=NULL)
	 {
	   inOrder(p->left);
	   printf("%d  ",p->info);
	   inOrder(p->right);
	 }
}

void preOrder(nodeptr p)
{
	 if(p!=NULL)
	 {
	   printf("%d  ",p->info);
	   preOrder(p->left);
	   preOrder(p->right);
	 }
}

void postOrder(nodeptr p)
{
	 if(p!=NULL)
	 {
	   postOrder(p->left);
	   postOrder(p->right);
	   printf("%d  ",p->info);
	 }
}

struct nodeType * search(struct nodeType *ROOT, int key){
    if(ROOT==NULL){
        return NULL;
    }
    if(key == ROOT->info){
        return ROOT;
    }
    else if(key < ROOT->info){
        return search(ROOT->left, key);
    }
    else{
        return search(ROOT->right, key);
    }
}

/*
void Display()
{
	if(root)
	{
		printf("\nTraverse Tree INorder\n");
		inOrder(root);
		printf("\nTraverse Tree PREorder\n");
		preOrder(root);
		printf("\nTraverse Tree POSTorder\n");
		postOrder(root);
	}
	else printf("\nBST IS NULL\n");
}
*/

int main()
{
	nodeptr p;
    root = NULL;
	int n, i, item;

	cout << "Enter number of elements = ";
	cin  >> n;
	cout << "Enter value of elements = ";
	for(i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertNode(x);
    }

	cout << endl << "Enter element to search : ";
	cin >> item;
	p = search(root, item);
	if(p == NULL){
        cout << "Item not found" << endl;
	}
	else cout << "Item found = " << p->info << endl;

	return 0;
}

