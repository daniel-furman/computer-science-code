

#pragma once
#include <iostream>
#include <string>

#include "LinkedList.h"

/********************************************************************
  insertOrdered
********************************************************************/

template <typename T>
void LinkedList<T>::insertOrdered(const T& newData) {

  // Make your new node on the heap
  Node *nn = new Node(newData);

  // Base case, empty list
  if (!head_){
    tail_ = nn;
    head_ = nn;
  }

  // Inserted number is greater than or equal to current entries
  else if (newData >= tail_ -> data){
    tail_ -> next = nn;
    nn -> prev = tail_;
    tail_ = nn;
  }

  // Inserted number is less than or equal to current entries
  else if (newData <= head_ -> data){
    head_ -> prev = nn;
    nn -> next = head_;
    head_ = nn;
  }

  // Inserted number is within the tail and head range
  else{
    Node *cn = head_ -> next;
    while (newData > cn -> data){
      cn = cn -> next;
    }
    // Found the spot to insert number
    nn -> next = cn;
    nn -> prev = cn -> prev;
    cn -> prev -> next = nn;
    cn -> prev = nn;
    cn = nn;
  }
  
  size_ += 1;
  return;
}

/********************************************************************
  Exercise 2: Linear-time Merge
 ********************************************************************/

template <typename T>
LinkedList<T> LinkedList<T>::merge(const LinkedList<T>& other) const {


  LinkedList<T> left = *this;
  LinkedList<T> right = other;
  LinkedList<T> merged;

  while(!right.empty() && !left.empty()){
    if(right.front() <= left.front()){
      merged.pushBack(right.front());
      right.popFront();
    }
    else{
      merged.pushBack(left.front());
      left.popFront();
    }
  }
  
  if(right.empty()){
    while(!left.empty()){
      merged.pushBack(left.front());
      left.popFront();
    }
  }
  
  else{
    while(!right.empty()){
      merged.pushBack(right.front());
      right.popFront();
    }
  }
  
  return merged;
}
