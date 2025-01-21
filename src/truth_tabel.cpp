#include <iostream>
#include "truth_table.h"
using namespace std;
TruthTable::TruthTable() : n(0), k(0), arr(nullptr) {}
TruthTable::~TruthTable() {
   /* try{
    if (arr != nullptr) {
        for (int i = 0; i < k; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
	} catch (...) {
        cout << "Error: " << endl;
    }*/
}
void TruthTable::generateTruthTable(int numVariables) {
    n = numVariables;
    k = 1;
    for (int i = 0; i < n; i++) {
        k *= 2;
    }

    if (arr != nullptr) {
        for (int i = 0; i < k; i++) {
            delete[] arr[i];
        }
        delete[] arr;
        arr = nullptr; 
    }
    arr = new char* [k];
    for (int i = 0; i < k; i++) {
        arr[i] = new char[n];
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 'T';
        }
    }
    bool check = false;
    int count = 1;
    int* ct = new int[n];
    for (int i = 0; i < n; i++) {
        ct[i] = count;
		count += count;
    }

    for (int i = 0; i < n; i++) {
        int temp = 0;
        int cnt = ct[i];
        for (int j = 0; j < k; j++) {
            if (temp == cnt) {
                check = !check;
                temp = 0;
            }
            arr[j][i] = check ? 'T' : 'F';
            temp++;
        }
    }

    delete[] ct;
}
void TruthTable::printTruthTable() {
    cout << endl;
    cout << "-----------------" << endl;
    cout << "|    TRUTH TABLE    |" << endl;
    cout << "-----------------" << endl;
    for (int i = 0; i < k; i++) {
        cout << " | ";
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " | ";
        }
        cout << endl;
    }
}
char TruthTable::getTruthTableIndex(int i, int j) {
	if (i < k && j < n) {
		return arr[i][j];
	}
	else {
		return 'E';
	}
}
int TruthTable::getNumberofRows() {
	return k;
}
int TruthTable::getNumberofvariables() {
	return n;
}