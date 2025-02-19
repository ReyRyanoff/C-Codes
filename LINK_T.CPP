#include<bits/stdc++.h>
using namespace std;
#define NULL 0

struct linked_list
{
    char name[10];
    int roll;
    double cgpa;
    struct linked_list *next;
};
typedef struct linked_list node;

int main()
{
    int n,i,item;
    node *start, *ptr;

    start = (node *) malloc(sizeof(node));
    ptr=start;

    cout << "Enter Number of students : ";
    cin >> n;

    for(i=1; i<=n; i++)
    {
        cout << "Enter student's name : ";
        ///gets(ptr->name);
        scanf("%s",&ptr->name);
        cout << "Enter student's roll : ";
        scanf("%d",&ptr->roll);
        cout << "enter student's cgpa : ";
        scanf("%lf",&ptr->cgpa);
        if(i!=n)
        {
            ptr->next=(node *)malloc(sizeof(node));
            ptr=ptr->next;
        }
    }
    ptr->next=NULL;

    printf("\nStudent list: \n");
    ptr=start;
    while(ptr!=NULL)
    {
        printf("Student name : %s",ptr->name);
        cout << endl;
        cout << "Student roll : " << ptr->roll << endl;
        cout << "Student CGPA : " << ptr->cgpa << endl;
        ptr= ptr->next;
    }

    return 0;
}

