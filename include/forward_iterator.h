#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "iterator.h"

template <typename T>
class ForwardIterator: public Iterator <T> {
public:
  ForwardIterator (): Iterator <T> () {};
  ForwardIterator (Node<T>* node): Iterator <T> (node) {};

  ForwardIterator <T> operator = (ForwardIterator <T> other) {}

  bool operator != (ForwardIterator <T> other) {}

  ForwardIterator <T> operator ++ () {}

  T operator * () {}
};

#endif
