#include "ChainingHashTable.h"
#include "ProbingHashTable.h"
#include "DoubleHashTable.h"
#include "StopWatch.h"
#include <fstream>

using namespace std;
int main(){
	
	int n = 1000000;
	const int numPoints = 100;
	const int numTrials = 20;
	double data[numPoints] = { 0 };
	for (int trial = 1; trial <= numTrials; trial++) {
		cout << "Starting trial " << trial << endl;
		for (int i = 0; i < numPoints; i++) {
			ProbingHashTable ht;
			if (i % 10 == 0) {
				cout << "\tTest #" << i << endl;
			}
			StopWatch t;
			ifstream file("dictionary.txt");
			t.start();
			for (int j = 0; j < i * n / numPoints; j++) {
				string word;
				file >> word;
				if (word != "")
					ht.insert(word, 1);
			}
			t.stop();
			data[i] += t.seconds() / numTrials;
		}
	}
	cout << endl;
	for (int i = 0; i < numPoints; i++) {
		cout << data[i] << endl;
	}
	/*
	ifstream file("dictionary.txt");
	while(!file.eof()){
		string word;
		file >> word;
		if(word != "")
			ht.insert(word, 1);
	}
	ht.printAll("outFile1.txt");
	*/
}