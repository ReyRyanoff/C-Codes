#include<bits/stdc++.h>
using namespace std;
#define NULL 0

struct linked_list
{
    int num;
    struct linked_list *next;
};
typedef struct linked_list node;

int main()
{
    int n,i,item;
    node *start, *ptr;

    start = (node *) malloc(sizeof(node));
    ptr=start;

    cout << "How many elements: ";
    cin >> n;

    for(i=1; i<=n; i++)
    {
        cout << "input a number: ";
        scanf("%d",&ptr->num);
        if(i!=n)
        {
            ptr->next=(node *)malloc(sizeof(node));
            ptr=ptr->next;
        }
    }
    ptr->next=NULL;

    printf("\nElements in the Link list are: \n");
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->num);
        ptr= ptr->next;
    }
    cout << endl << "Enter item to search : ";

    ///Searching the item:
    cin >> item;
    int loc = 1;
    ptr=start;
    while(ptr!=NULL)
    {
        if(item == ptr->num){
            break;
        }
        else{
            ptr= ptr->next;
            loc++;
        }
    }
    if(loc <= n) cout << item << " found in " << loc << "th position" << endl;
    else cout << item << " not found" << endl;
    return 0;
}

