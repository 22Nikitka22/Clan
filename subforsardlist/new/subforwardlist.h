#ifndef SUBFORWARDLIST_PROFILER_CPP_SUBFORWARDLIST_H
#define SUBFORWARDLIST_PROFILER_CPP_SUBFORWARDLIST_H

struct node{
    int data;
    node* next;
};

class subforwardlist
{
public:
    subforwardlist(node** sf);
    bool push_back(node** sf, int d);
    int pop_back(node** sf);
    bool push_forward(node** sf, int d);
    int pop_forward(node** sf);
    bool push_where(node** sf, unsigned int where, int d);
    bool erase_where(node** sf, unsigned int where);
    unsigned int size(node** sf);
    void clear(node** sf);
};


#endif
