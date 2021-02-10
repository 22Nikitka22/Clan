#include "subvector.h"
#include <cassert>

subvector::subvector()
{
    mas = nullptr;
    top = 0;
    capacity = 0;
}
void subvector::increase(int** arr, unsigned int oldLength, unsigned int newLength)
{
    int* newArr = new int [newLength];
    for (int i = 0; i < oldLength; i++)
        newArr[i] = (*arr)[i];
    if (*arr != nullptr)
        delete[] *arr;
    *arr = newArr;
}
bool subvector::push_back(int d)
{
    assert(capacity >= top);
    if (capacity == top)
    {
        increase(&(mas), top, capacity + 2);
        capacity += 2;
    }
    mas[top] = d;
    top++;
    return true;
}
int subvector::pop_back()
{
    if (top == 0)
        return 0;
    top--;
    return mas[top];
}
bool subvector::resize(unsigned int new_capacity)
{
    if (new_capacity <= capacity)
        return false;
    increase(&mas, capacity, new_capacity);
    capacity = new_capacity;
    return true;
}
void subvector::shrink_to_fit()
{
    assert(top <= capacity);
    if (top == capacity)
        return;
    increase(&mas, top, top);
    capacity = top;
}
void subvector::clear()
{
    top = 0;
}
subvector::~subvector()
{
    if (mas != nullptr)
    {
        delete[] mas;
        mas = nullptr;
    }
    top = capacity = 0;
}
