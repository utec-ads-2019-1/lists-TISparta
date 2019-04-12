#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
  T data;
  Node <T>* next = 0;
  Node <T>* prev = 0;
  Node () {}
  Node (T data): data(data) {}
  ~Node () {}
  void killAll () {
    if (next) next -> killAll();
    delete this;
  }
};

#endif
