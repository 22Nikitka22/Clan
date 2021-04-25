#include "subset.h"
#include <algorithm>

subset::subset(node** sn)
{
    *sn = nullptr;
}
bool subset::insert(node** sn, int k, node* parent)
{
    if ((*sn) == nullptr)
    {
        *sn = new node;
        (*sn)->key = k;
        (*sn)->left = nullptr;
        (*sn)->right = nullptr;
        (*sn)->parent = parent;
        if (parent)
        {
            if ((*sn)->key > parent->key)
                parent->right = *sn;
            else
                parent->left = *sn;
        }
        return true;
    }
    if (k < (*sn)->key)
        return insert(&((*sn)->left), k, *sn);
    else if (k > (*sn)->key)
        return insert(&((*sn)->right), k, *sn);
    return false;
}
node* subset::find(node* sn, int k)
{
    if (sn == nullptr)
        return nullptr;
    if ((*sn).key == k)
        return sn;
    if ((*sn).key < k)
        return find((*sn).right, k);
    else
        return find((*sn).left, k);
}
unsigned int subset::size(node* sn)
{
    if (sn == nullptr)
        return 0;
    return (1 + size(sn->right) + size(sn->left));
}
unsigned int subset::height(node* sn)
{
    if (sn == nullptr)
        return 0;
    return (1 + std::max(size(sn->right), size(sn->left)));
}
int subset::find_the_left(node* sn)
{
    if (sn != nullptr)
    {
        int found;
        while (sn->left != nullptr)
            found = find_the_left(sn->left);
        return found;
    }
    return 0;
}
node* subset::findmin(node* sn)
{
    if (sn->left == nullptr)
        return sn;
    node * min = sn;
    while (min->left)
        min = min->left;
    return min;
}
node* subset::remove_rec(node* sn, int k)
{
    if (sn == nullptr)
        return sn;
    if (k < sn->key)
        sn->left = remove_rec(sn->left, k);
    else if (k > sn->key)
        sn->right = remove_rec(sn->right, k);
    else if (sn->left != nullptr && sn->right != nullptr)
    {
        sn->key = findmin(sn->right)->key;
        sn->right = remove_rec(sn->right, sn->key);
    }
    else
    {
        node * tmp = sn;
        if (sn->left != nullptr)
            sn = sn->left;
        else if (sn->right != nullptr)
            sn = sn->right;
        else
            sn = nullptr;
        delete tmp;
    }
    return sn;
}
bool subset::remove(node** sn, int k)
{
    *sn = remove_rec(*sn, k);
    return true;
}
void subset::DFS_rec(node* sn, int* arr, int* i)
{
    if (sn == nullptr)
        return;
    DFS_rec(sn->left, arr, i);
    arr[*i] = sn->key;
    ++(*i);
    DFS_rec(sn->right, arr, i);
    return;
}
int* subset::DFS(node* sn)
{
    size_t size_arr = size(sn);
    int* arr = new int [size_arr];
    int i = 0;
    DFS_rec(sn, arr, &i);
    return arr;
}