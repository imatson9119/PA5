#include "DoubleHashTable.h"

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor (NOTE: graders will use a default constructor for testing)
DoubleHashTable::DoubleHashTable() {
	
}

// destructor
DoubleHashTable::~DoubleHashTable() {
	delete[] hashTable;
}

// inserts the given string key
void DoubleHashTable::insert(std::string key, int val) {
	int index = hash(key);
	int newIndex = index;
	bool newItem = true;
	int i = 1;
	while (hashTable[newIndex].second != 0) {
		if (hashTable[newIndex].first == key) {
			newItem = false;
			hashTable[newIndex].second++;
			break;
		}
		newIndex = (index + i * secondHash(key)) % capacity;
		i++;
	}
	if (newItem) {
		hashTable[index] = pair<string, int>(key, val);
		size++;
		if (size / (1.0 * capacity) > .5) {
			resize();
		}
	}
}
void DoubleHashTable::resize() {
	capacity *= 2;
	size = 0;
	pair<string, int>* oldTable = hashTable;
	hashTable = new pair<string, int>[capacity];
	for (int i = 0; i < (capacity / 2); i++) {
		pair<string, int>* curPair = &oldTable[i];
		if (curPair->second != 0) {
			insert(curPair->first, curPair->second);
		}
	}
	delete[] oldTable;
}
// removes the given key from the hash table - if the key is not in the list, throw an error
int DoubleHashTable::remove(std::string key) {

	return 0;
}

// getter to obtain the value associated with the given key
int DoubleHashTable::get(std::string key) {

	return 0;
}

// prints number of occurrances for all given strings to a txt file
void DoubleHashTable::printAll(std::string filename) {

}

// helper functions 
int DoubleHashTable::secondHash(std::string s) {
	int hash = 0;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		hash = 83 * hash + s.at(n-i-1);
	}
	return abs(hash) % capacity;
	return 0;
}
void DoubleHashTable::display() {
	cout << endl << "{";
	for (int i = 0; i < capacity; i++) {
		pair<string, int>* curPair = &hashTable[i];
		if (curPair->second != 0) {
			cout << "(" << curPair->first << ", " << curPair->second << "), ";
		}
		else {
			cout << "(), ";
		}
	}
	cout << "}" << endl;
}
