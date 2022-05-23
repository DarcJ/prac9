#include <stack>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>


class Polish
{
private:
    std::stack <char> operators;
    std::stack <double> operands;
    std::stack <double> tempValue;
 	int operand1;
 	int operand2;
    char x;
    std::string equation;
    char result;
 	int count;
public:
    Polish();
    int Setup(std::string polishInput);
    void Calculate();
    int Display();
    ~Polish();
};
