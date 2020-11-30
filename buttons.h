#ifndef BUTTONS_H
#define BUTTONS_H

#include "../Graph_lib/Graph.h"
#include "../Graph_lib/Simple_window.h"
#include<string>

enum class Element{

    digit_0 = 0, digit_1, digit_2, digit_3, digit_4, digit_5, digit_6, digit_7, digit_8, digit_9,
    open_bracket, close_bracket, dot,
    op_add, op_subtract, op_multiply, op_divide, op_factorial, op_power, op_sqrt,
    result, help , quit
};


void start();


class Buttons : public Graph_lib ::Button
{
public:
    Buttons(Graph_lib::Point xy, Graph_lib::Callback cb, const std::string& name);

    static constexpr int size_h = 80;
    static constexpr int size_w = 80;

    std::string value() const { return val; }

private:
    std::string val;
    //Element elem;
};

#endif // BUTTONS_H
