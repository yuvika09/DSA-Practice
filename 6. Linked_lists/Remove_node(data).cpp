// Given the head of a linked list and an integer val,
// remove all the nodes of the linked list that has Node.val == val, and return the new head.

//Create a dummyNode and start from it while checking all the nodes 

ListNode *removeElements(ListNode *head, int val)
{
    if (head == NULL)
        return head;
    ListNode *dummyNode = new ListNode(-1);
    dummyNode->next = head;
    ListNode *prev = dummyNode, *curr = head, *toDel;
    while (curr)
    {
        if (curr->val == val)
        {
            toDel = curr;
            prev->next = curr->next;
        }
        else
        {
            prev = curr;
        }
        curr = curr->next;
    }
    return dummyNode->next;
}

