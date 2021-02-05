#include <iostream>
using std::cin;
using std::cout;
#include <cassert>

struct subforwardlist {
  int data;
  subforwardlist* next;
};

typedef subforwardlist   sfl;   // переименовали для удобства
typedef subforwardlist * sfl_p; // ------

bool init(sfl_p *lst) //**, инициализация пустого недосписка
{
  assert(lst != nullptr);

  *lst = nullptr;
  return true;
}

bool push_back(sfl_p *lst, int d) //добавление элемента в конец недосписка
{
  assert(lst != nullptr);

  if (*lst != nullptr)
    return push_back(&(*lst)->next, d);

  *lst = new sfl;
  (*lst)->data = d;
  (*lst)->next = nullptr;

  return true;

  /*if ((*sfl)->next != nullptr)
  {
    push_back(&( (*sfl)->next ), d); //типа сдвинулись на один некст дальше, и вызвали от него функцию опять
  }
  else
  {
    (*sfl)->next->data = d; //по адресу некста добавляем новый элемент
    (*sfl)->next->next = nullptr; //для добав. элем. делаем указ. на след. как нулл
  }

  return true;*/
}

int pop_back(sfl_p *lst) //удаление элемента с конца недосписка
{
  /*мы такие ползем до конца, ищем последний элемент, то есть у которого указатель на
   * следующий это nullptr. И когда находим, отодвигаемся на один элемент назад, и вот
   * у него меняем указатель с бывшего последнего элемента на nullptr */
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

bool push_forward(sfl_p *lst, int d) //добавление элемента в начало недосписка
{
  assert(lst != nullptr);

  sfl_p node = new sfl;
  node->data = d;
  node->next = *lst; // шарику новому даем указатель на первый до него шарик

  *lst = node; //перешиваем указатель с предыдущего первого шарика на наш новый

  return true;
}

int pop_forward(sfl_p *lst) //удаление элемента из начала недосписка
{
  assert(lst != nullptr);
  if (*lst == nullptr)
    return 0;

  int wasted = (*lst)->data;
  sfl_p adress = *lst;
  *lst = (*lst)->next;
  delete adress;

  return wasted;

}

bool push_where(sfl_p *lst, unsigned int where, int d) //добавление элемента с поряд-
                                                       //ковым номером where
{
  assert(lst != nullptr);

  if (where > 1)
    return push_where(&(*lst)->next, where - 1, d);

  return push_forward(lst, d);
}

bool erase_where(sfl_p *lst, unsigned int where) //удаление элемента с порядковым номером where
{
  assert(lst != nullptr);

  if (where > 1)
    return erase_where(&(*lst)->next, where - 1);

  pop_forward(lst);
  return true;
}

unsigned int size(sfl_p *lst) //определить размер недосписка
{
  assert(lst != nullptr);

  if ((*lst) == nullptr)
    return 0;
  return (size(&(*lst)->next) + 1);

}

void clear(sfl_p *lst) //очистить содержимое недосписка
{
  unsigned int Size = size(lst);
  for (int i = 0; i < Size; ++i)
    pop_forward(lst);
}

/*int main()
{
  sfl_p list;

  init(&list);

  for (int i = 0; i < 100; ++i)
    push_back(&list, i);

  for (int i = 0; i < 100; ++i)
    push_forward(&list, i);

  for (int i = 0; i < 200;  ++i)
    cout << pop_back(&list) << (i % 15 == 0 ? "\n" : " ");

  clear(&list);
  return 0;
}*/
