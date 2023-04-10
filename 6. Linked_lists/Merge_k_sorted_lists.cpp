#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// struct myCmp
// {
//     bool operator()(ListNode *a, ListNode *b)
//     {
//         return a->val > b->val;
//     }
// };

auto cmp = [](const ListNode &a, const ListNode &b) -> bool // Lambda function
{
    return a.val > b.val;
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<ListNode *, vector<ListNode *>, greater<ListNode *>> pq;
    for (ListNode *x : lists)
    {
        if (x)
        {
            pq.push(x);
        }
    }

    ListNode *head = NULL, *tail = NULL;
    while (!pq.empty())
    {
        ListNode *x = pq.top();
        pq.pop();

        if (!head)
        {
            head = x;
            tail = x;
        }
        else
        {
            tail->next = x;
            tail = tail->next;
        }
        if (x->next)
        {
            pq.push(x->next);
        }
    }
    return head;
}
