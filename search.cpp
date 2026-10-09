#include <iostream>
using namespace std;

int main( ) {
	string server_word = "California";
	string user_search;
	
	cout << "google search: ";
	cin >> user_search;
	
	
	if (user_search == server_word) {
		cout << "\n [FOUND] : Opening Google Map . . . \n";
	} else {
		cout << "\n [404] : Word Not Found ! \n";
	}
	return 0;
}
