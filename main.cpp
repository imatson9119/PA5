#include "ChainingHashTable.h"
#include "ProbingHashTable.h"
#include "DoubleHashTable.h"
#include <fstream>

using namespace std;
int main(){
	DoubleHashTable ht;
	ht.insert("It's", 1);
	ht.insert("time", 1);
	ht.insert("to", 1);
	ht.insert("test", 1);
	ht.insert("how", 1);
	ht.insert("robust", 1);
	ht.insert("this", 1);
	ht.insert("hash", 1);
	ht.insert("table", 1);
	ht.insert("really", 1);
	ht.insert("is.", 1);
	ht.insert("Have", 1);
	ht.insert("fun!", 1);
	ht.insert("fun!", 1);
	ht.insert("fun!", 1);
	ht.display();

	/*
	ifstream file("dictionary.txt");
	while(!file.eof()){
		string word;
		file >> word;
		if(word != "")
			ht.insert(word, 1);
	}
	ht.printAll("outFile.txt");
	*/
}