#include <iostream>
#include <sstream>
#include <fstream>
#include "Parser.h"
using namespace std;

//test records
Packet p1("County1", "Buyer1", "State1", "SellerCounty1", "Seller1", "SellerState1", 20, "Male", "Slave1", "Black", "2023-01-01", 1, 1, 2, 0.01, "Credit", 80, 1000);
Packet p2("County2", "Buyer2", "State2", "SellerCounty2", "Seller2", "SellerState2", 25, "Female", "Slave2", "White", "2023-01-02", 1, 2, 3, 0.01, "Cash", 90, 1200);
Packet p3("County3", "Buyer3", "State3", "SellerCounty3", "Seller3", "SellerState3", 22, "Male", "Slave3", "Brown", "2023-01-03", 2, 0, 2, 0.01, "Credit", 85, 800);
Packet p4("County1", "Buyer1", "State1", "SellerCounty1", "Seller1", "SellerState1", 20, "Male", "Slave1", "Black", "2023-01-01", 1, 0, 1, 0.01, "Credit", 80, 1000);
Packet p5("County2", "Buyer2", "State2", "SellerCounty2", "Seller2", "SellerState2", 25, "Female", "Slave2", "White", "2023-01-02", 1, 0, 1, 0.01, "Cash", 90, 1200);
Packet p6("County3", "Buyer3", "State3", "SellerCounty3", "Seller3", "SellerState3", 22, "Male", "Slave3", "Brown", "2023-01-03", 2, 1, 3, 0.01, "Credit", 85, 800);
Packet p7("County1", "Buyer1", "State1", "SellerCounty1", "Seller1", "SellerState1", 20, "Male", "Slave1", "Black", "2023-01-01", 2, 2, 4, 0.01, "Credit", 80, 1000);
Packet p8("County2", "Buyer2", "State2", "SellerCounty2", "Seller2", "SellerState2", 25, "Female", "Slave2", "White", "2023-01-02", 1, 3, 4, 0.01, "Cash", 90, 1200);
Packet p9("County3", "Buyer3", "State3", "SellerCounty3", "Seller3", "SellerState3", 22, "Male", "Slave3", "Brown", "2023-01-03", 6, 1, 7, 0.01, "Credit", 85, 800);

int main(){

	BTree bt;
	bt.insert(1, p1);
	bt.insert(2, p2);
	bt.insert(5000, p3);
	bt.insert(9600, p4);
	bt.insert(2000, p5);
	bt.insert(1221, p6);
	bt.insert(8411, p7);
	bt.insert(6501, p8);
	bt.insert(10, p9);

	bt.inorder();



/*
	fstream data_in;
	data_in.open("../input/slavery_ids.csv", ios::in);
	string input;
	while(data_in >> input){
		getline(data_in, input);
		cout << input << endl;
	}
	return 0;
	*/
}