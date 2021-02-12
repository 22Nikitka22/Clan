#include <cassert>

struct subforwardlist {
  int data;
  subforwardlist* next;
};

//Инициализация пустого недосписка
bool init(subforwardlist** sfl)
{
  assert(sfl != nullptr);
  *sfl = nullptr;
  return true;
}
//Инициализация пустого недосписка

//Добавление элемента в конец недосписка
bool push_back(subforwardlist** sfl, int d)
{
  assert(sfl != nullptr);
  if (*sfl != nullptr)
    return push_back(&(*sfl)->next, d);
  *sfl = new subforwardlist;
  (*sfl)->data = d;
  (*sfl)->next = nullptr;
  return true;
}
//Добавление элемента в конец недосписка

//Удаление элемента с конца недосписка
int pop_back(subforwardlist** sfl) //удаление элемента с конца недосписка
{
  assert(sfl != nullptr);
  if (*sfl == nullptr)
    return 0;
  if ((*sfl)->next != nullptr)
    return pop_back(&(*sfl)->next);
  int wasted = (*sfl)->data;
  delete *sfl;
  *sfl = nullptr;
  return wasted;
}
//Удаление элемента с конца недосписка

//Добавление элемента в начало недосписка
bool push_forward(subforwardlist** sfl, int d)
{
  assert(sfl != nullptr);
  subforwardlist* sfl2 = new subforwardlist;
    sfl2->data = d;
    sfl2->next = *sfl;
  *sfl = sfl2;
  return true;
}
//Добавление элемента в начало недосписка

//Удаление элемента из начала недосписка
int pop_forward(subforwardlist** sfl)
{
  assert(sfl != nullptr);
  if (*sfl == nullptr)
    return 0;
  int wasted = (*sfl)->data;
  subforwardlist* excess= *sfl;
  *sfl = (*sfl)->next;
  delete excess;
  return wasted;
}
//Удаление элемента из начала недосписка

//Добавление элемента с порядковым номером where
bool push_where(subforwardlist** sfl, unsigned int where, int d)
{
  assert(sfl != nullptr);
  if (where > 1)
    return push_where(&(*sfl)->next, where - 1, d);
  return push_forward(sfl, d);
}
//Добавление элемента с порядковым номером where

//Удаление элемента с порядковым номером where
bool erase_where(subforwardlist** sfl, unsigned int where)
{
  assert(sfl != nullptr);
  if (where > 1)
    return erase_where(&(*sfl)->next, where - 1);
  pop_forward(sfl);
  return true;
}
//Удаление элемента с порядковым номером where

//Определить размер недосписка
unsigned int size(subforwardlist** sfl)
{
  assert(sfl != nullptr);
  if ((*sfl) == nullptr)
    return 0;
  return (size(&(*sfl)->next) + 1);
}
//Определить размер недосписка

//Очистить содержимое недосписка
void clear(subforwardlist** sfl)
{
  unsigned int Size = size(sfl);
  for (int i = 0; i < Size; ++i)
    pop_forward(sfl);
}
//Очистить содержимое недосписка