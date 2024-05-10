# JDataStructures
Implementing my own data structures in C++ for learning purposes.

## How to build the project ?
1. Install CMake (at least version 3.16).
2. Under Windows install MinGW.
3. Clone the repository using git CLI or via GitHub.
4. At the root of the repository directory, type the command : ```cmake -B build``` or ```cmake -B build -G "MinGW Makefiles"``` if under Windows.
5. At the root of the repository directory, type the command : ```cmake --build build```.

## Linked list
I've implemented a linked list with knowledge of the end, i.e. the complexity of adding an element at the end is not O(n) but O(1).

It is possible to iterate very simply through this linked list via the STL iterators end and begin, or simply via a for loop.

<ins>Example of usage :</ins>
```c++
jds::LinkedList<int> myLinkedList;
myLinkedList.push_back(1); //Adding the data 1 at the end of the linked list
myLinkedList.push_back(2); //Adding the data 2 at the end of the linked list
myLinkedList.push_back(3); //Adding the data 3 at the end of the linked list

//The linked list is now 1,2,3

//For loop to update the data for each node in the linked list to the value 3, as we use the & operator (reference)
for(int &i : myLinkedList)
{
    i = 3;
}

//For loop to print each linked list node
for(int i : myLinkedList)
{
    std::cout << i << std::endl;
}
```
<ins>TODO : </ins>
* Add insert at index method
* Add remove at index method
* Add remove_at_start method
* Add remove_at_end method
* Create a table specifying the performance of the data structure in big O notation.

## Static hash table
This data structure is called a static hash table because it's a classic hash table, but I just haven't yet implemented the ability to add elements on the fly like a dynamic array would do with a reallocation-copy.

For the hash function I've used ``` (std::hash<Key>()(key) % hashMapLength) ```, the modulo is used to transform the hash given by std::hash (which is an unsigned int) into a numeric value 
within the array limits.

Collisions are handled using linked lists as specified on the [hash table wikipedia page](https://fr.wikipedia.org/wiki/Table_de_hachage#Cha%C3%AEnage).

<ins>Example of usage :</ins>
```c++
jds::StaticHashMap<std::string, int> myHashmap(500);

myHashmap.addOrUpdate("key1", 5);
myHashmap.addOrUpdate("key1", 666);
std::cout << "Contains key1 ? " << myHashmap.contains("key1") << std::endl; //Contains key1 ? : 1
std::cout << "key1 value : " << myHashmap.get("key1") << std::endl; //key1 value : 666
```

<ins>TODO :</ins>
* Add iterator
* Add remove function
* Create a table specifying the performance of the data structure in big O notation.
