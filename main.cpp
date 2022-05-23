#include "Polish.h"

#include <stack>
#include <iostream>
#include <stdio.h>
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

	// the prefix input as a string 
	string prefix;
	getline(cin,prefix);
	char result;
	
	// find the length of the string
	int length = prefix.length();

	if (length == 0 || length == 1) {
		cout << "Error" << endl;
		return 0;
	}

	if (prefix.at(0) != '+' && prefix.at(0) != '-' && prefix.at(0) != '*' && prefix.at(0) != '/' ) {
		cout << "Error" << endl;
		return 0;
	} 

	// create the stack
	stack <double> tempValue;
	stack <double> operands;
	stack <char> operators;

	// coverting the string prefix to the stack
	// all the numbers will go in the operand stack
	// all the operators will go in the operators stack
	for (int i = 0; i < length; i++) {
		if (prefix.at(i) == '+' || prefix.at(i) == '-' || prefix.at(i) == '*' || prefix.at(i) == '/' ) {
			operators.push(prefix.at(i));
		} else if (deciferInput(prefix.at(i)) == true) {
			double num = prefix.at(i) - '0';
			tempValue.push(num);
			for (int j = i; j < length; j++) {
				if (prefix.at(j) == '+' || prefix.at(j) == '-' || prefix.at(j) == '*' || prefix.at(j) == '/' ) {
					cout << "Error" << endl;
					return 0;
				}
			}
		} 
	}
	

	int operandsSize = tempValue.size();

	for (int i = 0; i < operandsSize; i++) {
		double num = tempValue.top();
		operands.push(num);
		tempValue.pop();
	}

	// check to see if the input is working 
	if (operands.empty() || (operators.size() >= operands.size()) || (operands.size()  -1 != operators.size() )){
		cout << "Error" << endl;
		return 0;
	}

 	char op;
 	int num1;
 	int num2;
 	string formula;
 	int counter = 0;

 	//convert to infix and find the result
	while (operands.size() > 1) {
		counter++;

		num1 = operands.top();
		if (counter == 1) {
			formula = formula + to_string(num1) + " ";
		}
		operands.pop();

		op = operators.top();
		if ((op == '*' || '/') && counter == 1) {
			formula = "(" + formula + op + " ";
		} else if ((op == '*' || '/')){
			formula = formula + op + " ";
		}else {
			formula + op;
		}
 		operators.pop();

		num2 = operands.top();
		if ((op == '*' || '/')  && counter == 1) {
			formula = formula +  to_string(num2) + ") ";
		} else {
			formula = formula + to_string(num2);
		}
		
 		operands.pop();

 		if (op == '+') {
 			result = num1 + num2;
 		} else if (op == '-') {
 			result = num1 - num2;
 		} else if (op == '*') {
 			result = num1 * num2;
 		} else if (op == '/') {
 			result = num1 / num2;
 		}
 		operands.push(result);
 	}

 	if (operands.size() == 1) {
 		cout << formula << " = " << operands.top() << endl;
 	} else {
 		cout << "Error" << endl;
 		return 0;
 	}


}



