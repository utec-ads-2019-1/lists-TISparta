#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "forward_iterator.h"

template <typename T>
class BidirectionalIterator : public ForwardIterator <T> {
public:
  BidirectionalIterator (): ForwardIterator <T> () {};
  BidirectionalIterator (Node<T> *node): ForwardIterator <T> (node) {};
  BidirectionalIterator <T> operator -- () {
    if (!this -> current) {
      throw std::runtime_error("The iterator has no data");
    }
    this -> current = this -> current -> prev;
    return (*this);
  }
};

#endif
