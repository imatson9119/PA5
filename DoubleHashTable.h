#ifndef DOUBLEHASHING_H
#define DOUBLEHASHING_H

#include "HashTable.h"


// Double hashing hash table class
class DoubleHashTable : public HashTable {
    private:
    // helper functions
    int secondHash(std::string s);

    // TODO: insert additional variables here
	pair<string, int>* hashTable = new pair<string, int>[capacity];

    public: 
    DoubleHashTable();
    ~DoubleHashTable(); 
    void insert(std::string key, int val); 
    int remove(std::string key); 
    int get(std::string key); 
    void printAll(std::string filename);
	void display(); //for debugging purposes
	void resize();
};

#endif