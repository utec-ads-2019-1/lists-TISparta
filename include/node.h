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
  void kill (int nodes) {
    if (nodes > 1) next -> kill(nodes - 1);
    delete this;
  }
};

#endif
