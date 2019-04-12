#ifndef FORWARD_H
#define FORWARD_H

#include <stdexcept>
#include <exception>
#include <algorithm>

#include "list.h"
#include "forward_iterator.h"

// TO DELETE
#include <iostream>

template <typename T>
class ForwardList: public List <T> {
public:
  ForwardList (): List <T> () {}

  T front () {
    if (!this -> head) {
      throw std::runtime_error("The list is empty");
    }
    return this -> head -> data;
  }

  T back () {
    if (!this -> head) {
      throw std::runtime_error("The list is empty");
    }
    return this -> tail -> data;
  }
  
  void push_front (T value) {
    Node <T>* newNode = new Node <T> (value);
    if (this -> nodes == 0) {
      this -> head = newNode;
      this -> tail = this -> head;
    } else {
      newNode -> next = this -> head;
      this -> head = newNode;
    }
    this -> nodes++;
  }
  
  void push_back (T value) {
    Node <T>* newNode = new Node <T> (value);
     if (this -> nodes == 0) {
       this -> tail = newNode;
       this -> head = this -> tail;
    } else {
      this -> tail -> next = newNode;
      this -> tail = newNode;
    }
    this -> nodes++;
  }

  void pop_front () {
    if (this -> nodes == 0) {
      throw std::runtime_error("The list is empty"); 
    }
    if (this -> nodes == 1) {
      delete this -> head;
      this -> head = this -> tail = nullptr;
    } else {
      Node <T>* tmp = this -> head -> next;
      delete this -> head;
      this -> head = tmp;
    }
    this -> nodes--;
  }

  void pop_back () {
    if (this -> nodes == 0) {
      throw std::runtime_error("The list is empty"); 
    }
    if (this -> nodes == 1) {
      delete this -> tail;
      this -> tail = this -> head = nullptr;
    } else {
      Node <T>* tmp = this -> head;
      for (int i = 0; i < this -> nodes - 2; i++) {
        tmp = tmp -> next;
      }
      delete this -> tail;
      this -> tail = tmp;
    }
    this -> nodes--;
  }

  Node <T>* at (int index) {
    if (not (0 <= index and index < this -> nodes)) {
      throw std::out_of_range("The index is out of range");
    }
    Node <T>* tmp = this -> head;
    for (int i = 0; i < index; i++) {
      tmp = tmp -> next;
    }
    return tmp;
  }

  T operator [] (int index) {
    return (*this).at(index) -> data;
  }

  bool empty () { return (this -> nodes == 0); }

  int size () { return this -> nodes; }

  void clear () {
    this -> head -> killAll();
    this -> head = this -> tail = 0;
    this -> nodes = 0;
  }

  void sort () {
    for (int i = 0; i < this -> nodes; i++) {
      for (int j = i + 1; j < this -> nodes; j++) {
        if ((*this)[i] > (*this)[j]) {
          std::swap((*this).at(i) -> data, (*this).at(j) -> data);
        }
      }
    }
  }

  void reverse () {
    if (this -> nodes <= 1) return;
    Node <T>* prev = nullptr;
    Node <T>* cur = this -> head;
    Node <T>* tmp = new Node <T> ();
    for (int i = 0; i < this -> nodes; i++) {
      tmp = cur -> next;
      cur -> next = prev; 
      prev = cur;
      cur = tmp;
    }
    std::swap(this -> head, this -> tail);
  }

  inline std::string name () { return "Forward List"; }

  ForwardIterator <T> begin () {}

  ForwardIterator <T> end () {}

  void merge (ForwardList <T> list) {}
};

#endif
