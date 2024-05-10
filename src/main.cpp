#include <iostream>
#include "LinkedList.hpp"
#include "StaticHashMap.hpp"
#include <string>

int main()
{
    jds::LinkedList<int> myLinkedList;
    jds::StaticHashMap<std::string, int> myHashmap(500);

    std::cout << myHashmap.contains("key1") << std::endl;
    myHashmap.addOrUpdate("key1", 5);
    std::cout << myHashmap.contains("key1") << std::endl;
    std::cout << myHashmap.get("key1") << std::endl;
    myHashmap.addOrUpdate("key1", 666);
    std::cout << myHashmap.get("key1") << std::endl;

    myHashmap.addOrUpdate("key2", 8); //key2 is generating a collision with key1 since hash("key1") mod 500 == hash("key2") mod 5, found this by luck :=)
    std::cout << myHashmap.contains("key2") << std::endl;
    std::cout << myHashmap.get("key2") << std::endl;

    std::cout << myHashmap.get("key1") << std::endl;
}