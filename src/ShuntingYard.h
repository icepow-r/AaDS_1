#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include <string>

#include "DynamicArray.h"

class ShuntingYard
{
   private:
    enum TokenType
    {
        NUMBER,
        OPERATOR,
        FUNCTION,
        LEFT_PAREN,
        RIGHT_PAREN
    };

    struct Token
    {
        TokenType type;
        std::string value;

        Token() : type(NUMBER), value("") {}
        Token(TokenType t, std::string& v) : type(t), value(v) {}
    };

    bool isOperator(std::string& token);
    bool isFunction(std::string& token);
    int getPrecedence(std::string& op);
    bool isLeftAssociative(std::string& op);
    DynamicArray<Token> tokenize(std::string& expression);

   public:
    DynamicArray<std::string> infixToPostfix(std::string& expression);
};

#endif
