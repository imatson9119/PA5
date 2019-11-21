#include "ChainingHashTable.h"
#include "ProbingHashTable.h"
#include "DoubleHashTable.h"
#include <fstream>

using namespace std;
int main(){
	DoubleHashTable ht;

	
	ifstream file("dictionary.txt");
	while(!file.eof()){
		string word;
		file >> word;
		if(word != "")
			ht.insert(word, 1);
	}
	ht.printAll("outFile1.txt");
	
}