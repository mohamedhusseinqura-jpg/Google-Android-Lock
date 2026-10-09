#include <iostream>
using namespace std;

int main() {
      int realPassword = 1234 ;
      int userAttempt = 1234 ;
      
      if (userAttempt == realPassword) {
      	cout << "Access Granted ! Welcome to Google Android. " << endl ;
      }
      else {
      	cout << "Access Denied ! Wrong Password. " << endl ;
      }
      
      return 0 ;	
      } 		 	
