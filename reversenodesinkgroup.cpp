Node *getListAfterReverseOperation(Node *head, int n, int b[]) {
    
    if (head == NULL) {
        return NULL;
    }

    int idx = 0;

    Node *prev = NULL, *cur = head, *temp = NULL;
    Node *tail = NULL, *join = NULL;
    bool isHeadUpdated = false;

    
    while (cur != NULL && idx < n) {

      
        int K = b[idx];

        
        if (K == 0) {
            idx++;
            continue;
        }

        join = cur;
        prev = NULL;

       
        while (cur != NULL && K--) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

      
        if (isHeadUpdated == false) {
            head = prev;
            isHeadUpdated = true;
        }

        
        if (tail != NULL) {
            tail->next = prev;
        }

       
        tail = join;
        idx++;
    }

   
    if (tail != NULL) {
        tail->next = cur;
    }

   
    return head;
}
