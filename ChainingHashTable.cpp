#include "ChainingHashTable.h"
#include "Exceptions.h"
#include <fstream>

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor (NOTE: graders will use a default constructor for testing)
ChainingHashTable::ChainingHashTable() {
	
}

// destructor
ChainingHashTable::~ChainingHashTable() {
	delete[] hashTable;
}

// inserts the given string key
void ChainingHashTable::insert(std::string key, int val) {
	int index = hash(key);
	bool newItem = true;
	vector<pair<string, int>> *curList = &hashTable[index];
	for (int i = 0; i < curList->size(); i++) {
		pair<string, int>* a = &curList->at(i);
		if (a->first == key) {
			newItem = false;
			a->second++;
			break;
		}
	}
	if (newItem) {
		size++;
		hashTable[index].push_back(pair<string, int>(key, val));
		if (size / (1.0 * capacity) > .9) {
			resize();
		}
	}
}
void ChainingHashTable::resize() {
	capacity *= 2;
	size = 0;
	vector<pair<string, int>>* oldTable = hashTable;
	hashTable = new vector<pair<string, int>>[capacity];
	for (int i = 0; i < (capacity/2); i++) {
		vector<pair<string, int>> *curList = &oldTable[i];
		if (curList->size() != 0) {
			for (int j = 0; j < curList->size(); j++) {
				string a = curList->at(j).first;
				int b = curList->at(j).second;
				insert(a, b);
			}
		}
	}
	delete[] oldTable;
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ChainingHashTable::remove(std::string key) {
	vector<pair<string, int>>* curList = &hashTable[hash(key)];
	bool removed = false;
	for (int i = 0; i < curList->size(); i++) {
		if (curList->at(i).first == key) {
			curList->erase(curList->begin() + i);
			if (curList->size() == 0) {
				size--;
			}
			removed = true;
			break;
		}
	}
	if (!removed) {
		throw ItemNotFoundException();
	}
	return 0;
}

// getter to obtain the value associated with the given key
int ChainingHashTable::get(std::string key) {
	vector<pair<string, int>>* curList = &hashTable[hash(key)];
	for (int i = 0; i < curList->size(); i++) {
		if (curList->at(i).first == key) {
			return curList->at(i).second;
		}
	}
	return 0;
}

// prints number of occurrances for all given strings to a txt file
void ChainingHashTable::printAll(std::string filename) {
	ofstream file(filename);
	for (int i = 0; i < capacity; i++) {
		vector<pair<string, int>>* curList = &hashTable[i];
		for (int j = 0; j < curList->size(); j++) {
			file << curList->at(j).first << " " << curList->at(j).second << endl;
		}
	}
}
void ChainingHashTable::display() {
	cout << endl << "{";
	for (int i = 0; i < capacity; i++) {
		vector<pair<string, int>>* curList = &hashTable[i];
		if (curList->size() > 0) {
			cout << "[";
			for (int j = 0; j < curList->size(); j++) {
				cout << "(" << curList->at(j).first << ", " << curList->at(j).second << "), ";
			}
			cout << "], ";
		}
	}
	cout << "}" << endl;
}