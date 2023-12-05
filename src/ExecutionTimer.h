#pragma once
#include <iostream>
#include <sstream>
#include <chrono>
#include <unordered_map>
#include "Parser.h"
using namespace std;

class ExecutionTimer{
    public:
    static void insert();
    static void search(int n);
    static void traverse();
    static void top5Locations();
    static void averageAge();
};

void ExecutionTimer::insert(){
    cout << "Inserting 9600 rows of 19 columns into each tree..." << endl;

    auto start_time = chrono::high_resolution_clock::now();
	BTree btree = Parser::generateBTree();
	auto end_time = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "Time to insert into B tree: " << duration.count() << " microseconds" << endl;

	auto start_time2 = chrono::high_resolution_clock::now();
	RedBlackTree rbtree = Parser::generateRBTree();
	auto end_time2 = chrono::high_resolution_clock::now();
	auto duration2 = chrono::duration_cast<chrono::microseconds>(end_time2 - start_time2);
    cout << "Time to insert into Red Black Tree: " << duration2.count() << " microseconds" << endl;
}

void ExecutionTimer::search(int n){
    cout << "Searching for " << n << " random records in each tree..." << endl;

    set<int> records;
    while(records.size() < n){
        int random_record = rand() % 9599;
        if (!records.count(random_record)) records.emplace(random_record);
    }

    BTree btree = Parser::generateBTree();

    auto start_time = chrono::high_resolution_clock::now();
    for (int r : records) btree.search(r);
	auto end_time = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "Time to find in B tree: " << duration.count() << " microseconds" << endl;

	RedBlackTree rbtree = Parser::generateRBTree();

	auto start_time2 = chrono::high_resolution_clock::now();
    for (int r : records) rbtree.search(r);
	auto end_time2 = chrono::high_resolution_clock::now();
	auto duration2 = chrono::duration_cast<chrono::microseconds>(end_time2 - start_time2);
    cout << "Time to find in Red Black Tree: " << duration2.count() << " microseconds" << endl;
}

void ExecutionTimer::traverse(){
    cout << "Traversing both trees..." << endl;

    BTree btree = Parser::generateBTree();

    auto start_time = chrono::high_resolution_clock::now();
	btree.inorder();
	auto end_time = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "Time to traverse B tree: " << duration.count() << " microseconds" << endl;

    RedBlackTree rbtree = Parser::generateRBTree();

	auto start_time2 = chrono::high_resolution_clock::now();
	rbtree.inorder();
	auto end_time2 = chrono::high_resolution_clock::now();
	auto duration2 = chrono::duration_cast<chrono::microseconds>(end_time2 - start_time2);
    cout << "Time to traverse Red Black Tree: " << duration2.count() << " microseconds" << endl;
}

void ExecutionTimer::top5Locations(){
    RedBlackTree rbt = Parser::generateRBTree();
    unordered_map<string, int> mp = rbt.statesInorder();
    vector<pair<string, int>> top5;
    auto customComparator = [](const std::pair<string, int>& a, const std::pair<string, int>& b) {
        return a.second > b.second;
    };
    for(auto state : mp){
        top5.push_back(make_pair(state.first, state.second));
    }
    sort(top5.begin(), top5.end(), customComparator);

    cout << "Most active states:\n";
    for(int i = 0; i < 5; i++){
        auto p = top5[i];
        cout << p.first << " " << p.second << endl;
    }
}

void ExecutionTimer::averageAge(){
    RedBlackTree rbt = Parser::generateRBTree();
    double avgAge = rbt.agesInorder();
    cout << "Average slave age is " << avgAge << endl;
}