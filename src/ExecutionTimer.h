#pragma once
#include <iostream>
#include <sstream>
#include <chrono>
#include "Parser.h"
using namespace std;

class ExecutionTimer{
    public:
    static void insert_full();
    static void insert_partial(int n);
    static void temp(){
	    auto start_time = std::chrono::high_resolution_clock::now();
	    BTree btree = Parser::generateBTree();
	    auto end_time = std::chrono::high_resolution_clock::now();
	    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        std::cout << "Time to insert into B tree: " << duration.count() << " microseconds" << std::endl;

	    auto start_time2 = std::chrono::high_resolution_clock::now();
	    RedBlackTree rbtree = Parser::generateRBTree();
	    auto end_time2 = std::chrono::high_resolution_clock::now();
	    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end_time2 - start_time2);
        std::cout << "Time to insert into Red Black Tree: " << duration2.count() << " microseconds" << std::endl;
        cout << endl;

        auto start_time3 = std::chrono::high_resolution_clock::now();
        btree.search(10);
        btree.search(10000);
        auto end_time3 = std::chrono::high_resolution_clock::now();
        auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(end_time3 - start_time3);
        std::cout << "Time to search for a B tree: " << duration3.count() << " microseconds" << std::endl;
        cout << endl;

        auto start_time4 = std::chrono::high_resolution_clock::now();
        rbtree.search(10);
        rbtree.search(10000);
        auto end_time4 = std::chrono::high_resolution_clock::now();
        auto duration4 = std::chrono::duration_cast<std::chrono::microseconds>(end_time4 - start_time4);
        std::cout << "Time to search for a Red Black tree: " << duration4.count() << " microseconds" << std::endl;
        cout << endl;

        auto start_time5 = std::chrono::high_resolution_clock::now();
        btree.inorder();
        auto end_time5 = std::chrono::high_resolution_clock::now();
        auto duration5 = std::chrono::duration_cast<std::chrono::microseconds>(end_time5 - start_time5);
        std::cout << "Time for inorder Traversal in a B tree: " << duration5.count() << " microseconds" << std::endl;

        auto start_time6 = std::chrono::high_resolution_clock::now();
        rbtree.inorder();
        auto end_time6 = std::chrono::high_resolution_clock::now();
        auto duration6 = std::chrono::duration_cast<std::chrono::microseconds>(end_time6 - start_time6);
        std::cout << "Time for inorder Traversal in a Red Black tree: " << duration6.count() << " microseconds" << std::endl;
    }
};

void ExecutionTimer::insert_full(){

}
void ExecutionTimer::insert_partial(int n){
    
}