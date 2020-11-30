#ifndef LOGIC_H
#define LOGIC_H

#include<string>

using namespace std;

constexpr char quit = 'q';
constexpr char print = '\n';
constexpr char number = '8';
constexpr char name = 'a';
constexpr char let = 'L';
constexpr char pnc = ';';
constexpr char fact ='!';
constexpr char sqrtt = '_';
constexpr char poww = '#';
constexpr char help = 'h';

const string helpS = "help";
const string power = "pow";
const string prompt = "> ";
const string result = "= ";
const string declkey = "let";

double define_name(string var, double val);
double get_value(string s);
double expression();
double primary();
double term();
double expression();
double declaration();
double statement();

void clean_up_mess(const char& ch);
void calculate();
void helpF();

#endif // LOGIC_H
