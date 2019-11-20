#include "ChainingHashTable.h"

using namespace std;
int main(){
	ChainingHashTable a;
	for (int i = 0; i < 1000000; i++) {
		a.insert("test" + to_string(i), 1);
	}
	a.display();
}