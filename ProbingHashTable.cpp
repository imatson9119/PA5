#include "ProbingHashTable.h"

using namespace std;
// constructor (NOTE: graders will use a default constructor for testing)
ProbingHashTable::ProbingHashTable() {
	
}

// destructor
ProbingHashTable::~ProbingHashTable() {
	delete[] hashTable;
}

// inserts the given string key
void ProbingHashTable::insert(std::string key, int val) {
	int index = hash(key);
	bool newItem = true;
	while (hashTable[index].second != 0) {
		if (hashTable[index].first == key) {
			newItem = false;
			hashTable[index].second++;
			break;
		}
		index = (index + 1) % capacity;
	}
	if (newItem) {
		hashTable[index] = pair<string, int>(key, val);
		size++;
		if (size / (1.0 * capacity) > .5) {
			resize();
		}
	}
}
void ProbingHashTable::resize() {
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
int ProbingHashTable::remove(std::string key) {

	return 0;
}

// getter to obtain the value associated with the given key
int ProbingHashTable::get(std::string key) {

	return 0;
}

// prints number of occurrances for all given strings to a txt file
void ProbingHashTable::printAll(std::string filename) {

}
void ProbingHashTable::display() {
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