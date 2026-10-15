#include <iostream>
using namespace std;
int main() {
	int number;
	cout << "Enter an integer number: ";
	cin >> number;
	
	
	if (number % 2==0) {
		cout << number << "is an Even number ." << endl;
	} else {
		cout << number << "is an Odd number ." << endl;
	}
	
	return 0;
}
