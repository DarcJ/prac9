#include "Polish.h"

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

//this function will test whether the input is a digit or string
bool deciferInput(char input) {
	if (isdigit(input) == false) {
		return false;
	}
  return true;
}

int main() {

	
	string userInput;
	getline(cin,userInput);
    int error =1;


	if (userInput.length() == 0 || userInput.length() == 1) {
		cout << "Error" << endl;
		return 0;
	}

	if (userInput.at(0) != '+' && userInput.at(0) != '-' && userInput.at(0) != '*' && userInput.at(0) != '/' ) {
		cout << "Error" << endl;
		return 0;
	} 

	Polish P;
    error = P.Setup(userInput);
    if (error == 0)
    {
        return 0;
    }
    P.Calculate();
    error = P.Display();
    if (error == 0)
    {
        return 0;
    }
    

}



