#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"
#include "bidirectional_iterator.h"

template <typename T>
class CircularLinkedList: public List <T> {
public:
  CircularLinkedList (): List <T>() {}

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

  std::string name () { return "Circular Linked List"; }

  BidirectionalIterator <T> begin () {}

  BidirectionalIterator <T> end () {}

  void merge (CircularLinkedList <T> list) {}
};

#endif
