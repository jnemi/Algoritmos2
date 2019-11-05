#ifndef LINKED_H_INCLUDED
#define LINKED_H_INCLUDED

using namespace std;

template <typename Object>

class Linked
{
private:
    Linked<Object>* next;
    Linked<Object>* prev;
    Object* value;
public:
    Linked(Object*);
    ~Linked();
    void setValue(Object*);
    void setNext(Linked<Object>*);
    void setPrev(Linked<Object>*);
    Object& getValue();
    Linked<Object>* getNext();
    Linked<Object>* getPrev();
};

template <typename Object>
Linked<Object>::Linked(Object* obj)
{
    setValue(obj);
}

template <typename Object>
Linked<Object>::~Linked()
{
    delete value;
    cout<<"Linked has been eliminated"<<endl;
}

template <typename Object>
void Linked<Object>::setValue(Object* pointedObj)
{
    value = pointedObj;
}

template <typename Object>
void Linked<Object>::setNext(Linked<Object>* pointedLink)
{
    next = pointedLink;
}

template <typename Object>
void Linked<Object>::setPrev(Linked<Object>* pointedLink)
{
    prev = pointedLink;
}

template <typename Object>
Object& Linked<Object>::getValue()
{
    return *(value);
}

template <typename Object>
Linked<Object>* Linked<Object>::getNext()
{
    return next;
}

template <typename Object>
Linked<Object>* Linked<Object>::getPrev()
{
    return prev;
}
#endif // LINKED_H_INCLUDED
