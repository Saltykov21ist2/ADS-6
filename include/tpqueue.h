// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
template<typename T, int size>
class TPQueue {
 private:
    T q[size] = {0};
    int ft = 0, lt = 0;
 public:
  void push(T value) {
      int i = lt;
      while ((--i >= ft) && (value.prior > q[i % size].prior)) {
          q[(i + 1) % size] = q[i % size];
      }
      q[(i+1) % size] = value;
      lt++;
  }
  T pop() {
      return q[(ft++) % size];
  }
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
