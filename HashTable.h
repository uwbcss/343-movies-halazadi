#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>
#include <utility>
#include <vector>

template <typename KeyType, typename ValueType>
class HashTable {
public:
    explicit HashTable(int size = 1000);  // Fix: mark single-arg constructor explicit
    ~HashTable();

    void insert(const KeyType& key, const ValueType& value);
    ValueType get(const KeyType& key) const;
    bool contains(const KeyType& key) const;

private:
    int hashFunction(const KeyType& key) const;
    std::vector<std::list<std::pair<KeyType, ValueType>>> table;
    int capacity;
};

#endif
