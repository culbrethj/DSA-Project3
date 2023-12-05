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
				ExecutionTimer::insert();
				break;
			case 2:
				int n;
				cout << "Number of records: ";
				cin >> n;
				ExecutionTimer::search(n);
				break;
			case 3:
				ExecutionTimer::traverse();
				break;
			case 4:
				while(inner_selection != 3){
					cout << "Applications in Data analytics\n1. Top 5 Hotspots\n2. ()\nSelection: " << endl;
					cin >> inner_selection;
					switch(inner_selection){
						case 1:
							ExecutionTimer::top5Locations();
							break;
						case 2:

							break;
						default:
							break;
					}
				}
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