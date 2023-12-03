// #include "../src/main.cpp"
#include "../src/Parser.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <Windows.h>
#include <sstream>
#include <iostream>

/*
	To check output (At the Project1 directory):
		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp && build/test
*/

TEST_CASE("Incorrect Command 1", "[flag]"){
	ostringstream oss;
    streambuf* p_cout_streambuf = cout.rdbuf();
    cout.rdbuf(oss.rdbuf());

	MyAVLTree tree;
	string command = "insert \"1nv4L1d_n4m3\" 12345678";
	string result = Parser::execute(command, tree);

	cout.rdbuf(p_cout_streambuf);


	assert(oss && oss.str() == "unsuccessful");
}

// TEST_CASE("Incorrect Command 2", "[flag]"){
// 	string command = "insert \"1nv4L1d_n4m3\" 12345678";
// }

// TEST_CASE("Incorrect Command 3", "[flag]"){
// 	string command = "insert \"1nv4L1d_n4m3\" 12345678";
// }

// TEST_CASE("Incorrect Command 4", "[flag]"){
// 	string command = "insert \"1nv4L1d_n4m3\" 12345678";
// }

// TEST_CASE("Incorrect Command 5", "[flag]"){
// 	string command = "insert \"1nv4L1d_n4m3\" 12345678";
// }

// TEST_CASE("BST RemoveInorder", "[flag]"){
// 	MyAVLTree tree;

// 	tree.insert("11111111", "Andy");
// 	tree.insert("22222222", "Bob");
// 	tree.insert("33333333", "Carla");

// 	tree.removeInOrder(2);

// 	tree.removeInOrder(1);

// 	const visualizer<int> v(tree);
// 	cout << endl << endl;
// 	v.visualize();
// 	cout << endl << endl;

// 	REQUIRE(1 == 1);
// }