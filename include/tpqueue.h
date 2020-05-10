#include <cassert>
 
template<typename T>
class TPQueue
{private:
    T *arr;          // массив с данными
    int* preoritets;
    int size;        // максимальное количество элементов в очереди (размер массива)
    int begin,       // начало очереди
        end;         // конец очереди
    int count;       // счетчик элементов
public:
    TQueue(int =100);          // конструктор по умолчанию
    ~TQueue();                 // деструктор

    void push(const T &, int preoritet); // добавить элемент в очередь
    T poop();              // удалить элемент из очереди
    T get() const;        // прочитать первый элемент
    bool isEmpty() const;      // пустая ли очередь?
    bool isFull() const;       // заполнен ли массив?
};
// конструктор по умолчанию
template<typename T>
TQueue<T>::TQueue(int sizeQueue) :
    size(sizeQueue),
    begin(0), end(0), count(0)
{
    // дополнительный элемент поможет нам различать конец и начало очереди
    arr = new T[size + 1];
    preoritets = new int[size + 1];
}

// деструктор класса Queue
template<typename T>
TQueue<T>::~TQueue()
{
    delete [] arr;
    delete [] preoritets;
}


// функция добавления элемента в очередь
template<typename T>
void TQueue<T>::push(const T & item, int preoritet)
{
    // проверяем, ести ли свободное место в очереди
    assert( count < size );

    arr[end] = item;
    preoritets[end++] = preoritet;
    count++;

    // проверка кругового заполнения очереди
    if (end > size)
        end -= size + 1; // возвращаем end на начало очереди
}

// функция удаления элемента из очереди
template<typename T>
T TQueue<T>::poop()
{
    // проверяем, есть ли в очереди элементы
    assert( count > 0 );

    int max = 0;
    for(int i=0; i<count; ++i){
        if(preoritets[i] > preoritets[max]){
            max = i;
        }
    }
    preoritets[max] = 0;
    T item = arr[max];

    // проверка кругового заполнения очереди
    if (begin > size)
        begin -= size + 1; // возвращаем begin на начало очереди

    return item;
}

// функция чтения элемента на первой позиции
template<typename T>
T TQueue<T>::get() const
{
    // проверяем, есть ли в очереди элементы
    assert( count > 0 );
    return arr[begin];
}

// функция проверки очереди на пустоту
template<typename T>
bool TQueue<T>::isEmpty() const
{
  return count==0;
}

// функция проверки очереди на заполненность
template<typename T>
bool TQueue<T>::isFull() const
{
  return count==size;
}

struct SYM
{
	char ch;
	int  prior;
};