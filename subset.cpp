#include <cassert>

struct subset_node
{
    int key;
    subset_node* left;
    subset_node* right;
    subset_node* parent;
};

//Инициализация пустого дерева
bool init(subset_node** sn)
{
    assert(sn != nullptr);
    *sn = nullptr;
    return true;
}
//Инициализация пустого дерева

//Добавление элемента в дерево
bool insert(subset_node** sn, int k, subset_node* parent = nullptr)
{
    if ((*sn) == nullptr)
    {
        *sn = new subset_node;
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
//Добавление элемента в дерево

//Поиск элемента в дереве
subset_node* find(subset_node* sn, int k)
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
//Поиск элемента в дереве

//Количество элементов в дереве
unsigned int size(subset_node* sn)
{
    if (sn == nullptr)
        return 0;
    return (1 + size(sn->right) + size(sn->left));
}
//Количество элементов в дереве

//Высота дерева
unsigned int height(subset_node* sn)
{
    if (sn == nullptr)
        return 0;
    return (1 + std::max(size(sn->right), size(sn->left)));
}
//Высота дерева

//Поиск крайнего левого элемента
int find_the_left(subset_node* sn)
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
//Поиск крайнего левого элемента

subset_node* findmin(subset_node* sn)
{
    if (sn->left == nullptr)
        return sn;
    subset_node * min = sn;
    while (min->left)
        min = min->left;
    return min;
}

//Удаление элемента из дерева
subset_node* remove_rec(subset_node* sn, int k)
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
        subset_node * tmp = sn;
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
//Удаление элемента из дерева


bool remove(subset_node** sn, int k)
{
    *sn = remove_rec(*sn, k);
    return true;
}

//Очистить всю используемую память
void destructor(subset_node* sn)
{
    if (sn == nullptr)
        return;
    destructor((*sn).left);
    destructor((*sn).right);
    delete sn;
    sn = nullptr;
    return;
}
//Очистить всю используемую память

void DFS_rec(subset_node* sn, int* arr, int* i)
{
    if (sn == nullptr)
        return;
    DFS_rec(sn->left, arr, i);
    arr[*i] = sn->key;
    ++(*i);
    DFS_rec(sn->right, arr, i);
    return;
}

int* DFS(subset_node* sn)
{
    size_t size_arr = size(sn);
    int* arr = new int [size_arr];
    int i = 0;
    DFS_rec(sn, arr, &i);
    return arr;
}