#ifndef FORWARD_H
#define FORWARD_H

#include "iterators/forward_iterator.h"
#include "lists/list.h"

template <typename T>
class ForwardList: public List <T> {
public:
  ForwardList (): List <T> () {}

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
      Node <T>* tmp = (*this).at(this -> nodes - 2);
      delete this -> tail;
      this -> tail = tmp;
      this -> tail -> next = nullptr;
    }
    this -> nodes--;
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

  inline std::string name () const { return "Forward List"; }

  ForwardIterator <T> begin () const { return ForwardIterator <T> (this -> head); }

  ForwardIterator <T> end () const { return ForwardIterator <T> (nullptr); }

  void merge (ForwardList <T>& list) {
    if (list.empty()) return;
    if (this -> nodes == 0) {
      this -> head = list.head;
      this -> tail = list.tail;
    } else {
      this -> tail -> next = list.head;
      this -> tail = list.tail;
    }
    this -> nodes += list.nodes;
  }
};

#endif
