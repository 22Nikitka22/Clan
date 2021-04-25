#ifndef SUBVECTOR_PROFILER_CPP_SUBVECTOR_H
#define SUBVECTOR_PROFILER_CPP_SUBVECTOR_H

class subvector
{
private:
    void increase(int** arr, unsigned int oldLength, unsigned int newLength);
public:
    int* mas;
    unsigned int capacity;
    unsigned int top;
    subvector();
    bool push_back (int d);
    int pop_back();
    void insert(int p, int d);
    bool resize(unsigned int new_capacity);
    void shrink_to_fit();
    void clear();
    ~subvector();
};

#endif
