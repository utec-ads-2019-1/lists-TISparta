#ifndef TESTER_H
#define TESTER_H

#include "mocker.h"
#include "forward.h"
#include "linked.h"
#include "circular.h"

#define NUMBER_OF_TESTS 1

enum Collection { forward_list, linked_list, circular_list };

class Tester {
private:
  template <typename T>
  static List <T>* getCollection (Collection);

  template <typename T>
  static void testList (Collection collection);

  template <typename T>
  static bool isSorted (List <T>*);

  template <typename T>
  static void print (List <T>*);

  template <typename T>
  static void testSpecifics (Collection, List <T>*);

  template <typename T>
  static void testForward (ForwardList <T>*);

  template <typename T>
  static void testLinked (LinkedList <T>*);

  template <typename T>
  static void testCircularLinked (CircularLinkedList <T>*);

public:
  static void execute ();
};

#endif
