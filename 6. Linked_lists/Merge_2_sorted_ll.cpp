// Recursive and iterative approaches for merging 2 sorted linked lists

#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Recursive Approach

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (!list1)
    {
        return list2;
    }
    if (!list2)
    {
        return list1;
    }
    if (list1->val >= list2->val)
    {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
    else
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
}

// Iterative Approach

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *p1 = list1;
    ListNode *p2 = list2;
    ListNode *dummyNode = new ListNode(-1);
    ListNode *p3 = dummyNode;

    while (p1 && p2)
    {
        if (p1->val < p2->val)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    while (p1)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }

    return dummyNode->next;
}
