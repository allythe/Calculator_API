#ifndef TOKEN_H
#define TOKEN_H

#include"logic.h"
#include<string>
using namespace std;

struct Token
{
    char kind;
    double value;
    string name;

    Token(char ch) : kind{ch}, value{0} {}
    Token(char ch, string s) : kind{ch}, name{s} {}
    Token(char ch, double val) : kind{ch}, value{val} {}
};

class Token_stream
{
    Token buffer{'\0'};
    bool full{false};
public:

    Token_stream() {}
    Token get();
    void putback(Token t);
    void ignore(char);
};

extern Token_stream ts;

Token get();

void putback(Token t);
void ignore(char c);

#endif // TOKEN_H
