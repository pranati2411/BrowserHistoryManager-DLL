#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node* next;
    Node* prev;

    Node(T val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class dll
{
    private:

    Node<T> * head;
    Node<T> * tail;
    int size;

    public:
    dll()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~dll()
    {
        Node<T> *curr = head;
        while(curr!=nullptr)
        {
            Node<T>* nextnode = curr->next;
            delete curr;
            curr = nextnode;
        }
    }

    void deletetail()
    {
        if(tail==nullptr) return;
        else if(head==tail)
        {
            Node<T> * temp  = head;
            head = tail = nullptr;
            delete temp;
        }
        else
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
    }

    void movetohead(Node<T>* node)
    {
        if(node == head) return;
        else if(node == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
        {
            node->prev->next  = node->next;
            node->next->prev = node->prev;
        }

        node->next = head;
        node->prev = nullptr;
        head->prev = node;
        head = node;
    }

    void push_front(T val)
    {
        Node<T>* newnode = new Node<T>(val);
        if(head==nullptr)
        {
            head = tail = newnode;
        }
        else
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        size++;
    }

    void print()
    {
        Node<T>* temp = head;
        while(temp!=nullptr)
        {
            std::cout<<temp->data<<" <-> ";
            temp = temp->next;
        }
        std::cout<<"NULL\n";
    }

    Node<T>* gettail()
    {
        return tail;
    }

    Node<T>* searcher(T key) 
    {
        Node<T>* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

};

#endif