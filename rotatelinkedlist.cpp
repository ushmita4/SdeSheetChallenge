#include <bits/stdc++.h> 
/********************************

    Following is the class structure of the Node class:
    
    class Node
    {
    	public:
    	    int data;
    	    Node *next;
    	    Node(int data)
    	    {
    	        this->data = data;
    	        this->next = NULL;
    	    }
    };

********************************/


Node *rotate(Node *head, int k) {
     // Write your code here.
    if(head==NULL||head->next==NULL||k==0)
        return head;
    Node *temp=head;
    int l=1;
    while(temp->next!=NULL)
    {
        l++;
        temp=temp->next;
    }
    temp->next=head;
    k=k%l;
    int end=l-k;
    while(end--)
        temp=temp->next;
    
    head=temp->next;
    temp->next=NULL;
    
    return head;
    
}
