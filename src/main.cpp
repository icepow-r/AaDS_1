#include <iostream>
#include <string>

#include "ShuntingYard.h"

int main()
{
    std::cout << "Shunting Yard Algorithm\n";
 

    std::string input;
    std::cout << "Enter the sequence (or 'exit' to quit): ";

    while (std::getline(std::cin, input))
    {
        if (input == "exit")
        {
            break;
        }

        if (input.empty())
        {
            std::cout << "Enter the sequence (or 'exit' to quit): ";
            continue;
        }

        ShuntingYard converter;
        DynamicArray<std::string> postfix = converter.infixToPostfix(input);

        std::cout << "Reverse Polish Notation: ";
        for (size_t i = 0; i < postfix.size(); i++)
        {
            std::cout << postfix[i];
            if (i < postfix.size() - 1)
            {
                std::cout << " ";
            }
        }
        std::cout << "\n\n";

        std::cout << "Enter the sequence (or 'exit' to quit): ";
    }

    return 0;
}
