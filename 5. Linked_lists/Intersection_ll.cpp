//Create an intersection in two ll
//finding the point of intersection of two lls


#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
void InsertAtEnd(Node *&head, int val)
{
    Node *n, *temp = head;
    n = new Node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void Display(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int Length(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void CreateIntersection(Node *&head1, Node *&head2, int pos)
{
    Node *temp1 = head1, *temp2 = head2;
    int count = pos-1;
    while (count--)
    {
        temp1 = temp1->next;
    }
    while (temp2->next)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

int PointOfIntersection(Node *&head1, Node *&head2)
{
    int l1 = Length(head1);
    int l2 = Length(head2);
    Node *ptr1, *ptr2;
    int d;
    if (l1 > l2)
    {
        ptr1 = head1;
        ptr2 = head2;
        d = l1 - l2;
    }
    else
    {
        ptr2 = head1;
        ptr1 = head2;
        d = l2 - l1;
    }
    while (d--)
    {
        // if(ptr1==NULL)
        //     return -1;
        ptr1 = ptr1->next;
    }
    while (ptr1 && ptr2)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    int arr1[5] = {1, 2, 3, 4, 7};
    int arr2[2] = {6, 5};
    for (int i = 0; i < 5; i++)
    {
        InsertAtEnd(head1, arr1[i]);
    }
    for (int i = 0; i < 2; i++)
    {
        InsertAtEnd(head2, arr2[i]);
    }
    CreateIntersection(head1, head2, 4);
    Display(head1);
    Display(head2);
    cout << PointOfIntersection(head1, head2) << endl;
    return 0;
}
