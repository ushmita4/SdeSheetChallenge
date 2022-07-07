/*
    Time Complexity: O(N)
    Space Compexity: O(1)

    Where 'N' is the total nodes in Linked List.
*/

LinkedListNode<int> *removeKthNode(LinkedListNode<int> *head, int K)
{
    if (head == NULL || K == 0)
    {
        return head;
    }

    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;

    for (int i = 0; i < K; i++)
    {
        
        if (fast->next == NULL) {
            LinkedListNode<int> *next = head->next;
            head->next = NULL;
            head = next;

            return head;
        }
        else
        {
            fast = fast->next;
        }
    }

   
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    
    slow->next = slow->next->next;

    return head;
}
