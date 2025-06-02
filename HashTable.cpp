#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP

#include "HashTable.h"

template <typename KeyType, typename ValueType>
HashTable<KeyType, ValueType>::HashTable(int size) : capacity(size) {
  table.resize(capacity);
}

template <typename KeyType, typename ValueType>
HashTable<KeyType, ValueType>::~HashTable() {}

template <typename KeyType, typename ValueType>
int HashTable<KeyType, ValueType>::hashFunction(const KeyType &key) const {
  return key % capacity; // assumes KeyType is int (e.g., customer ID)
}

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::insert(const KeyType &key,
                                           const ValueType &value) {
  int idx = hashFunction(key);
  for (auto &pair : table[idx]) {
    if (pair.first == key) {
      pair.second = value;
      return;
    }
  }
  table[idx].emplace_back(key, value);
}

template <typename KeyType, typename ValueType>
ValueType HashTable<KeyType, ValueType>::get(const KeyType &key) const {
  int idx = hashFunction(key);
  for (const auto &pair : table[idx]) {
    if (pair.first == key) {
      return pair.second;
    }
  }
  return nullptr; // or ValueType{} for default
}

template <typename KeyType, typename ValueType>
bool HashTable<KeyType, ValueType>::contains(const KeyType &key) const {
  int idx = hashFunction(key);
  for (const auto &pair : table[idx]) {
    if (pair.first == key) {
      return true;
    }
  }
  return false;
}

#endif
