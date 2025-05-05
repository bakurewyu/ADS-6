// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <list>

template<typename T>
class TPQueue {
  // реализация шаблона очереди с приоритетом на связанном списке
 private:
    std::list<T> list;

 public:
    void push(const T& item) {
        auto it = list.begin();
        while (it != list.end() && it->prior >= item.prior) {
            ++it;
        }
        list.insert(it, item);
    }

    T pop() {
        T item = list.front();
        list.pop_front();
        return item;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
