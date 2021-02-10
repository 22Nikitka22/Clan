#include <cassert>

struct subforwardlist {
  int data;
  subforwardlist* next;
};

//Инициализация пустого недосписка
bool init(subforwardlist** lst)
{
  assert(lst != nullptr);
  *lst = nullptr;
  return true;
}
//Инициализация пустого недосписка

//Добавление элемента в конец недосписка
bool push_back(subforwardlist** lst, int d)
{
  assert(lst != nullptr);
  if (*lst != nullptr)
    return push_back(&(*lst)->next, d);
  *lst = new subforwardlist;
  (*lst)->data = d;
  (*lst)->next = nullptr;
  return true;
}
//Добавление элемента в конец недосписка

//Удаление элемента с конца недосписка
int pop_back(subforwardlist** lst) //удаление элемента с конца недосписка
{
  assert(lst != nullptr);
  if (*lst == nullptr)
    return 0;
  if ((*lst)->next != nullptr)
    return pop_back(&(*lst)->next);
  int wasted = (*lst)->data;
  delete *lst;
  *lst = nullptr;
  return wasted;
}
//Удаление элемента с конца недосписка

//Добавление элемента в начало недосписка
bool push_forward(subforwardlist** lst, int d)
{
  assert(lst != nullptr);
  subforwardlist* lst2 = new subforwardlist;
  lst2->data = d;
  lst2->next = *lst;
  *lst = lst2;
  return true;
}
//Добавление элемента в начало недосписка

//Удаление элемента из начала недосписка
int pop_forward(subforwardlist** lst)
{
  assert(lst != nullptr);
  if (*lst == nullptr)
    return 0;
  int wasted = (*lst)->data;
  subforwardlist* excess= *lst;
  *lst = (*lst)->next;
  delete excess;
  return wasted;
}
//Удаление элемента из начала недосписка

//Добавление элемента с порядковым номером where
bool push_where(subforwardlist** lst, unsigned int where, int d)
{
  assert(lst != nullptr);
  if (where > 1)
    return push_where(&(*lst)->next, where - 1, d);
  return push_forward(lst, d);
}
//Добавление элемента с порядковым номером where

//Удаление элемента с порядковым номером where
bool erase_where(subforwardlist** lst, unsigned int where)
{
  assert(lst != nullptr);
  if (where > 1)
    return erase_where(&(*lst)->next, where - 1);
  pop_forward(lst);
  return true;
}
//Удаление элемента с порядковым номером where

//Определить размер недосписка
unsigned int size(subforwardlist** lst)
{
  assert(lst != nullptr);
  if ((*lst) == nullptr)
    return 0;
  return (size(&(*lst)->next) + 1);
}
//Определить размер недосписка

//Очистить содержимое недосписка
void clear(subforwardlist** lst)
{
  unsigned int Size = size(lst);
  for (int i = 0; i < Size; ++i)
    pop_forward(lst);
}
//Очистить содержимое недосписка