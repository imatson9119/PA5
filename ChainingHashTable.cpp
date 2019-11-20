#include "ChainingHashTable.h"

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
	for (int i = 0; i < hashTable[index].size(); i++) {
		pair<string,int> a = hashTable[index].at(i);
		if (a.first == key) {
			newItem = false;
			a.second++;
			break;
		}
	}
	if (newItem) {
		size++;
		hashTable[index].push_back(pair<string, int>(key, val));
	}
	if (capacity / (1.0 * size) > .9) {
		resize();
	}
}
void ChainingHashTable::resize() {
	vector<pair<string, int>>* oldTable = hashTable;
	hashTable = new vector<pair<string, int>>[capacity * 2];
	for (int i = 0; i < capacity; i++) {
		vector<pair<string, int>> *curList = &oldTable[i];
		if (curList->size() != 0) {
			for (int j = 0; j < curList->size(); j++) {
				insert(curList->at(j).first,curList->at(j).second);
			}
		}
	}
	delete[] oldTable;
	capacity *= 2;
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ChainingHashTable::remove(std::string key) {
	int index = hash(key);
	return 0;
}

// getter to obtain the value associated with the given key
int ChainingHashTable::get(std::string key) {

	return 0;
}

// prints number of occurrances for all given strings to a txt file
void ChainingHashTable::printAll(std::string filename) {

}
void ChainingHashTable::display() {
	cout << "{";
	for (int i = 0; i < capacity; i++) {
		vector<pair<string, int>>* curList = &hashTable[i];
		cout << "[";
		for (int j = 0; j < curList->size(); j++) {
			cout << "(" << curList->at(j).first << ", " << curList->at(j).second << "), ";
		}
		cout << "], ";
	}
	cout << "}";
}