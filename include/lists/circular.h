#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "iterators/bidirectional_iterator.h"
#include "lists/list.h"

template <typename T>
class CircularLinkedList: public List <T> {
public:
  CircularLinkedList (): List <T> () {}

  void push_front (T value) {
    Node <T>* newNode = new Node <T> (value);
    if (this -> nodes == 0) {
      newNode -> next = newNode;
      newNode -> prev = newNode;
      this -> head = newNode;
      this -> tail = this -> head;
    } else {
      newNode -> next = this -> head;
      this -> head -> prev = newNode;
      this -> head = newNode;
      this -> head -> prev = this -> tail;
      this -> tail -> next = this -> head;
    }
    this -> nodes++;
  }

  void push_back (T value) {
    Node <T>* newNode = new Node <T> (value);
    if (this -> nodes == 0) {
      newNode -> next = newNode;
      newNode -> prev = newNode;
      this -> tail = newNode;
      this -> head = this -> tail;
    } else {
      newNode -> prev = this -> tail;
      this -> tail -> next = newNode;
      this -> tail = newNode;
      this -> head -> prev = this -> tail;
      this -> tail -> next = this -> head;
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
      this -> head -> prev = this -> tail;
      this -> tail -> next = this -> head;
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
      Node <T>* tmp = this -> tail -> prev;
      delete this -> tail;
      this -> tail = tmp;
      this -> head -> prev = this -> tail;
      this -> tail -> next = this -> head;
    }
    this -> nodes--;
  }

  void reverse () {
    if (this -> nodes <= 1) return;
    Node <T>* prev = this -> head -> prev;
    Node <T>* cur = this -> head;
    Node <T>* tmp = new Node <T> ();
    for (int i = 0; i < this -> nodes; i++) {
      tmp = cur -> next;
      cur -> next = prev; 
      cur -> prev = tmp;
      prev = cur;
      cur = tmp;
    }
    std::swap(this -> head, this -> tail);
  }

  std::string name () const { return "Circular Linked List"; }

  BidirectionalIterator <T> begin () const { return BidirectionalIterator <T> (this -> head); }

  BidirectionalIterator <T> end () const { return BidirectionalIterator <T> (nullptr); }

  void merge (CircularLinkedList <T>& list) {
    if (list.empty()) return;
    if (this -> nodes == 0) {
      this -> head = list.head;
      this -> tail = list.tail;
    } else {
      this -> tail -> next = list.head;
      list.head -> prev = this -> tail;
      this -> tail = list.tail;
      this -> head -> prev = this -> tail;
      this -> tail -> next = this -> head;
    }
    this -> nodes += list.nodes;
  }

};

#endif
