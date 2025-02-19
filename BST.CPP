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

struct nodeType *inOrderPredecessor(struct nodeType* root){
    root = root->left;
    while (root->right!=NULL){
        root = root->right;
    }
    return root;
}

struct nodeType *deleteNode(struct nodeType *root, int value){

    struct nodeType* iPre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){
        free(root);
        return NULL;
    }

    //searching for the node to be deleted
    if (value < root->info){
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->info){
        root->right = deleteNode(root->right, value);
    }
    //deletion strategy when the node is found
    else{
        iPre = inOrderPredecessor(root);
        root->info = iPre->info;
        root->left = deleteNode(root->left, iPre->info);
    }
    return root;
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

    cout << "\nBefore deleting element Tree : ";
    inOrder(root);

	cout << endl << "Enter element to delete : ";
	cin >> item;
	cout << endl;
	deleteNode(root, item);
	cout << "Element deleted from tree = " << item << endl;
	cout << "After deleting element Tree : ";
	inOrder(root);

	return 0;
}

