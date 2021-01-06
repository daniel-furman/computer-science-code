#include <iostream>

class Pair {
public:
  int first, second;
  void check() {
    first = 5;
    std::cout << "Congratulations! The check() method of the Pair class \n has executed. (But, this isn't enough to guarantee \n that your code is correct.)" << std::endl;
  }
};

Pair * pairFactory() {
  Pair *p = new Pair;
  std::cout << "The function returns p :" << std::endl;
  std::cout << p << std::endl;
  return p;
}

int main() {
  Pair *p;
  p = pairFactory();

  // This function call should work without crashing:
  p->check();

  // Deallocating the heap memory. (Assuming it was made on the heap!)
  delete p;

  std::cout << "If you can see this text, the system hasn't crashed yet!" << std::endl;

  return 0;
}
