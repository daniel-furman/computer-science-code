
#pragma once
#include <iostream>
#include <string>
#include "GenericTree.h"

/*******************************************************************
  Populate a tree by completing the treeFactory function.
  ****************************************************************/


static void treeFactory(GenericTree<int>& tree) {

  tree.clear();
  // Create root node for GenericTree<int>:
  GenericTree<int>::TreeNode* n_root = tree.getRootPtr();
  tree.createRoot(4);
  // Children nodes:
  auto n_eight = tree.getRootPtr()->addChild(8);
  tree.getRootPtr()->addChild(15);
  auto n_sixteen = n_eight->addChild(16);
  n_eight->addChild(23);
  n_sixteen->addChild(42);
  return;
}


static void treeFactoryTest() {
  std::cout << std::endl;
  std::cout << "------------------------------" << std::endl;
  std::cout << "EXERCISE 1: treeFactoryTest" << std::endl;
  std::cout << "The output should match what you see in the code comments" << std::endl << std::endl;

  GenericTree<int> tree(9999);
  treeFactory(tree);
  std::cout << tree << std::endl;
}

// -------------------------------------------------------------------
// Breadth-first vs. Depth-first Search Strategies
// -------------------------------------------------------------------

// countNullChildrenRecursive:
template <typename N>
int countNullChildrenRecursive(N* subtreeRoot) {

  // Base case: If the root of this subtree itself is null, then return 1.
  if (!subtreeRoot) return 1;

  int nullChildrenSum = 0;

  // Iterate over the list of children and recurse on each subtree.
  for (auto childPtr : subtreeRoot->childrenPtrs) {

    // Increment the sum by the result of recursing on this child's subtree.
    nullChildrenSum += countNullChildrenRecursive(childPtr);

  }

  // Return the sum.
  return nullChildrenSum;
}

template <typename N>
int countNullChildrenIterative(N* subtreeRoot) {

  int nullChildrenSum = 0;

  // Stack of node pointers that we still need to explore (constructed empty)
  std::stack<N*> nodesToExplore;

  // Begin by pushing our subtree root pointer onto the stack
  nodesToExplore.push(subtreeRoot);

  // Loop while there are still nodes to explore
  while (!nodesToExplore.empty()) {

    // Make a copy of the top pointer on the stack, then pop it to decrease the stack
    N* topNode = nodesToExplore.top();
    nodesToExplore.pop();

    if (!topNode) {
      // If the top node pointer is null, then we must not dereference it.
      // Just increment the null counter, then "continue" to jump back to the top of the loop.
      nullChildrenSum++;
      continue;
    }

    // If the node exists, it may have children pointers. Let's iterate
    // through the childrenPtrs vector and push copies of those pointers
    // onto the exploration stack.
    for (auto childPtr : topNode->childrenPtrs) {
      nodesToExplore.push(childPtr);
    }

  }

  // Return the sum.
  return nullChildrenSum;
}

/*******************************************************************
  Implements level-order traversal in the traverseLevels function.

  
// traverseLevels: 
*/
template <typename T>
std::vector<T> traverseLevels(GenericTree<T>& tree) {

  // This defines a type alias for the appropriate TreeNode dependent type.
  // This might be convenient.
  using TreeNode = typename GenericTree<T>::TreeNode;

  // Now you can refer to a pointer to a TreeNode in this function like this.
  // TreeNode* someTreeNodePointer = nullptr;

  // This is the results vector you need to fill.
  std::vector<T> results;

  auto rootNodePtr = tree.getRootPtr();
  if (!rootNodePtr) return results;
  std::vector<TreeNode *> next_level_childPtrs;
  std::vector<TreeNode *> childPtrs;
  childPtrs = rootNodePtr->childrenPtrs;
  results.push_back(rootNodePtr->data);

  while(childPtrs.size() != 0){
    next_level_childPtrs.clear();
    for(std::size_t w = 0; w < childPtrs.size(); w++){
      T ch_data = childPtrs[w]->data;
      results.push_back(ch_data);

      for( std::size_t p = 0 ; p < childPtrs[w]->childrenPtrs.size() ; p++){
        next_level_childPtrs.push_back(childPtrs[w]->childrenPtrs[p]);

      }
    }
    childPtrs.clear();
    childPtrs = next_level_childPtrs;
  }

  return results;
}

// traversalTest:
static void traversalTest() {
  std::cout << std::endl;
  std::cout << "------------------------------" << std::endl;
  std::cout << "EXERCISE 2: traversalTest" << std::endl;
  std::cout << "Testing your traverseLevels function" << std::endl  << std::endl;

  {
    // This is the tree from exampleTree1() in main.cpp
    std::cout << "[Test 1] Expected output:" << std::endl
      << "A B E C D F G" << std::endl;
    GenericTree<std::string> tree1("A");
    auto nodeA = tree1.getRootPtr();
    auto nodeB = nodeA->addChild("B");
    nodeB->addChild("C");
    nodeB->addChild("D");
    auto nodeE = nodeA->addChild("E");
    nodeE->addChild("F");
    nodeE->addChild("G");
    std::vector<std::string> tree1_results = traverseLevels(tree1);
    std::cout << "Your traverseLevels output:" << std::endl;
    for (auto result : tree1_results) {
      std::cout << result << " ";
    }
    std::cout << std::endl << std::endl;
  }

  {
    // This is the tree from exampleTree2() in main.cpp
    std::cout << "[Test 2] Expected output:" << std::endl
      << "A B D J K C E I L F G M H" << std::endl;
    GenericTree<std::string> tree2("A");
    auto A = tree2.getRootPtr();
    A->addChild("B")->addChild("C");
    auto D = A->addChild("D");
    auto E = D->addChild("E");
    E->addChild("F");
    E->addChild("G")->addChild("H");
    D->addChild("I");
    A->addChild("J");
    auto L = A->addChild("K")->addChild("L");
    L->addChild("M");
    std::vector<std::string> tree2_results = traverseLevels(tree2);
    std::cout << "Your traverseLevels output:" << std::endl;
    for (auto result : tree2_results) {
      std::cout << result << " ";
    }
    std::cout << std::endl << std::endl;
  }

  {
    // This is the tree you should have built for the first part of this
    // assignment above, with treeFactory.
    std::cout << "[Test 3] Expected output:" << std::endl
      << "4 8 15 16 23 42" << std::endl;
    GenericTree<int> tree3(9999);
    treeFactory(tree3);
    std::vector<int> tree3_results = traverseLevels(tree3);
    std::cout << "Your traverseLevels output:" << std::endl;
    for (auto result : tree3_results) {
      std::cout << result << " ";
    }
    std::cout << std::endl << std::endl;
  }

}
