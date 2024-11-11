#ifndef LINKEDLIST
#define LINKEDLIST
#include <iostream>

using namespace std;
template <typename T>
class LinkedList
{
private:
  class Node
  {
  public:
    T *data;
    Node *next;
    Node(T *value) : data(value), next(nullptr) {}
  };

  Node *head;
  Node *tail;
  int size;

public:
  LinkedList();
  ~LinkedList();
  void append(T *value);
  void remove(const T &value);
  T &at(int index);
  int getSize() const;

  friend ostream &operator<<(ostream &os, const LinkedList<T> &list)
  {
    Node *current = list.head;

    while (current != nullptr)
    {
      os << *(current->data);
      current = current->next;
    }

    return os;
  }
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0)
{
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  Node *current = head;
  while (current != nullptr)
  {
    Node *next = current->next;
    delete current;
    current = next;
  }
}

template <typename T>
void LinkedList<T>::append(T *value)
{
  Node *newNode = new Node(value);
  if (tail)
    tail->next = newNode;
  else
    head = newNode;
  tail = newNode;
  ++size;
}

template <typename T>
void LinkedList<T>::remove(const T &value)
{
  Node *current = head;
  Node *previous = nullptr;
  while (current != nullptr)
  {
    if (*(current->data) == value)
    {
      if (previous)
        previous->next = current->next;
      else
        head = current->next;
      if (current == tail)
        tail = previous;
      delete current;
      --size;
      return;
    }
    previous = current;
    current = current->next;
  }
  cout << "không tìm thấy nhân viên này trong danh sách" << endl;
}

template <typename T>
T &LinkedList<T>::at(int index)
{
  if (index >= size)
    cout << "Lỗi: chỉ số lớn kích thước của danh sách" << endl;
  Node *current = head;
  for (int i = 0; i < index; ++i)
    current = current->next;
  return *(current->data);
}

#endif
