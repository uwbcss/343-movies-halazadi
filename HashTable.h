#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>
#include <utility>
#include <vector>

template <typename KeyType, typename ValueType>
class HashTable {
public:
    explicit HashTable(int size = 1000);  // HashTable constructor
    ~HashTable(); // HashTable destructor

    void insert(const KeyType& key, const ValueType& value); // Inserts a key-value pair
    ValueType get(const KeyType& key) const; // Retrieves the value for a key
    bool contains(const KeyType& key) const; // Checks if the key exists

private:
    int hashFunction(const KeyType& key) const; // Computes the hash for a key
    std::vector<std::list<std::pair<KeyType, ValueType>>> table;
    int capacity;
};

#endif