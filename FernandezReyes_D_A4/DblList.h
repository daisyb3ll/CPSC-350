#ifndef DBL_LIST_H
#define DBL_LIST_H

#include "ListNode.h"

template<typename T>
class DblList
    {
    public:
        DblList();
        virtual ~DblList();
        int getSize();
        bool isEmpty();
        T get(int pos);
        T remove(int pos);
        T removeFront();
        T removeBack();
        void add(int pos, T data);
        void addFront(T data);
        void addBack(T data);
    private:
        ListNode<T>* m_front;
        ListNode<T>* m_back;
        int m_size;
    };

template<typename T>
DblList<T>::DblList()
    {
    m_front = NULL;
    m_back = NULL;
    m_size = 0;
    }

template<typename T>
DblList<T> ::~DblList()
    {
    //to do - free memory - loop through the list and delete all nodes
    m_front = NULL;
    m_back = NULL;
    m_size = 0;
    }

template<typename T> //O(1) - constant
int DblList<T>::getSize()
    {
        return m_size;
    }

template<typename T> //O(1) - constant
bool DblList<T>::isEmpty()
    {
        return (m_size == 0);
    }

template<typename T>
void DblList<T>::addFront(T data){ //constant
    ListNode<T>* newNode = new ListNode<T>(data);

    if(!isEmpty()){
        m_front->m_prev = newNode;
        newNode->m_next = m_front;
        }else{
            m_back = newNode;
        }
        m_front = newNode;
        ++m_size;
    }

template<typename T>
void DblList<T>::addBack(T data){ //constant
    ListNode<T>* newNode = new ListNode<T>(data);
        if(!isEmpty()){
            m_back->m_next = newNode;
            newNode->m_prev = m_back;
        }else{
            m_front = newNode;
        }
            m_back = newNode;
            ++m_size;
        }
    

template<typename T>
void DblList<T>::add(int pos, T data){ //linear
    if(isEmpty()){
        addFront(data);
    }else if(pos == 0){
        addFront(data);
    }else if(pos >= m_size){
        addBack(data);
    }else{
        ListNode<T>* current = m_front;
        int cPos = 0;
        while(cPos != pos){
        current = current->m_next;
        ++cPos;
    }
    ListNode<T>* newNode = new ListNode<T>(data);
    current->m_prev->m_next = newNode;
    newNode->m_prev = current->m_prev;
    current->m_prev = newNode;
    newNode->m_next = current;
    ++m_size;
    }
}

template<typename T>
T DblList<T>::removeFront(){ //constant
//TODO: make sure not empty
    T data;
    data = m_front->m_data;
    if(m_size == 1){
        delete m_front; //since there's only one item, the back and front are the
        //same memory
        m_front = NULL;
        m_back = NULL;
    }else{
    ListNode<T>* currFront = m_front;
    m_front = m_front->m_next;
    m_front->m_prev = NULL;
    delete currFront;
    }
    --m_size;
    return data;
    }

template<typename T>
T DblList<T>::removeBack(){ //constant
    T data;
    data = m_back->m_data;
//TODO: make sure not empty
    if(m_size == 1){
        delete m_back; //could also use m_front, since m_back and m_front point to the same place
        m_front = NULL;
        m_back = NULL;
    }else{
        ListNode<T>* currBack = m_back;
        m_back = m_back->m_prev;
        m_back->m_next = NULL;
        delete currBack;
    }
    --m_size;
    return data;
}

template<typename T>
T DblList<T>::remove(int pos){ //linear
//TODO: make sure not empty
    T data;
    if(pos == 0){
        data = removeFront();
    }else if(pos >= m_size){
        data = removeBack();
    }else{
        ListNode<T>* current = m_front;
        int cPos = 0;
    while(cPos != pos){
        current = current->m_next;
        ++cPos;
    }
        data = current->m_data;
        current->m_prev->m_next = current->m_next;
        current->m_next->m_prev = current->m_prev;
        delete current;
        --m_size;
    }
        return data;
    }   

template<typename T>
T DblList<T>::get(int pos){ //linear
        //TODO: make sure position is in range
        ListNode<T>* current = m_front;
        int cPos = 0;
    while(cPos != pos){
        current = current->m_next;
        ++cPos;
    }
        return current->m_data; 
    }
#endif
