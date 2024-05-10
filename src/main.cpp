#include <iostream>
#include "LinkedList.hpp"

int main()
{
    jds::LinkedList<int> myLinkedList;
    myLinkedList.push_back(888);
    myLinkedList.push_back(777);
    myLinkedList.push_back(666);

    for(int &i : myLinkedList)
    {
        i = 3;
    }

    for(int i : myLinkedList)
    {
        std::cout << i << std::endl;
    }
}