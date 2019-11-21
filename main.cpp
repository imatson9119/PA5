#include "ChainingHashTable.h"
#include <fstream>

using namespace std;
int main(){
	ChainingHashTable ht;
	pair<string, int> *a = new pair<string,int>();
	cout << ht.hashTable[0].at(0).first;
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