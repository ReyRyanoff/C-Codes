/// Write a program to show the insert and delete operations of a circular queue.

#include <bits/stdc++.h>
using namespace std;
#define Size 5
int circ_queue[Size + 1], front, rear;
int n = Size, item;

void Display()
{
    cout << "Queue : ";
    if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
        {
            int x = circ_queue[i];
            cout << x << " ";
        }
    }
    else
    {
        for (int i = front; i <= n; i++)
        {
            int x = circ_queue[i];
            cout << x << " ";
        }
        for (int i = 1; i <= rear; i++)
        {
            int x = circ_queue[i];
            cout << x << " ";
        }
    }

    cout << endl
         << endl;
    return;
}

void QInsert()
{
    if ((front == 1) && (rear == n))
    {
        cout << "Overflow" << endl;
        return;
    }
    if (front == 0)
    {
        front++;
        rear++;
    }
    else if (rear == n)
        rear = 1;
    else
        rear++;
    cout << "Enter value to insert in the Queue : ";
    cin >> item;
    circ_queue[rear] = item;
    cout << endl
         << "Element Inserted" << endl;
    cout << "After Inserting ";
    Display();
    return;
}

void QDelete()
{
    if (front == 0)
    {
        cout << "Underflow" << endl;
        return;
    }
    item = circ_queue[front];
    if (front == rear)
    {
        front = 0;
        rear = 0;
    }
    else if (front == n)
        front = 1;
    else
        front++;
    cout << endl
         << "Element Deleted : " << item << endl;
    cout << "After Deleting ";
    Display();
    return;
}

int main()
{
    front = 0;
    rear = 0;
    int x;
    while (1)
    {
        cout << "Enter your choice : ";
        cin >> x;
        if (x == 1)
        {
            QInsert();
        }
        else if (x == 2)
        {
            QDelete();
        }
        else
        {
            cout << "Exiting...." << endl;
            break;
        }
    }
    return 0;
}
