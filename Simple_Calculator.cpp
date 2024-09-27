#include <iostream>

int main () {
    char OP;
    double number1;
    double number2;
    double result;

    std::cout<<"*****CALCULATOR*****\n";
    std::cout<<"Enter either (+ - * /)\n";

    std::cout<<"Enter first number: ";
    std::cin>>number1;
    
    std::cout<<"Enter second number: ";
    std::cin>>number2;

    std::cout<<"Enter the type of operation: ";
    std::cin>>OP;
    
    switch(OP){
        case '+':
        result = number1 + number2;
        std::cout<<result;
        break;

        case '-':
        result = number1 - number2;
        std::cout<<result;
        break;

        case '*':
        result = number1 * number2;
        std::cout<<result;
        break;
        
        case '/':
        result = number1 / number2;
        std::cout<<result;
        break;


    }

    
    return 0;


}