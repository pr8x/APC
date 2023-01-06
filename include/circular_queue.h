#pragma once
#include <array>
#include <gsl/span>
#include <stddef.h>

namespace apc {

template <class T, size_t Size>
class circular_queue {
 public:
  T& dequeue() {
    assert(_size > 0);
    T& item = _buffer[_head++];
    _head %= Size;
    _size--;
    return item;
  }

  template <class _T>
  void enqueue(_T&& item) {
    assert(_size < Size);
    _buffer[_tail++] = std::forward<T>(item);
    _tail %= Size;
    _size++;
  }

  size_t size() const { return _size; }

 private:
  size_t _head;
  size_t _tail;
  size_t _size;
  std::array<T, Size> _buffer;
};

}  // namespace apc