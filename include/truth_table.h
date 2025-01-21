#ifndef TRUTH_TABLE_H
#define TRUTH_TABLE_H

class TruthTable {
private:
    int n; 
    int k;                 
    char** arr;
public:
    TruthTable();
    ~TruthTable();
	int getNumberofRows();
    int getNumberofvariables();
    void generateTruthTable(int numVariables);
    void printTruthTable();
	char getTruthTableIndex(int i, int j);
};

#endif