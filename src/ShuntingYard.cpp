#include "ShuntingYard.h"

#include <sstream>

#include "Stack.h"

bool ShuntingYard::isOperator(std::string& token)
{
    return token == "+" || token == "-" || token == "*" || token == "/" || token == "^";
}

bool ShuntingYard::isFunction(std::string& token) { return token == "sin" || token == "cos"; }

int ShuntingYard::getPrecedence(std::string& op)
{
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    if (op == "^") return 3;
    return 0;
}

bool ShuntingYard::isLeftAssociative(std::string& op) { return op != "^"; }

DynamicArray<ShuntingYard::Token> ShuntingYard::tokenize(std::string& expression)
{
    DynamicArray<Token> tokens;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (token == "(")
        {
            tokens.push_back(Token(LEFT_PAREN, token));
        }
        else if (token == ")")
        {
            tokens.push_back(Token(RIGHT_PAREN, token));
        }
        else if (isFunction(token))
        {
            tokens.push_back(Token(FUNCTION, token));
        }
        else if (isOperator(token))
        {
            tokens.push_back(Token(OPERATOR, token));
        }
        else
        {
            tokens.push_back(Token(NUMBER, token));
        }
    }

    return tokens;
}

DynamicArray<std::string> ShuntingYard::infixToPostfix(std::string& expression)
{
    DynamicArray<Token> tokens = tokenize(expression);
    DynamicArray<std::string> output;
    Stack<std::string> operators;

    for (size_t i = 0; i < tokens.size(); i++)
    {
        Token token = tokens[i];

        if (token.type == NUMBER)
        {
            output.push_back(token.value);
        }
        else if (token.type == FUNCTION)
        {
            operators.push(token.value);
        }
        else if (token.type == OPERATOR)
        {
            while (!operators.empty() && operators.top() != "(")
            {
                if (isFunction(operators.top()))
                {
                    output.push_back(operators.top());
                    operators.pop();
                }
                else if (isOperator(operators.top()))
                {
                    int topPrecedence = getPrecedence(operators.top());
                    int currentPrecedence = getPrecedence(token.value);

                    if (topPrecedence > currentPrecedence ||
                        (topPrecedence == currentPrecedence && isLeftAssociative(token.value)))
                    {
                        output.push_back(operators.top());
                        operators.pop();
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            operators.push(token.value);
        }
        else if (token.type == LEFT_PAREN)
        {
            operators.push(token.value);
        }
        else if (token.type == RIGHT_PAREN)
        {
            while (!operators.empty() && operators.top() != "(")
            {
                output.push_back(operators.top());
                operators.pop();
            }
            if (!operators.empty() && operators.top() == "(")
            {
                operators.pop();
            }
            if (!operators.empty() && isFunction(operators.top()))
            {
                output.push_back(operators.top());
                operators.pop();
            }
        }
    }

    while (!operators.empty())
    {
        output.push_back(operators.top());
        operators.pop();
    }

    return output;
}
