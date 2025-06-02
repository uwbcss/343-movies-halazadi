#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>
#include <utility>

template<typename KeyType, typename ValueType>
class HashTable {
public:
    HashTable(int size = 1000);
    ~HashTable();

    void insert(const KeyType& key, const ValueType& value);
    ValueType get(const KeyType& key) const;
    bool contains(const KeyType& key) const;

private:
    int hashFunction(const KeyType& key) const;
    std::vector<std::list<std::pair<KeyType, ValueType>>> table;
    int capacity;
};

#include "HashTable.cpp" // Needed for template implementation

#endif
