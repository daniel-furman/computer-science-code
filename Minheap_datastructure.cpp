/*
downHeap procedure for a min heap data structure,
represented as node-based tree.
*/

Node* lesser(Node *n){

  if(n->right != nullptr && n->left != nullptr){
    if (n->left->value >= n->right->value){
      return n->right;
    }
    else{
      return n->left;
    }
  }

  else if(n->right == nullptr && n->left != nullptr){
    return n->left;
  }

  else if(n->right != nullptr && n->left == nullptr){
    return n->right;
  }

  else{
    return nullptr;
  }
}


void downHeap(Node *n) {

  Node *n_lesser = lesser(n);

  if(n_lesser != nullptr){
    if(n->value > n_lesser->value){
      // swap the nodes
      int intermediate = n_lesser->value;
      n_lesser->value = n->value;
      n->value = intermediate;
      // recursion call
      downHeap(n_lesser);
    }
    else{
      return;
    }
  }
  return;
}

void printTree(Node *n) {
  if (!n) return;
  std::cout << n->value << "(";
  printTree(n->left);
  std::cout << ")(";
  printTree(n->right);
  std::cout << ")";
}

int main() {
  Node *n = new Node(100);
  n->left = new Node(1);
  n->right = new Node(2);
  n->right->left = new Node(3);
  n->right->right = new Node(4);
  n->right->right->right = new Node(5);

  downHeap(n);

  std::cout << "Compact printout:" << std::endl;
  printTree(n);
  std::cout << std::endl << "Vertical printout:" << std::endl;
  printTreeVertical(n);

  delete n;
  n = nullptr;

  return 0;
}
