#include<iostream>
using namespace std;
#define SIZE 5

int stack[SIZE+1],top=0;

int menu(void)
{
    int choice;
    do
    {
        cout<<("\n1-push\n2-pop\n0-Exit\n");
        cout<<("Enter your choice: ");
        cin>>choice;
        if(choice<0||choice>2)
            cout<<("\nWrong...Choice again...\n");
    }
    while(choice<0||choice>2);
    return (choice);
}

void push()
{
    int item;
    if(top == SIZE){
        cout<<"Stack overflow!"<<endl;
    }
    else{
        cin>>item;
        top++;
        stack[top] = item;
        cout<<item<<endl;
    }
   

}
void pop()
{
    int item;
    if(top == 0){
        cout<<"Stack underflow!"<<endl;
    }
    else{
        item = stack[top];
        top--;
        cout<<item<<endl;
    }
}

void display()
{
   if(top == 0){
    cout<<"Stack empty";
   }
   else{
    cout<<"elements are"<<endl;
    for (int i = 1; i <= top; i++)
    {
        cout<<stack[i]<<" ";
    }
   
   }
}

int main()
{
    int choice;

    do
    {
        choice=menu();
        switch(choice)
        {
        case 1:
            push();
            display();
            break;
        case 2:
            pop();
            display();
            break;
        case 0:
            cout<<"End of operation\n";
            break;
        }
    }
    while(choice!=0);
    return 0;
}
