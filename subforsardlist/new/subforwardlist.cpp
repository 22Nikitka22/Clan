#include "subforwardlist.h"
subforwardlist::subforwardlist(node** sf)
{
    *sf = nullptr;
}
bool subforwardlist::push_back(node** sf, int d)
{
    if (*sf != nullptr)
        return push_back(&(*sf)->next, d);
    *sf = new node;
    (*sf)->data = d;
    (*sf)->next = nullptr;
    return true;
}
int subforwardlist::pop_back(node** sf)
{
    if (*sf == nullptr)
        return 0;
    if ((*sf)->next != nullptr)
        return pop_back(&(*sf)->next);
    int wasted = (*sf)->data;
    delete *sf;
    *sf = nullptr;
    return wasted;
}
bool subforwardlist::push_forward(node** sf, int d)
{
    node* sf2 = new node;
    sf2->data = d;
    sf2->next = *sf;
    *sf = sf2;
    return true;
}
int subforwardlist::pop_forward(node** sf)
{
    if (*sf == nullptr)
        return 0;
    int wasted = (*sf)->data;
    node* excess = *sf;
    *sf = (*sf)->next;
    delete excess;
    return wasted;
}
bool subforwardlist::push_where(node** sf, unsigned int where, int d)
{
    if (where > 1)
        return push_where(&(*sf)->next, where - 1, d);
    return push_forward(sf, d);
}
bool subforwardlist::erase_where(node** sf, unsigned int where)
{
    if (where > 1)
        return erase_where(&(*sf)->next, where - 1);
    pop_forward(sf);
    return true;
}
unsigned int subforwardlist::size(node** sf)
{
    if ((*sf) == nullptr)
        return 0;
    return (size(&(*sf)->next) + 1);
}
void subforwardlist::clear(node** sf)
{
    unsigned int Size = size(sf);
    for (int i = 0; i < Size; ++i)
        pop_forward(sf);
}