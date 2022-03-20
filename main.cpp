#include <iostream>  // cout

#include "assignment/dynamic_array.hpp"  // DynamicArray
#include "assignment/linked_list.hpp"    // LinkedList
#include "assignment/array_stack.hpp"    // ArrayStack
#include "assignment/linked_queue.hpp"   // LinkedQueue

using std::cout;

int main(int argc, char **argv) {

  // Пример. Создание пустого динамического массива.
  assignment::DynamicArray array;


  cout << "print\n";
  for (int i = 0; i < array.size(); i++) {
    cout << array.Get(i).value() << "\n";
  }

  array.Add(1);
  array.Add(2);
  array.Add(3);

  cout << "print\n";
  for (int i = 0; i < array.size(); i++) {
    cout << array.Get(i).value() << "\n";
  }

  cout << array.size()  << '|' << array.Insert(3, 1) << "\n";
  cout << "print\n";
  for (int i = 0; i < array.size(); i++) {
    cout << array.Get(i).value() << "\n";
  }
  cout << "Write your code here...\n";

  return 0;
}
