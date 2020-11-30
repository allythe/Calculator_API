#ifndef VARIABLE_H
#define VARIABLE_H
#include<string>
using namespace std;

struct New_Var
{
    string name;
    double value;

    New_Var(string n, double v) : name{n}, value{v} {}
};


double get_value(string s);
void set_value(string s, double d);
bool is_declared(string s);
double define_name(string var, double val);
#endif // VARIABLE_H
