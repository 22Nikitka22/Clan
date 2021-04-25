#ifndef SUBSET_PROFILER_CPP_SUBSET_H
#define SUBSET_PROFILER_CPP_SUBSET_H

struct node
{
    int key;
    node* left;
    node* right;
    node* parent;
};

class subset{
public:
    subset(node** sn);
    bool insert(node** sn, int k, node* parent = nullptr);
    node* find(node* sn, int k);
    unsigned int size(node* sn);
    unsigned int height(node* sn);
    int find_the_left(node* sn);
    node* findmin(node* sn);
    node* remove_rec(node* sn, int k);
    bool remove(node** sn, int k);
    ~subset(){};
    void DFS_rec(node* sn, int* arr, int* i);
    int* DFS(node* sn);
};
#endif
