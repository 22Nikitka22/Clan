#include <cassert>

struct subvector
{
    int* mas;
    unsigned int top;
    unsigned int capacity;
};

//Инициализация пустого недовектора
bool init(subvector* qv)
{
    assert(qv != nullptr);
    qv->mas = nullptr;
    qv->top = 0;
    qv->capacity = 0;
    return true;
}
//Инициализация пустого недовектора

//Увеличение массива
void increase(int** arr, unsigned int oldLength, unsigned int newLength)
{
    int* newArr = new int [newLength];
    for (int i = 0; i < oldLength; i++)
        newArr[i] = (*arr)[i];
    if (*arr != nullptr)
        delete[] *arr;
    *arr = newArr;
}
//Увеличение массива

//Добавление элемента в конец недовектора
bool push_back(subvector *qv, int d)
{
    assert(qv != nullptr);
    assert(qv->capacity >= qv->top);
    if (qv->capacity == qv->top)
    {
        increase(&(qv->mas), qv->top, qv->capacity + 2);
        qv->capacity += 2;
    }
    qv->mas[qv->top] = d;
    qv->top++;
    return true;
}
//С выделением дополнительной памяти при необходимости

//Удаление элемента с конца недовектора
int pop_back(subvector *qv)
{
    assert(qv != nullptr);
    if (qv->top == 0)
        return 0;
    qv->top--;
    return qv->mas[qv->top];
}
//Удаление элемента с конца недовектора

//Увеличить ёмкость недовектора
bool resize(subvector *qv, unsigned int new_capacity)
{
    assert(qv != nullptr);
    if (new_capacity <= qv->capacity)
        return false;
    increase(&qv->mas, qv->capacity, new_capacity);
    qv->capacity = new_capacity;
    return true;
}
//Увеличить ёмкость недовектора

//Очистить неиспользуемую память
void shrink_to_fit(subvector *qv)
{
    assert(qv != nullptr);
    assert(qv->top <= qv->capacity);
    if (qv->top == qv->capacity)
        return;
    increase(&qv->mas, qv->top, qv->top);
    qv->capacity = qv->top;
}
//Очистить неиспользуемую память

//Очистить содержимое недовектора
void clear(subvector *qv)
{
    assert(qv != nullptr);
    qv->top = 0;
}
//Занимаемое место при этом не меняется

//Очистить всю используемую память
void destructor(subvector *qv)
{
    assert(qv != nullptr);
    if (qv->mas != nullptr)
    {
        delete[] qv->mas;
        qv->mas = nullptr;
    }
    qv->top = qv->capacity = 0;
}
//Инициализировать недовектор как пустой
