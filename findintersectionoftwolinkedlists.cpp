
#include <unordered_set>

int findIntersection(Node *firstHead, Node *secondHead)
{
    
    Node *firstHeadTmp = firstHead;

 
    unordered_set<Node *> referenceSet;

    
    while (firstHeadTmp != NULL)
    {
        referenceSet.insert(firstHeadTmp);
        firstHeadTmp = firstHeadTmp->next;
    }

    Node *secondHeadTmp = secondHead;

    
    while (secondHeadTmp != NULL)
    {
        if (referenceSet.find(secondHeadTmp) != referenceSet.end())
        {
            return secondHeadTmp->data;
        }
        secondHeadTmp = secondHeadTmp->next;
    }

    return -1;
}
