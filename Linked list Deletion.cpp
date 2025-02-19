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
    ptr->next=NULL;
}

void Display (node *ptr){
    printf("\nElements in the Link list are: \n");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->num);
        ptr= ptr->next;
    }
    cout <<endl;
}

void Delete(node *start)
{
    if (pos < 1 || pos > n + 1)
    {
        cout << "Invalid position. Choose from position 1 to " << n << endl;
        return;
    }

    if (pos == 1)
    {
        node *ptr = start;
        start = ptr->next;
        item = ptr->num;
        free(ptr);
    }
    else
    {
        node *prev = start, *current = start;
        for (int i = 1; i < pos; i++)
        {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        item = current->num;
        free(current);
    }

    n--;
    cout << "\nItem deleted = " << item << endl;

    cout << "After deleting ";
    Display(start);
}

int main()
{
    node *start, *ptr;

    start = (node *) malloc(sizeof(node));
    LinkedList_creation(start);
    Display(start);

    cout << "Enter position to insert : ";
    cin >> pos;

    Delete(start);

    return 0;
}
