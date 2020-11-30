/*
 Грамматика

Выражение
Терм
Выражение + Терм
        Выражение - Терм
              Терм
                  Первичное выражение
                      Терм * Первичное выражение
                          Терм / Первичное выражение
              Терм !
          Первичное выражение
              Число
          ( Выражение )
    - Первичное выражение
    + Первичное выражение
              Корень из первичного выражения
                  Первичное выражение в степени
                      Число
                          Литерал с плавающей точкой


                              */

#include "logic.h"
#include <fstream>
#include "token.h"
#include<cmath>
#include <std_lib_facilities.h>

#include<iostream>
using namespace std;

ofstream fout{"ans.txt"};

void helpF()
{
    fout <<  "This is the calculator \n"
         <<  "You can calculate almost everything using this application \n"
         <<  "you can use : \n"
         <<  "1) divide , multiply , plus , minus\n2) factorial, module, square root , power \n"
         <<  "if you have any claims write me on my vk: \n"
         <<  "Pesotskaia Alisa" << endl;
}

double expression();
double powerr();
double primary()
{
    Token t = ts.get();
    switch (t.kind)
    {
    case '|':
    {
        double d = expression();
        t = ts.get();
        if (t.kind!='|'){
            ts.putback(t);
            error("| expected");
        }
        ts.putback(t);
        return abs(d);
    }

    case '(':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')'){
            ts.putback(t);
            error("')' Expected");
        }
        return d;
    }

    case '-':{
        return -primary();
    }

    case '+':{
        return +primary();
    }

    case poww:{
        return powerr();
    }

    case number:{
        Token t2 = ts.get();
        if (t2.kind == number){
            ts.putback(t);
            error("operator expected");
        }
        ts.putback(t2);
        return t.value;
    }

    case sqrtt: {
        double d = primary();
        if (d < 0){
            ts.putback(t);
            error("error: sqrt from negative");
        }
        return sqrt(d);
    }

    default:
        ts.putback(t);
        error("primary expected");
    }
}

double term()
{
    double left = primary();

    while (true)
    {
        Token t = ts.get();

        switch (t.kind)
        {
        case '*':
            left *= primary();
            break;

        case fact: {
            left = int(left);

            if (left < 0)
            {
                ts.putback(t);
                error("error: factorial from negative");

            } else if (left == 0)
            {
                left = 1;

            } else

                for (int i = left - 1; i > 0; --i)
                {
                    left *= i;
                }

            break;
        }

        case '/': {
            double d = primary();
            if (d == 0)
                error("divide by zero");
            left /= d;
            break;
        }

        default:
            ts.putback(t);
            return left;
        }
    }
}

double expression()
{
    double left = term();
    while (true)
    {
        Token t = ts.get();

        switch (t.kind)
        {
        case '+':
            left += term();
            break;

        case '-':
            left -= term();
            break;

        default:
            ts.putback(t);
            return left;
        }
    }
}

double powerr()
{
    Token t = ts.get();

    if (t.kind != '(')
    {
        ts.putback(t);
        error("error: '(' expected");
    }

    double d = expression();

    t = ts.get();
    if (t.kind != ',')
    {
        ts.putback(t);
        error("error: pow(x,i) expected ");
    }
    double i = expression();
    if (i != int(i))
    {
        ts.putback(t);
        error("error: pow(double,INT) expected");
    }
    if ((ts.get()).kind != ')')
    {
        ts.putback(t);
        error("error: ')' expected");
    }
    return pow(d, i);
}


double declaration()
{
    /*Token t = ts.get();
    if (t.kind != name)
        error("name expected in declaration");

    string var = t.name;
    if (is_declared(var))
        error(var, " declared twice");

    t = ts.get();
    if (t.kind != '=')
        error("'=' missing in declaration of ", var);

    return define_name(var, expression());
    */
        return 0;
}

double statement()
{
    Token t = ts.get();
    switch (t.kind)
    {

    case let:
        return declaration();
        break;

    default:
        ts.putback(t);
        return expression();
    }
}

void clean_up_mess(const char & ch)
{
    ts.ignore(ch);
}

void calculate()
{
    bool is_number = false;
    bool is_prompt = true;

    while (true)
        try
        {
            if(is_prompt)
                fout << prompt;
            is_prompt = false;

            Token t = ts.get();

         //  std::cout<<t.kind<<" "<<std::end;
            if (t.kind==help){
                helpF();
                is_prompt = true;
                clean_up_mess(print);
                continue;
            }

            if (t.kind == print){
                is_prompt=true;
                continue;
            }

            if (t.kind == quit)
                break;

            if (t.kind == number)
                is_number =true;
            else
                is_number =false;

            while (t.kind == pnc)
            {

                is_prompt == false;

                t = ts.get();

                if (t.kind == print){
                    is_prompt=true;

                    break;
                }
            }

            if (t.kind==print)
            {
                is_prompt = true;
                continue;
            }

            ts.putback(t);

            double res = statement();
            fout << result << res << endl;
            break;


        } catch (runtime_error &e)
        {
            cerr << e.what() << endl;
            is_prompt = true;
            clean_up_mess(print);
            continue;
        }
}
