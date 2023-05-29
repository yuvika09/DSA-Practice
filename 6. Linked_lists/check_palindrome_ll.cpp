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

class Solution
{
public:
    ListNode *reverseLL(ListNode *head)
    {
        ListNode *newHead = NULL;
        while (head)
        {
            ListNode *nxtptr = head->next;
            head->next = newHead;
            newHead = head;
            head = nxtptr;
        }
        return newHead;
    }

    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        ListNode *slow = head, *fast = head;

        // use hare and tortoise to find middle element
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the last half ll
        slow = reverseLL(slow);

        // compare nodes
        while (slow)
        {
            if (head->val != slow->val)
            {
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};