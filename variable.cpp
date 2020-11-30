#include "variable.h"
#include "logic.h"
#include<vector>
#include<fstream>

#include"token.h"
#include<vector>

#include"std_lib_facilities.h"

vector<New_Var> var_table;

double get_value(string s)
{
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == s)
            return var_table[i].value;
    error("get: undefined name ");
}

void set_value(string s, double d)
{
    for (int i = 0; i <= var_table.size(); ++i)
    {
        if (var_table[i].name == s)
        {
            var_table[i].value = d;
            return;
        }
    }
    clean_up_mess('\n');
}

bool is_declared(string s)
{
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == s)
            return true;
    return false;
}

double define_name(string var, double val)
{
    if (is_declared(var))
        error(var, " declared twice");
    var_table.push_back(New_Var{var, val});
    return val;
}
