#ifndef CHAINING_H
#define CHAINING_H

#include "HashTable.h"
#include <vector>
#include <utility>

// Chaining hash table class
class ChainingHashTable: public HashTable {
    private:
		vector<pair<string, int>> hashTable[2000000];
		int size = 0;
    public: 
    ChainingHashTable();
    ~ChainingHashTable(); 
    void insert(std::string key, int val); 
    int remove(std::string key); 
    int get(std::string key);
    void printAll(std::string filename);
};

#endif