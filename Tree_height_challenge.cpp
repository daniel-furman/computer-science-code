int count(Node *n) {
  // Implement count() here.
  // Base case, empty tree:
  if (n == nullptr) {
    return 0;
  }
  // recursion call, count left and right subtrees
  else {
    return 1 + count(n -> right) + count(n -> left);
  }
}

int main() {
  Node *n = new Node();
  n->left = new Node();
  n->right = new Node();
  n->right->left = new Node();
  n->right->right = new Node();
  n->right->right->right = new Node();
  std::cout << count(n) << std::endl;
  delete n;
  n = nullptr;

  return 0;
}
