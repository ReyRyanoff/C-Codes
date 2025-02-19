#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* head = 0;
int SIZE = 0;
/// 7 3 1 5
void addFirst(int item)
{
    /// Node nn;
    Node *nn = new Node;
    (*nn).data = item;

    nn->next = head;

    head = nn;
    SIZE++;
}
void addLast(int item)
{
    Node* nn = new Node;
    nn->data = item;
    nn->next = 0;
    SIZE++;
    if(head == NULL) {
        head = nn;
        return;
    }

    Node* ptr = head;
    while(ptr->next != 0)
    {
        ptr = ptr->next;
    }
    ptr->next = nn;
}

void Insert(int pos, int item)
{
    if(pos == 1) {
        addFirst(item);
    }
    else if(pos == SIZE + 1) {
        addLast(item);
    }
    else {
        Node* nn = new Node;
        nn->data = item;
        Node* prev = head;

        for(int i = 1; i <= pos - 2; i++)
            prev = prev->next;

        Node* cur = prev->next;

        prev->next = nn;
        nn->next = cur;
        SIZE++;
    }
}
void Print()
{
    Node* ptr = head;
    while(ptr){
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}
/// 13 5 100 10
int main()
{
    addFirst(10);
    addLast(9);
    addLast(199);
    Print();

    return 0;
}

