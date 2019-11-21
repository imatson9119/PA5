#ifndef HASH_H
#define HASH_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

using namespace std;
// Chaining hash table class


class HashTable{
	protected:
	// helper functions
	int hash(std::string s); 
	
	// TODO: insert necessary variables for your hash table here

	int size = 0;
	int primes[28] = { 11,17,37,67,131,257,521,1031,2053,4091,8179,16349,32693,65381,130769,261509,523021,
		1046029,2092039,4184087,8368169,16736257,33472553,66945049,133890067,267780109,535560199,1071120443 };
	int primesInd = 7;
	int capacity = primes[primesInd];


	public: 
	HashTable();
	~HashTable(); 
	virtual void insert(std::string key, int val) = 0; 
	virtual int remove(std::string key) = 0; 
	virtual int get(std::string key) = 0; 
	virtual void printAll(std::string filename) = 0;
	bool isEmpty() const; 
};

#endif