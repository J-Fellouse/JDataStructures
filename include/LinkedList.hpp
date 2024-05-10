#pragma once

#include "stddef.h"
#include <iostream>

//jds = jules data structures
namespace jds
{
    template<typename T>
    class LinkedList
    {
        private:
            //Node of the linked list
            struct Node
            {
                T data;
                Node* nextNode;

                Node(T data, Node* nextNode)
                    : data(data), nextNode(nextNode) {}
            };

            class Iterator;

            Node* _headNode = nullptr;
            Node* _lastNode = nullptr;
            size_t _size = 0;
        public:
            //Delete all dynamically created LinkedListNode
            ~LinkedList();

            //Add an element at the end of the linked list
            void push_back(const T data);

            //Add the element at the top of the linked list
            void push_front(const T data);

            //Get the actual number of nodes in the linked list
            size_t size() const {return _size; }
            
            //Standard STL method used for iteration using for loop
            Iterator begin() const { return Iterator(_headNode); }
            
            //Standard STL method used for iteration using for loop
            Iterator end() const { return Iterator(nullptr); }
    };

    //Internal Iterator class
    template <typename T>
    class LinkedList<T>::Iterator
    {
        private:
            Node* _current;
        public:
            Iterator(Node* node = nullptr) : _current(node) {}

            //Iterating behavior
            Iterator& operator++()
            {
                _current = _current->nextNode;
                return *this;
            }

            //Used to access the data by reference
            T& operator*() { return _current->data; }

            //Used to access the data via pointer
            T* operator->() { return &_current->data; }

            //Inequality operator generally used as a condition to stop the loop
            bool operator!=(const Iterator& other) const { return _current != other._current; }

            //Equality operator generally used as a condition to stop the loop
            bool operator==(const Iterator& other) const { return _current == other._current; }
    };

    template <typename T>
    LinkedList<T>::~LinkedList()
    {
        struct Node* current = _headNode;
        while (current != nullptr)
        {
            struct Node* next = current->nextNode;
            delete current;
            current = next;
        }
    }

    template <typename T>
    void LinkedList<T>::push_back(const T data)
    {        
        Node* newNode = new Node(data, nullptr);
        _size++;

        if(_headNode == nullptr)
        {
            _headNode = newNode;
            _lastNode = _headNode;
            return;
        }

        _lastNode->nextNode = newNode;
        _lastNode = newNode;
    }

    template <typename T>
    void LinkedList<T>::push_front(const T data)
    {
        Node* newNode = new Node(data, _headNode);
        _size++;

        _headNode = newNode;

        if(_lastNode == nullptr)
        {
            _lastNode = _headNode;
        }
    }
}