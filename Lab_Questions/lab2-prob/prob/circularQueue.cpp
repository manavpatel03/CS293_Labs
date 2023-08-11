#include <stdlib.h>
#include "queue.h"

using namespace std;

template <typename T>
bool DynamicQueue<T>::isEmpty()
{
  return (head == tail);
}

template <typename T>
bool DynamicQueue<T>::isFull()
{
  return size() == (N - 1);
}

template <typename T>
void DynamicQueue<T>::grow()
{
  int new_size = N * 2; // We observed the growth in our lab !!
  T *tmp = (T *)malloc(sizeof(int) * new_size);
  for (int i = 0; i < N; i++)
  {
    tmp[i] = A[(N + i + head) % N];
  }
  head = 0;
  tail = N;
  free(A);
  A = tmp;
  N = new_size;
}

template <typename T>
unsigned int DynamicQueue<T>::size()
{
  return (N + tail - head) % N; // dummy return
}

template <typename T>
void DynamicQueue<T>::QInsert(T x)
{
  if (isFull())
    grow();
  A[tail] = x;
  if (tail == N - 1)
    tail = 0;
  else
    tail++;
}

template <typename T>
bool DynamicQueue<T>::QDelete(T *x)
{
  if (isEmpty())
    return false; // dummy return
  *x = A[head];
  if (head == N - 1)
    head = 0;
  else
    head++;
  return true;
}
