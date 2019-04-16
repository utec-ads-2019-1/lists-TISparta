#ifndef ITERATOR_H
#define ITERATOR_H

#include <stdexcept>
#include <exception>
#include "node.h"

template <typename T>
class ForwardIterator {
protected:
 Node <T>* current;

public:
  ForwardIterator (): current(nullptr) {};
  ForwardIterator (Node <T>* node): current(node) {};
  T operator * () { return this -> current -> data; };
  bool operator != (ForwardIterator <T> other) { return &(this -> current) != &(other.current); }
  ForwardIterator <T> operator = (ForwardIterator <T> other) { this -> current = other.current; }
  ForwardIterator <T> operator ++ () {
    if (!this -> current) {
      throw std::runtime_error("The iterator has no data");
    }
    this -> current = this -> current -> next;
    return (*this);
  }
};

#endif
