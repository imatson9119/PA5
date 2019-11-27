#include "ChainingHashTable.h"
#include "ProbingHashTable.h"
#include "DoubleHashTable.h"
#include "StopWatch.h"
#include <fstream>

using namespace std;
int main(){
	////////////////////////////////////////////////////////////
	//Default code
	////////////////////////////////////////////////////////////
	
	cout << "Please enter the name of the input file (including extension): ";
	string fileName;
	cin >> fileName;
	DoubleHashTable dht;
	ChainingHashTable cht;
	ProbingHashTable pht;
	ifstream file(fileName);
	while(!file.eof()){
		string word;
		file >> word;
		if (word != "") {
			dht.insert(word, 1);
			cht.insert(word, 1);
			pht.insert(word, 1);
		}
	}
	pht.printAll("Probing.txt");
	cht.printAll("Chaining.txt");
	dht.printAll("DoubleHashing.txt");
	
	////////////////////////////////////////////////////////////
	//Code for testing variable insertions
	////////////////////////////////////////////////////////////
	/*
	int n = 1000000;
	const int numPoints = 100;
	const int numTrials = 100;
	double data[numPoints] = { 0 };
	for (int trial = 1; trial <= numTrials; trial++) {
		ChainingHashTable ht;
		cout << "Starting trial " << trial << endl;
		for (int i = 0; i < numPoints; i++) {
			StopWatch t;
			ifstream file("dictionary.txt");
			t.start();
			for (int j = 0; j < n / numPoints; j++) {
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
	for (int i = 1; i < numPoints; i++) {
		data[i] = data[i] + data[i - 1];
	}
	for (int i = 0; i < numPoints; i++) {
		cout << data[i] << endl;
	}
	*/


	////////////////////////////////////////////////////////////
	//Code for testing variable load factor
	////////////////////////////////////////////////////////////
	/*
	int n = 10000;
	const int numPoints = 99;
	const int numTrials = 100;
	double start = .01;
	double data[numPoints] = { 0 };
	for (int trial = 1; trial <= numTrials; trial++) {
		cout << "Starting trial " << trial << endl;
		for (int i = 0; i < numPoints; i++) {
			if (i % 10 == 0) {
				cout << "\tTrial #" << i << endl;
			}
			ProbingHashTable ht;
			ht.setLoadFactor(start + (1 - start) / numPoints * i);
			StopWatch t;
			ifstream file("dictionary.txt");
			t.start();
			for (int j = 0; j < n; j++) {
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
	}*/
}