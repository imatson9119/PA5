#ifndef CHAINING_H
#define CHAINING_H

#include "HashTable.h"
#include <vector>
#include <utility>


// Chaining hash table class
class ChainingHashTable: public HashTable {
    private:
		vector<pair<string, int>>* hashTable = new vector<pair<string, int>>[capacity];
    public: 
    ChainingHashTable();
    ~ChainingHashTable(); 
    void insert(std::string key, int val); 
    int remove(std::string key); 
    int get(std::string key);
	void resize();
    void printAll(std::string filename);
	void display();
};

#endif