

class Node {
public:
  int height; // to be set by computeHeight()
  Node *left, *right;
  Node() { height = -1; left = right = nullptr; }
  ~Node() {
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
  }
};

void computeHeight(Node *n) {

  if (n == nullptr) {
    // base case
    return;
  }

  else {
    // right node call
    computeHeight(n->right);
    // left node call
    computeHeight(n->left);

    // define variables
    Node *rn = n->right;
    Node *ln = n->left;

    // height zero leaf node
    if (rn == nullptr && ln == nullptr) {
      n->height = 0;
    }

    // else if only left subtree
    else if (rn == nullptr && ln != nullptr) {
      n->height = 1 + ln->height;
    }

    // else if only right subtree
    else if (rn != nullptr && ln == nullptr) {
      n->height = 1 + rn->height;
    }

    // else add deeper subtree
    else {
      if (rn->height >= ln->height) {
        n->height = 1 + rn->height;
      }
      else {
        n->height = 1 + ln->height;
      }
    }
    return;
  }
}

// This function prints the tree in a nested linear format.
void printTree(const Node *n) {
  if (!n) return;
  std::cout << n->height << "(";
  printTree(n->left);
  std::cout << ")(";
  printTree(n->right);
  std::cout << ")";
}

int main() {
  Node *n = new Node();
  n->left = new Node();
  n->right = new Node();
  n->right->left = new Node();
  n->right->right = new Node();
  n->right->right->right = new Node();

  computeHeight(n);

  printTree(n);
  std::cout << std::endl << std::endl;
  printTreeVertical(n);
  delete n;
  n = nullptr;

  return 0;
}
