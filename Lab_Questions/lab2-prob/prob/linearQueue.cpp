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
  return (tail == N) && (head == 0);
}

template <typename T>
void DynamicQueue<T>::grow()
{
  int new_size = N * 2;                         // We observed the growth in our lab !!
  T *tmp = (T *)malloc(sizeof(int) * new_size); // New array
  for (unsigned i = 0; i < N; i++)
  { // copy from the old array
    tmp[i] = A[i];
  }
  free(A);      // Release old memory
  A = tmp;      // Update local fields
  N = new_size; //
}

template <typename T>
unsigned int DynamicQueue<T>::size()
{
  return (tail - head); // dummy return
}

template <typename T>
void DynamicQueue<T>::QInsert(T x)
{
  if (tail == N && head != 0)
  {
    for (int i = 0; i < (tail - head); i++)
    {
      A[i] = A[head + i];
    }
    tail -= head;
    head = 0;
  }
  else if (isFull())
    grow();
  A[tail] = x;
  tail++;
}

template <typename T>
bool DynamicQueue<T>::QDelete(T *x)
{
  if (isEmpty())
    return false;
  *x = A[head];
  head++;
  return true;
}
