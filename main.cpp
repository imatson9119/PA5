#include "ChainingHashTable.h"
#include <fstream>

using namespace std;
int main(){
	ChainingHashTable ht;
	/*
	for (int i = 0; i < 100; i++) {
		ht.insert("hzxcvzxcvzcvzxcvzxcvzxcvzxzcxvzxcvzxcv",1);
	}*/
	
	ifstream file("dictionary.txt");
	while(!file.eof()){
		string word;
		file >> word;
		if(word != "")
			ht.insert(word, 1);
	}
	ht.printAll("outFile.txt");
}