#include<bits/stdc++.h>
using namespace std;
#define NULL 0

struct linked_list
{
    int num;
    struct linked_list * next;
};
typedef struct linked_list node;
int n,i,item, pos;

void LinkedList_creation(node *ptr){
    node *start = ptr;
    cout << "How many elements: ";
    cin >> n;
    cout << "input the values : ";
    for(i = 1; i <= n; i++)
    {
        scanf("%d",&ptr->num);
        if(i!=n)
        {
            ptr->next=(node *)malloc(sizeof(node));
            ptr=ptr->next;
        }
    }
    ptr->next=start;
}

void Display (node *ptr){
    node *head = ptr;
    printf("\nElements in the Link list are: \n");
    do
    {
        printf("%d ",ptr->num);
        ptr= ptr->next;
    }while(ptr != head);
    cout <<endl;
}

void insert(node *start)
{
    if ((pos < 1) || (pos > (n + 1)))
    {
        cout << "Invalid position. Choose position from 1 to " << n+1 << endl;
        return;
    }

    node *new_node = (node *)malloc(sizeof(node));
    new_node->num = item;

    if (pos == 1)
    {
        new_node->next = start;
        start = new_node;
    }

    else
    {
        node *ptr = (node *)malloc(sizeof(node));
        ptr = start;

        for (int i = 1; i < pos - 1; i++) ptr = ptr->next;

        new_node->next = ptr->next;
        ptr->next = new_node;
    }

    n++;
    cout << "After inserting ";
    Display(start);
}

int main()
{
    node *start, *ptr;

    start = (node *) malloc(sizeof(node));
    LinkedList_creation(start);
    Display(start);

    return 0;
}
