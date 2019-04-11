#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "bidirectional_iterator.h"

template <typename T>
class LinkedList: public List <T> {
public:
 LinkedList (): List <T>() {}

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

 inline std::string name () { return "Linked List"; }

 BidirectionalIterator <T> begin () {}

 BidirectionalIterator <T> end () {}

 void merge (LinkedList <T> list) {}
};

#endif
