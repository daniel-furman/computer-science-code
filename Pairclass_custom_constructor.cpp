/* Class Pair has already been declared
 * as shown:
 *
 * class Pair {
 * public:
 *   int *pa,*pb;
 *   Pair(int, int);
 *   Pair(const Pair &);
 *  ~Pair();
 * };
 *
 */

Pair::Pair(int a, int b){
  pa = new int;
  *pa = a;
  pb = new int;
  *pb = b;
  std::cout << "custom constructor invoked" << std::endl;
}

Pair::Pair(const Pair& other){
  pa = new int;
  *pa = *(other.pa);
  pb = new int;
  *pb = *(other.pb);

  std::cout << "copy constructor invoked" << std::endl;
}

Pair::~Pair(){
  delete pa;
  delete pb;
  std::cout << "deconstructor invoked" << std::endl;
}

int main() {
  Pair p(15,16);
  Pair q(p);
  Pair *hp = new Pair(23,42);
  delete hp;

  std::cout << "If this message is printed,"
    << " at least the program hasn't crashed yet!\n"
    << "But you may want to print other diagnostic messages too." << std::endl;
  return 0;
};
