#pragma once
#include <iostream>

// узел списка
template<typename DATA>
class ListNode {
public:
    DATA data;
    ListNode<DATA>* next;
    ListNode() { next = nullptr; } //конструктор
};

// Шаблонный класс MyStack на основе односвязного списка.
template<class DATA>
class MyStack {
    ListNode<DATA>* top;
public:
    // конструктор
    MyStack() { top = nullptr; }
    // деструктор
    ~MyStack(void) { delete[] top; }

    // стек пустой?
    bool empty(void) {
      return top == nullptr;
    }
    // добавить узел в вершину стека
    bool push(DATA obj) {
      ListNode<DATA>* tmp = new ListNode<DATA>();
      tmp->next = top;
      tmp->data = obj;
      top = tmp;
    }
    // удалить узел из вершины стека
    bool pop() {
      if (empty()) {
        return false;
      }
      top = top->next;
      return true;
    }
    // считать информацию из вершины стека
    DATA inf() {
      if (empty()) {
        std::cout << "Попытка обратиться к несуществующему элементу!\n";
        exit(0);
      }
      return top->data;
    }
};