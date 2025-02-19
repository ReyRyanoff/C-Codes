#include<bits/stdc++.h>
using namespace std;
#define NULL 0

struct linked_list
{
    int num;
    struct linked_list * next;
    struct linked_list * prev;
};
typedef struct linked_list node;
int n,i,item, pos;

node *head = (node *)malloc(sizeof(node));

void LinkedList_creation(){
    cout << "Enter number of inputs = ";
    cin >> n;

    node *ptr1 = NULL;
    node *ptr2;
    cout << "Enter the values : ";

    for (int i = 1; i <= n; i++)
    {
        ptr2 = (node *)malloc(sizeof(node));
        cin >> ptr2->num;

        ptr2->prev = ptr1;
        ptr2->next = NULL;

        if (ptr1 != NULL) ptr1->next = ptr2;
        else head = ptr2;

        ptr1 = ptr2;
    }
}

void Display (){
    node *ptr = head;
    printf("\nElements in the Two-way Link list are: \n");
    while(ptr != NULL)
    {
        printf("%d ",ptr->num);
        ptr= ptr->next;
    }
    cout <<endl;
}

int main()
{
    LinkedList_creation();
    Display();

    return 0;
}
