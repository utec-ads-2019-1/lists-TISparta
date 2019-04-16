#include <iostream>
#include "test/tester.h"
#include "test/color.h"

struct Test {
  int correct = 0;
  int incorrect = 0;
  Test () {}
  ~Test () {}
  void init () { correct = incorrect = 0; }
  void showTestName (const string& testName) {
    std::cout << Color::bold << Color::underline << Color::blue << 
      "Running tests for " << testName << std::endl << Color::normal;
  }
  void showSubTestName (const string& testName) {
    std::cout << Color::bold << Color::cyan << testName << std::endl << Color::normal;
  }
  void showResults () {
    if (incorrect == 0) {
      std::cout << Color::bold << Color::green << 
        "All tests successfully passed" << std::endl << Color::normal;
    } else {
      std::cout << Color::bold << Color::green << correct <<
      " tests successfully passed" << std::endl << Color::normal;
      std::cout << Color::bold << Color::red << incorrect <<
      " tests failed" << std::endl << Color::normal;
    }
  }
  void check (bool condition, std::string message) {
    if (condition) {
      correct++; 
    } else {
      incorrect++;
      std::cout << Color::bold << Color::red << 
        "NO: " << message << std::endl << Color::normal;
    }
  }
} test;

void Tester::execute () {
  Collection collections[] = {
    forward_list,
    linked_list,
    circular_list
  };
  size_t numberOfCollections = sizeof(collections) / sizeof(collections[0]);
  for (int i = 0; i < int(numberOfCollections); i++) {
    List <int>* list = getCollection <int> (collections[i]);
    test.showTestName(list -> name());
    for (int j = 0; j < NUMBER_OF_TESTS; j++) {
      std::cout << "Running test " << j + 1 << std::endl;

      test.init();
      test.showSubTestName("For int");
      testList <int> (collections[i]);
      test.showResults();
      
      test.init();
      test.showSubTestName("For char");
      testList <char> (collections[i]);
      test.showResults();
    }
  }
}

template <typename T>
List <T>* Tester::getCollection (Collection collection) {
  switch (collection) {
    case forward_list: return new ForwardList <T> ();
    case linked_list: return new LinkedList <T> ();
    case circular_list: return new CircularLinkedList <T> ();
    default: throw invalid_argument("Not a valid collection - build");
  }
}

template <typename T>
void Tester::testList (Collection collection) {
  Mocker mocker;
  unsigned int size = mocker.generateRandomInt(10);
  T* elements = mocker.generateRandomArray <T> (size);
  List <T>* list = getCollection <T> (collection);
  test.check(list -> size() == 0, "The " + list -> name() + " size is not working");
  test.check(list -> empty() == true, "The " + list -> name() + " empty is not working");

  list -> push_back(elements[0]);
  list -> push_back(elements[1]);
  test.check(list -> size() == 2, "The " + list -> name() + " push_back or size is not working");
  test.check((*list)[1] == elements[1], "The " + list -> name() + " operator [] is not working");

  list -> push_back(elements[2]);
  list -> push_back(elements[3]);
  list -> pop_front();
  test.check(list -> size() == 3, "The " + list -> name() + " pop_front is not working");
  test.check(list -> front() == elements[1], "The " + list -> name() + " front is not working");
  test.check((*list)[2] == elements[3], "The " + list -> name() + " operator [] is not working");

  list -> push_back(elements[4]);
  list -> push_back(elements[5]);
  list -> pop_back();
  test.check(list -> size() == 4, "The " + list -> name() + " pop_back is not working");
  test.check(list -> back() == elements[4], "The " + list -> name() + " back is not working");

  list -> reverse();
  test.check(list -> back() == elements[1], "The " + list -> name() + " reverse is not working");
  test.check(list -> front() == elements[4], "The " + list -> name() + " reverse is not working");
  test.check((*list)[1] == elements[3], "The " + list -> name() + " reverse is not working");
  test.check((*list)[2] == elements[2], "The " + list -> name() + " reverse is not working");

  
  list -> push_back(elements[6]);
  list -> push_back(elements[7]);
  list -> sort();
  test.check(isSorted(list), "The " + list -> name() + " sort is not working");

  list -> clear();
  test.check(list -> size() == 0, "The " + list -> name() + " size or clear is not working");
  test.check(list -> empty() == true, "The " + list -> name() + " empty is not working");

  testSpecifics(collection, list);
}

template <typename T>
bool Tester::isSorted (List <T>* list) {
  for (int i = 1; i < list -> size(); i++) {
    if ((*list)[i - 1] > (*list)[i]) {
      return false;
    }
  }
  return true;
}

template <typename T>
void Tester::print (List <T>* list) {
  for (int i = 0; i < list -> size(); i++) {
    cout << (*list)[i] << " ";
  }
  cout << endl;
}

template <typename T>
void Tester::testSpecifics (Collection collection, List <T>* list) {
  switch (collection) {
    case forward_list: testForward((ForwardList <T>*) list); break;
    case linked_list: testLinked((LinkedList <T>*) list); break;
    case circular_list: testCircularLinked((CircularLinkedList <T>*) list); break;
    default: throw invalid_argument("Not a valid collection - specifics");
  }
}

template <typename T>
void Tester::testForward (ForwardList <T>* list) {
  Mocker mocker;
  unsigned int size = mocker.generateRandomInt(5);
  T* elements = mocker.generateRandomArray <T> (size);
  ForwardList <T>* list1 = new ForwardList <T>;
  list1 -> push_back(elements[0]);
  list1 -> push_back(elements[1]);
  list1 -> push_back(elements[2]);
  list1 -> push_back(elements[3]);
  list1 -> push_back(elements[4]);

  list -> merge(*list1);
  test.check(list -> size() == 5, "The " + list -> name() + " merge is not working");

  auto it = list -> begin();
  ++it;
  test.check(*it == elements[1], "The " + list -> name() + " iterator is not working");
  ++it;
  ++it;
  test.check(it != list -> end(), "The " + list -> name() + " iterator is not working");
}

template <typename T>
void Tester::testLinked (LinkedList <T>* list) {
  Mocker mocker;
  unsigned int size = mocker.generateRandomInt(5);
  T* elements = mocker.generateRandomArray <T> (size);

  LinkedList <T>* list1 = new LinkedList <T>;
  list1 -> push_back(elements[0]);
  list1 -> push_back(elements[1]);
  list1 -> push_back(elements[2]);
  list1 -> push_back(elements[3]);
  list1 -> push_back(elements[4]);

  list -> merge(*list1);
  test.check(list -> size() == 5, "The " + list -> name() + " merge is not working");

  auto it = list -> begin();
  ++it;
  test.check(*it == elements[1], "The " + list -> name() + " iterator is not working");
  ++it;
  ++it;
  --it;
  test.check(*it == elements[2], "The " + list -> name() + " iterator is not working");
  test.check(it != list -> end(), "The " + list -> name() + " iterator is not working");
}

template <typename T>
void Tester::testCircularLinked (CircularLinkedList <T>* list) {
  Mocker mocker;
  unsigned int size = mocker.generateRandomInt(5);
  T* elements = mocker.generateRandomArray <T> (size);

  CircularLinkedList <T>* list1 = new CircularLinkedList <T>;
  list1 -> push_back(elements[0]);
  list1 -> push_back(elements[1]);
  list1 -> push_back(elements[2]);
  list1 -> push_back(elements[3]);
  list1 -> push_back(elements[4]);

  list -> merge(*list1);
  test.check(list -> size() == 5, "The " + list -> name() + " merge is not working");

  auto it = list -> begin();
  ++it;
  test.check(*it == elements[1], "The " + list -> name() + " iterator is not working");
  ++it;
  ++it;
  --it;
  test.check(*it == elements[2], "The " + list -> name() + " iterator is not working");
  test.check(it != list -> end(), "The " + list -> name() + " iterator is not working");
  ++it;
  ++it;
  ++it;
  ++it;
  test.check(*it == elements[1], "The " + list -> name() + " iterator is not working");
  --it;
  --it;
  test.check(*it == elements[4], "The " + list -> name() + " iterator is not working");
}
