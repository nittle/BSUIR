#include<iostream>

template <class T>
class Stack {
private:
    // Index of the top element in the stack
    int _top;
    // Array to store stack elements, with a capacity of 100
    // elements
    T _arr[100];

public:
    // Constructor to initialize an empty stack
    Stack() { 
        _top = -1; 
    }

    // Function to add an element x to the top of the stack
    void push(T x)
    {
        // If the stack is full, throw ex
        if (_top >= 99) {
            throw "Stack overflow";
        }
        // Add element to the top of the stack and increment
        // top
        _arr[++_top] = x;
    }

    // Function to remove the top element from the stack
    T pop()
    {
        // If the stack is empty, throw ex
        if (_top < 0) {
            throw "Stack underflow";
        }
        // Remove the top element from the stack and
        // decrement top
        return _arr[_top--];
    }

    // Function to return the top element of the stack
    T peek()
    {
        // If the stack is empty, throw ex
        if (_top < 0) {
            throw "Stack is empty";
        }
        // Return the top element of the stack
        return _arr[_top];
    }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        // Return true if the stack is empty (i.e., top is
        // -1)
        return (_top < 0);
    }
};