#pragma once
#include <iostream>
#include <sstream>
#include <set>
#include "RedBlackTree.h"
#include "BTree.h"
using namespace std;

//column schema
set<int> skip({4, 8, 22});
set<int> to_int({1, 12, 17, 18, 19});
set<int> to_double({20, 22, 23});

class Parser{
    public:
    static BTree generateBTree();
    static RedBlackTree generateRBTree();
};

// reads file and generates a B tree with all records. Note how packets are used to encapsulate variables
BTree Parser::generateBTree(){
    BTree bt;
    ifstream data_in("input/slavery_ids.csv");
	string line, val;
	vector<string> values;

    getline(data_in, line);
	while(getline(data_in, line)){
		stringstream ss(line);
		values.clear();
		int index = 1;
		while (getline(ss, val, ',')) {
			if(!skip.count(index))
            	values.push_back(val);
			index++;
        }
        int id = stoi(values[0]);
        Packet p(
            values[1],
            values[2],
            values[3],
            values[4],
            values[5],
            values[6],
            stoi(values[7]),
            values[8],
            values[9],
            values[10],
            values[11],
            stoi(values[12]),
            stoi(values[13]),
            stoi(values[14]),
            stod(values[15]),
            values[16],
            stod(values[17]),
            stod(values[18])
        );
        bt.insert(id, p);
	}
    return bt;
}

// reads file and generates a red black tree with all records. Note how packets are used to encapsulate variables

RedBlackTree Parser::generateRBTree(){
    RedBlackTree rbt;
    ifstream data_in("input/slavery_ids.csv");
	string line, val;
	vector<string> values;

    getline(data_in, line);
	while(getline(data_in, line)){
		stringstream ss(line);
		values.clear();
		int index = 1;
		while (getline(ss, val, ',')) {
			if(!skip.count(index))
            	values.push_back(val);
			index++;
        }
        int id = stoi(values[0]);
        Packet p(
            values[1],
            values[2],
            values[3],
            values[4],
            values[5],
            values[6],
            stoi(values[7]),
            values[8],
            values[9],
            values[10],
            values[11],
            stoi(values[12]),
            stoi(values[13]),
            stoi(values[14]),
            stod(values[15]),
            values[16],
            stod(values[17]),
            stod(values[18])
        );
        rbt.insert(id, p);
	}
    return rbt;
}