/* 
 *
 * class sumPair : public Pair {
 * public:
 *   int sum;
 *   sumPair(int,int);
 * };
 *
 * Implement the constructor
 * sumPair(int,int) 
 * loads two member variables of
 * the base Pair class with its
 * arguments, and initializes the
 * member variable sum with their sum.
 */

sumPair::sumPair(int a,int b) : Pair (a,b) {
  sum = a+b;
}

int main() {
  sumPair sp(15,16);
  std::cout << "sp(15,16).sum =" << sp.sum << std::endl;
  return 0;
}
