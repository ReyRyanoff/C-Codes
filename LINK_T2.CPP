#include<stdio.h>
#include<stdlib.h>
#define NULL 0

struct linked_list
{
    int num;
    struct linked_list *next;
};
typedef struct linked_list node;

int main()
{
    int n,ch;
    node *start, *ptr;

    start = (node *) malloc(sizeof(node));
    ptr=start;

    while(1)
    {
        printf("input a number: ");
        scanf("%d",&ptr->num);

        printf("Again? (1/0)");
        scanf("%d",&ch);
        if (ch==0)
        {
            ptr->next = NULL;
            break;
        }
        ptr->next=(node *)malloc(sizeof(node));
        ptr=ptr->next;
    }

    printf("\nElements in the Link list are: \n");
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->num);
        ptr= ptr->next;
    }

    return 0;
}
