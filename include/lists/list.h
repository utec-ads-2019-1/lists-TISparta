#ifndef LIST_H
#define LIST_H

#include <string>
#include <stdexcept>
#include <exception>
#include <algorithm>
#include "node.h"

template <typename T>
class List {
protected:
  Node <T>* head = 0;
  Node <T>* tail = 0;
  int nodes;

public:
  List (): head(nullptr), tail(nullptr), nodes(0) {};
  ~List () { (*this).clear(); }
  inline bool empty () const { return this -> nodes == 0; }
  inline int size () const { return this -> nodes; }
  T operator [] (int index) const { return (*this).at(index) -> data; }
  T front () const;
  T back () const;
  Node <T>* at (int) const;
  void clear ();
  void sort ();
  virtual void push_front (T) = 0;
  virtual void push_back (T) = 0;
  virtual void pop_front () = 0;
  virtual void pop_back () = 0;
  virtual void reverse () = 0;
  virtual std::string name () const = 0;
};

template <typename T>
T List <T>::front () const {
  if (!this -> head) {
    throw std::runtime_error("The list is empty");
  }
  return this -> head -> data;
}

template <typename T>
T List <T>::back () const {
  if (!this -> head) {
    throw std::runtime_error("The list is empty");
  }
  return this -> tail -> data;
}

template <typename T>
Node <T>* List <T>::at (int index) const {
  if (not (0 <= index and index < this -> nodes)) {
    throw std::out_of_range("The index is out of range");
  }
  Node <T>* tmp = this -> head;
  for (int i = 0; i < index; i++) {
    tmp = tmp -> next;
  }
  return tmp;
}

template <typename T>
void List <T>::clear () {
  if (this -> head) {
    this -> head -> kill(this -> nodes);
    this -> head = this -> tail = 0;
    this -> nodes = 0;
  }
}

template <typename T>
void List <T>::sort () {
  Node <T>* tmp = this -> head;
  T* arr = new T[this -> nodes];
  for (int i = 0; i < this -> nodes; i++) {
    arr[i] = tmp -> data;
    tmp = tmp -> next;
  }
  std::sort(arr, arr + this -> nodes);
  tmp = this -> head;
  for (int i = 0; i < this -> nodes; i++) {
    tmp -> data = arr[i];
    tmp = tmp -> next;
  }
  delete[] arr;
}

#endif
