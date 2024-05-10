#pragma once

#include <utility>
#include <functional>

#include "LinkedList.hpp"

namespace jds
{
    //Unresizable HashMap, no dynamic reallocation like in dynamic array
    //Using linked list to handle collisions
    template <typename Key, typename Value>
    class StaticHashMap
    {
        private:
            size_t _size;
            LinkedList<std::pair<Key,Value>>* _buckets;

            size_t hash(Key key);
        public:
            StaticHashMap(size_t size) : _size(size)
            {
                _buckets = new LinkedList<std::pair<Key,Value>>[_size];
            }

            ~StaticHashMap()
            {
                delete[] _buckets; //deletion is propagated to each LinkedList objects of _buckets
            }

            //Add a key-value pair using raw values or update if existing key
            void addOrUpdate(const Key key, const Value value);

            //Add a key-value pair using std::pair type or update if existing key
            void addOrUpdate(const std::pair<Key,Value> pair);

            //Get reference to value by key
            const Value& get(const Key key);

            //Check if HashMap contains a certain key
            bool contains(const Key key);
    };

    template<typename Key, typename Value>
    size_t StaticHashMap<Key,Value>::hash(Key key)
    {
        return (std::hash<Key>()(key) % _size);
    }

    template <typename Key, typename Value>
    void StaticHashMap<Key,Value>::addOrUpdate(const Key key, const Value value)
    {
        size_t index = hash(key);
        LinkedList<std::pair<Key,Value>>* currentBucket = &_buckets[index];

        for(std::pair<Key,Value>& pair : *currentBucket)
        {
            if(pair.first == key)
            {
                pair.second = value;
                return;
            }
        }

        _buckets[index].push_back(std::make_pair(key, value));
    }

    template <typename Key, typename Value>
    void StaticHashMap<Key,Value>::addOrUpdate(const std::pair<Key,Value> pair)
    {
        add(pair.first, pair.second);
    }

    template <typename Key, typename Value>
    const Value& StaticHashMap<Key,Value>::get(const Key key)
    {
        size_t index = hash(key);
        for(std::pair<Key,Value>& pair : _buckets[index])
        {
            if(pair.first == key) return pair.second;
        }
        throw std::out_of_range("Key not found");
    }

    template <typename Key, typename Value>
    bool StaticHashMap<Key,Value>::contains(const Key key)
    {
        size_t index = hash(key);
        for(std::pair<Key,Value> pair : _buckets[index])
        {
            if(pair.first == key) return true;
        }
        return false;
    }
}