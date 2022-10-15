#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

// Create A class node

class node
{
public:
    int data;
    node *next;

    // Node Class Constructor
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
// Insert At Head

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    if (head==NULL)
    {
        n->next= n;
        head=n;
        return;
    }
    node*temp= head;
    while (temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next= n;
    n->next=head;
    head=n;
}

// Insert Element At Tail

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next= head;
}



// Display All Element

void display(node *head)
{
    node *temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    }while(temp!=head);
    cout << "NULL" << endl;
}

// Deleting in LL
void deletehead(node* &head)
{
    node*temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    node* todelete= head;
    temp->next= head->next;
    head= head->next;
    delete todelete;
}

void deletion(node* &head, int pos)
{
    if (pos==1)
    {
        deletehead(head);
        return;
    }
    
    node*temp=head;
    int count=1;
    while(count!=(pos-1))
    {
        temp= temp->next;
        count++;
    }
    node* todelete= temp->next;
    temp->next= temp->next->next;
    delete todelete;
}

int main()
{

    node *head = NULL;
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    display(head);
    
    insertAtHead(head, 55);
    display(head);

    deletehead(head);
    display(head);

    deletion(head, 3);
    display(head);
    
    
    return 0;
}