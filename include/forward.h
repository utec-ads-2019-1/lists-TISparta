#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "forward_iterator.h"

// Delete this after debug
#include <iostream>

template <typename T>
class ForwardList: public List <T> {
public:
  ForwardList (): List <T> () {
    std::cout << this -> head -> data << std::endl; 
  }

  T front () {}

  T back () {}

  void push_front (T value) {}

  void push_back (T value) {}

  void pop_front () {}

  void pop_back () {}

  T operator[] (int index) {}

  bool empty () {}

  int size () {}

  void clear () {}

  void sort () {}

  void reverse () {}

  inline std::string name () { return "Forward List"; }

  ForwardIterator <T> begin () {}

  ForwardIterator <T> end () {}

  void merge (ForwardList <T> list) {}
};

#endif
