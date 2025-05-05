#pragma once
#include <iostream>

// узел списка
template<typename DATA>
class ListNode {
public:
    DATA data;
    ListNode<DATA>* next;
    ListNode() { next = nullptr; }
};

// Шаблонный класс MyStack на основе односвязного списка.
template<class DATA>
class MyStack {
    ListNode<DATA>* top;
public:
    // конструктор
    MyStack() { top = nullptr; }
    // конструктор копирования
    MyStack(const MyStack &other) {
      top = nullptr;
      MyStack<DATA> tmpStack;
      ListNode<DATA>* tmp = other.top;
      while (tmp != nullptr) {
        tmpStack.push(tmp->data);
        tmp = tmp->next;
      }

      tmp = tmpStack.top;
      while (tmp != nullptr) {
        push(tmp->data);
        tmp = tmp->next;
      }
    }
    // деструктор
    ~MyStack(void) {
      while (pop()) {}
    }

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
      return 1;
    }
    // удалить узел из вершины стека
    bool pop() {
      if (empty()) {
        return false;
      }
      ListNode<DATA>* tmp = top->next;
      delete top;
      top = tmp;
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

    // присваивания
    MyStack& operator=(const MyStack &obj) {
      if (this == &obj) {
        return *this;
      }
      while (pop()) {}

      MyStack<DATA> tmpStack;
      ListNode<DATA>* tmp = obj.top;
      while (tmp != nullptr) {
        tmpStack.push(tmp->data);
        tmp = tmp->next;
      }

      tmp = tmpStack.top;
      while (tmp != nullptr) {
        push(tmp->data);
        tmp = tmp->next;
      }
      return *this;
    }

    DATA operator[](int ind) {
      MyStack<DATA> tmpStack;
      ListNode<DATA>* tmp = top;
      while (tmp != nullptr) {
        tmpStack.push(tmp->data);
        tmp = tmp->next;
      }

      tmp = tmpStack.top;
      int i = 0;
      while (tmp != nullptr && i < ind) {
        i++;
      //  std::cout << tmp->data << '\n';
        tmp = tmp->next;
      }

      if (i == ind) {
        return tmp->data;
      }
      
      std::cout << "Попытка обратиться к несуществующему элементу!\n";
      exit(0);
    }
};