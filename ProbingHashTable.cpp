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