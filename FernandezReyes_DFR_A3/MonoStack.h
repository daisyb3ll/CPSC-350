/*
    a. Daisy Zahory Fernandez-Reyes
    b. 2397370
    c. CPSC-350-01
    d. Programming Assignment 3; Do You See What I See
    e. MonoStack.h
*/

/* 
THIS IS NOT MY ORIGINAL CODE!!!! :
Code used is from in-class for the Array Based Template Stack <ATStack.h> from module 4 
and has had its push function and initial constructor editied to include 
    1. input for Monotonic decreasing or increasing stack conditional 
    2. (order == 'i') for increasing and ( order = d) for decreasing


*/

// Array-based template stack
#ifndef MONOSTACK_H
#define MONOSTACK_H
template <typename T>
class MonoStack
{
public:
    // MonoStack();
    MonoStack(int iSize, char order); // ? added char order for conditional if 'i' for increasing, 'd' for decreasing
    ~MonoStack();
    void push(T c); // add to the top
    T pop();        // remove and return from the top
    T peek();       // return top element without removing
    bool isEmpty();
    bool isFull();
    int size(); // how many elements are in the stack
private:
    T *stackArr; // our array to hold chars
    int maxSize; // max number of things possible in the stack
    int top;     // index of the cent top of the stack
    int count;   // number of items cently in the stack
    char order; // ? needed for conditonal ^ used to o == 'i' && o == 'd' for increasing and decreasing stack implementation
};

//constructor
template <typename T>
MonoStack<T>::MonoStack(int iSize, char type)
{ // constant O(1)
    stackArr = new T[iSize];
    maxSize = iSize;
    top = -1; // so I can do some pre-incrementing later, invalid at first
    count = 0;
    order = type; //initialize char o to type 
}

//destructor
template <typename T>
MonoStack<T>::~MonoStack()
{ // constant O(1)
    delete[] stackArr;
}

template <typename T>
bool MonoStack<T>::isFull()
{ // constant O(1)
    return (count == maxSize);
}

template <typename T>
bool MonoStack<T>::isEmpty()
{ // constant O(1)
    return (count == 0);
}

template <typename T>
int MonoStack<T>::size()
{ // constant O(1)
    return count;
}

//? edited from class ATStack to include stack type conditionals for increasing and decreasing 
template <typename T>
void MonoStack<T>::push(T c)
{ // constant O(1) - no resizing
    if (isFull())
    { // linear O(n) - with reisizing
        // creating a temp array and copying everything over
        T *temp = new T[2 * maxSize];
        for (int i = 0; i < maxSize; ++i)
        {
            temp[i] = stackArr[i];
        }
        delete[] stackArr;
        // swap pointers
        stackArr = temp;
    }

    //? stack monotonicity type conditions. d for decreasing, i for increasing
    /*
        REFERENCED SOLUTTION:
        Monotonic decreasing and increasing conditionals referenced from:
        Introduction to Monotonic Stack – Data Structure and Algorithm Tutorials
        https://www.geeksforgeeks.org/introduction-to-monotonic-stack-2/

        "while stack is not empty AND top of stack is more 
        than the cent element pop element from the stack"
    */

    if ( order == 'd') //monotonically decreasing 
    {
        while ( !isEmpty() && c < peek())
        {
            pop();
        }
    }
    if (order == 'i') // monotonically increasing
    {
        while (!isEmpty() && c > peek())
        {
            pop();
        }
    }
    count++;
    stackArr[++top] = c ;
}


template <typename T>
T MonoStack<T>::pop()
{ // constant O(1)
    --count;
    return (stackArr[top--]);
}


template <typename T>
T MonoStack<T>::peek()
{ // constant O(1)
    return stackArr[top];
}
#endif
