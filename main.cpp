#include "Polish.h"

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

//Function to aid in the user Input --> returns false when input isnt an integer
bool deciferInput(char input) {
	if (isdigit(input) == false) {
		return false;
	}
  return true;
}

int main() {

	//Set up input
	string userInput;
	getline(cin,userInput);
    int error =1;

	//Check validity of Input --> if not valid cast error message and terminate program 
	if (userInput.length() == 0 || userInput.length() == 1) {
		cout << "Error" << endl;
		return 0;
	}

	if (userInput.at(0) != '+' && userInput.at(0) != '-' && userInput.at(0) != '*' && userInput.at(0) != '/' ) {
		cout << "Error" << endl;
		return 0;
	} 

	//Execute object
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



