#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include "Linked.h"

template <typename Object>

class List
{
private:
    Linked<Object>* first;
    Linked<Object>* last;
    int length;
public:
    List();
    ~List();
    int getLength();
    bool isEmpty();
    void put(Object*, int);
    void put(Object*, Linked<Object>*);
    void push(Object*);
    void takeAway(int);
    void takeAway(Linked<Object>*);
    Linked<Object>* findLink(int);
    Object& getValue(int);
};

template <typename Object>
List<Object>::List()
{
    length = 0;
}

template <typename Object>
List<Object>::~List()
{
    while (!isEmpty())
        takeAway(first);
}

template <typename Object>
int List<Object>::getLength()
{
    return length;
}

template <typename Object>
bool List<Object>::isEmpty()
{
    return (length <= 0);
}

template <typename Object>
void List<Object>::put(Object* obj, int index)
{
    if ((0 < index) && (index <= length))
        put(obj, findLink(index));
    else
        delete obj;
}

template <typename Object>
void List<Object>::put(Object* obj, Linked<Object>* linkToRelocate)
{
    Linked<Object>* newElement = new Linked<Object>(obj);
    if (isEmpty()){
        first = newElement;
        last = newElement;
    }else if (linkToRelocate == first){
        newElement->setNext(first);
        first->setPrev(newElement);
        first = newElement;
    }else if(linkToRelocate == last){
        newElement->setPrev(last);
        last->setNext(newElement);
        last = newElement;
    }else{
        newElement->setNext(linkToRelocate);
        newElement->setPrev(linkToRelocate->getPrev());
        newElement->getPrev()->setNext(newElement);
        newElement->getNext()->setPrev(newElement);
    }
    length++;
}

template <typename Object>
void List<Object>::push(Object* obj)
{
    Linked<Object>* newElement = new Linked<Object>(obj);
    if (length > 0){
        last->setNext(newElement);
        newElement->setPrev(last);
    }
    else{
        first = newElement;
    }
    last = newElement;
    length++;
}

template <typename Object>
void List<Object>::takeAway(int index)
{
    takeAway(findLink(index));
}

template <typename Object>
void List<Object>::takeAway(Linked<Object>* takenLink)
{
    if (!isEmpty()){
        Linked<Object>* aux = first;
        if (length <= 1){
            aux = takenLink;
            first = 0;
            last = 0;
        }
        else if (takenLink == first){
            first = aux->getNext();
            first->setPrev(0);
        }
        else if (takenLink == last){
            aux = last;
            last = aux->getPrev();
            last->setNext(0);
        }
        else{
            aux = takenLink;
            aux->getPrev()->setNext(aux->getNext());
            aux->getNext()->setPrev(aux->getPrev());
        }
        delete aux;
        length--;
    }
}

template <typename Object>
Linked<Object>* List<Object>::findLink(int index)
{
    Linked<Object>* target;
    if (index <= (length/2)){
        target = first;
        for (int i = 1; i < index; i++)
            target = target->getNext();
    }else{
        target = last;
        for (int i = length; i > index; i--)
            target = target->getPrev();
    }
    return target;
}

template <typename Object>
Object& List<Object>::getValue(int index)
{
    return findLink(index)->getValue();
}


#endif // LIST_H_INCLUDED
