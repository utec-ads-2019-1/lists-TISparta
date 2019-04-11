#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "iterator.h"

template <typename T>
class BidirectionalIterator : public Iterator <T> {
public:
  BidirectionalIterator (): Iterator <T> () {};
  BidirectionalIterator (Node<T> *node): Iterator <T> (node) {};

  BidirectionalIterator <T> operator = (BidirectionalIterator <T> other) {}

  bool operator != (BidirectionalIterator <T> other) {}

  BidirectionalIterator <T> operator ++ () {}

  BidirectionalIterator <T> operator -- () {}

  T operator * () {}
};

#endif
