#include <iostream>
#include <sstream>
#include <fstream>
#include <set>
#include <chrono>
#include "Parser.h"
using namespace std;

//test records
Packet p1("County1", "Buyer1", "State1", "SellerCounty1", "Seller1", "SellerState1", 20, "Male", "Slave1", "Black", "2023-01-01", 1, 1, 2, 0.01, "Credit", 80, 1000);
Packet p2("County2", "Buyer2", "State2", "SellerCounty2", "Seller2", "SellerState2", 21, "Female", "Slave2", "White", "2023-01-02", 1, 2, 3, 0.01, "Cash", 90, 1200);
Packet p3("County3", "Buyer3", "State3", "SellerCounty3", "Seller3", "SellerState3", 22, "Male", "Slave3", "Brown", "2023-01-03", 2, 0, 2, 0.01, "Credit", 85, 800);
Packet p4("County1", "Buyer1", "State1", "SellerCounty1", "Seller1", "SellerState1", 23, "Male", "Slave1", "Black", "2023-01-01", 1, 0, 1, 0.01, "Credit", 80, 1000);
Packet p5("County2", "Buyer2", "State2", "SellerCounty2", "Seller2", "SellerState2", 24, "Female", "Slave2", "White", "2023-01-02", 1, 0, 1, 0.01, "Cash", 90, 1200);
Packet p6("County3", "Buyer3", "State3", "SellerCounty3", "Seller3", "SellerState3", 25, "Male", "Slave3", "Brown", "2023-01-03", 2, 1, 3, 0.01, "Credit", 85, 800);
Packet p7("County1", "Buyer1", "State1", "SellerCounty1", "Seller1", "SellerState1", 26, "Male", "Slave1", "Black", "2023-01-01", 2, 2, 4, 0.01, "Credit", 80, 1000);
Packet p8("County2", "Buyer2", "State2", "SellerCounty2", "Seller2", "SellerState2", 27, "Female", "Slave2", "White", "2023-01-02", 1, 3, 4, 0.01, "Cash", 90, 1200);
Packet p9("County3", "Buyer3", "State3", "SellerCounty3", "Seller3", "SellerState3", 28, "Male", "Slave3", "Brown", "2023-01-03", 6, 1, 7, 0.01, "Credit", 85, 800);

int main(){

	// BTree bt;
    // bt.insert(1, p1);
    // bt.insert(2, p2);
    // bt.insert(5000, p3);
    // bt.insert(9600, p4);
    // bt.insert(2000, p5);
    // bt.insert(1221, p6);
    // bt.insert(8411, p7);
    // bt.insert(6501, p8);
    // bt.insert(10, p9);

    //  bt.search(10);
	//  bt.inorder();

	//  RedBlackTree rbt;
	//  rbt.insert(1, p1);
	//  rbt.insert(2, p2);
	//  rbt.insert(5000, p3);
	//  rbt.insert(9600, p4);
	//  rbt.insert(2000, p5);
	//  rbt.insert(1221, p6);
	//  rbt.insert(8411, p7);
	//  rbt.insert(6501, p8);
	//  rbt.insert(10, p9);

	auto start_time = std::chrono::high_resolution_clock::now();
	//BTree bt2 = Parser::generateBTree();
	auto end_time = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "Time to insert into B tree: " << duration.count() << " microseconds" << std::endl;

	auto start_time2 = std::chrono::high_resolution_clock::now();
	RedBlackTree rbt2 = Parser::generateRBTree();
	auto end_time2 = std::chrono::high_resolution_clock::now();
	auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end_time2 - start_time2);
    std::cout << "Time to insert into Red Black Tree: " << duration2.count() << " microseconds" << std::endl;

	return 0;
}