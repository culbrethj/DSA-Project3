#include <iostream>
#include <fstream>
#include "ExecutionTimer.h"
using namespace std;

int main(){
	cout << "Welcome to Ernesto, Jackson, and Muhimin's final project for DSA!" << endl;
	cout << "In this project, we examine the performance of a Red Black tree versus a B tree." << endl;
	int inner_selection = -1, outer_selection = -1;
	while(outer_selection != 5){
		cout << "Select an option:\n1. Insertion tests\n2. Searching tests\n3. Traversal tests\n4. Applications in Data analytics\n5. Exit program\nSelection: ";
		cin >> outer_selection;
		switch(outer_selection){
			case 1:
				while(inner_selection != 3){
					cout << "Insertion tests\n1. Insert full dataset (9600 records)\n2. Insert partial dataset\n3. Return to main menu\nSelection: " << endl;
					cin >> inner_selection;
					switch(inner_selection){
						case 1:
							ExecutionTimer::insert_full();
							break;
						case 2:
							ExecutionTimer::insert_partial(1000);
							break;
						default:
							break;
					}
				}
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				cout << "Exiting" << endl;
				break;
			default:
				cout << "Invalid choice" << endl;
				break;
		}
	}
	return 0;
}