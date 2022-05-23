#include "Polish.h"

Polish::Polish()
{
    count = 0;
}
int Polish::Setup(std::string polishInput){

	//Put polishInput into stack Variables
		//Operators (+ - * / ) --> operators stack variable
		//Operands ( numbers to be operated on) --> operands stack variable

	//Operators
    for (int i = 0; i < polishInput.length(); i++) {

		if (polishInput.at(i) == '+' || polishInput.at(i) == '*' || polishInput.at(i) == '-' || polishInput.at(i) == '/' ) {
			operators.push(polishInput.at(i));
		} 

		else if (isdigit(polishInput.at(i)) == true) {
			double num = polishInput.at(i) - '0';
			tempValue.push(num);

			//Check valididity -> if not valid cast error message
			for (int j = i; j < polishInput.length(); j++) {

				if (polishInput.at(j) == '-' || polishInput.at(j) == '+' || polishInput.at(j) == '*' || polishInput.at(j) == '/' ) {
					std::cout << "Error" << std::endl;
					return 0;
				}

			}
		} 
	}
	
	//Operands
	int size = tempValue.size();
	for (int i = 0; i < size; i++) {
		double num = tempValue.top();
		operands.push(num);
		tempValue.pop();
	}

	//Check is input is valid --> if not sedn error message
	if (operands.empty() || (operators.size() >= operands.size()) || ((operands.size() - 1) != operators.size() )){
		std::cout << "Error" << std::endl;
		return 0;
	}
	//return 1 to represent program is running as should
    return 1;
}
void Polish::Calculate(){

	while (operands.size() > 1) {

		count++;

		operand1 = operands.top();
		if (count == 1) {

			equation = equation + std::to_string(operand1) + " ";
		}
        
		operands.pop();
		x = operators.top();

		if ((x == '*' || '/') && count == 1) {
			equation = "(" + equation + x + " ";
		} 
		else if ((x == '*' || '/')){
			equation = equation + x + " ";
		}
		else {
			equation + x;
		}

 		operators.pop();

		operand2 = operands.top();
		if ((x == '*' || '/')  && count == 1) {
			equation = equation +  std::to_string(operand2) + ") ";
		} 
		else {
			equation = equation + std::to_string(operand2);
		}
		
 		operands.pop();

 		if (x == '+') {
 			result = operand1 + operand2;
 		} 
		else if (x == '-') {
 			result = operand1 - operand2;
 		} 
		else if (x == '*') {
 			result = operand1 * operand2;
 		} 
		else if (x == '/') {
 			result = operand1 / operand2;
 		}
 		operands.push(result);
 	}
}
int Polish::Display(){
    if (operands.size() == 1) {
 		std::cout << equation << " = " << operands.top() << std::endl;
 	} 
	else {
 		std::cout << "Error" << std::endl;
 		return 0;
 	}
    return 1; 
}
Polish::~Polish()
{
}
