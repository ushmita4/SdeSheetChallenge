

int findCeil(BinaryTreeNode < int > * node, int x) {
  
  int ceil = -1;

  
  while (node != NULL) {

    
    if (x == node -> data) {
      return node -> data;
    }

    
    if (x > node -> data) {

      node = node -> right;
    }

   
    else {
      ceil = node -> data;
      node = node -> left;
    }
  }

 
  return ceil;

}
