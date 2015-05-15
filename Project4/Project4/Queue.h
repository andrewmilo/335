#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue
{
public:
    void Enqueue(T);
    void Dequeue();
    bool isEmpty() const;
    void Print() const;
    Queue();
    ~Queue();
private:
    class Node
    {
    public:
            T value_;
            Node * next;
            Node(T);
    };

    Node * head;
    Node * tail;
};

template <class T>
Queue<T>::Queue(){}

template <class T>
Queue<T>::~Queue(){}

template <class T>
Queue<T>::Node::Node(T value)
{
    this->value_ = value;
}

template <class T>
bool Queue<T>::isEmpty() const
{
    if(head == 0)
            return true;

    return false;
}

template <class T>
void Queue<T>::Enqueue(T value)
{
    Node * temp = new Node(value);
    temp->next = head;
    head = temp;
}

template <class T>
void Queue<T>::Dequeue()
{
    if(!isEmpty())
    {
        Node * temp = head;

        if(head == tail)
        {
            head = 0;
            tail = 0;
        }
        else head = head->next;

        delete temp;
    }
}

void Queue<T>::Print() const
{
    if(head != 0)
    {
        Node * temp = head;

        while(temp != 0)
        {
            std::cout << temp->value_;
            temp = temp->next;
        }
    }
}

#endif