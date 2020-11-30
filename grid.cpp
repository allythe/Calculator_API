#include "grid.h"
#include "buttons.h"

#include <fstream>
#include"logic.h"

ifstream fin {"expression.txt"};


char sign[]{'1', '2', '3','+','-',',', '4', '5', '6','(',')', '_', '7', '8', '9', '*', '/', 'p', 'h', '0', 'q', '!', '=','c'};

void Grid::make_btn(int i, int j, Callback cb, const std::string& name){
    my_btns.push_back(
        new Buttons{Point{margin + j * Buttons::size_w,
                          height - H_of_box - (2 * margin + (N_h - 1 - i) * Buttons::size_h)},
                    cb,
                    name });

    attach(my_btns[my_btns.size() - 1]);
}

Grid::Grid(Point xy)
    : My_window{xy, width, height, "Grid"}
    , anss{Point{x_max() - 350, 10}, 240, 40, ""}
    , qst{Point{x_max() - 460, 60}, 350, 40, ""}
    , btn_del_ans{Point{40, 10}, 100, 40, "Delete ans", cb_delete_ans}
    , btn_del_expr{Point{40, 60}, 100, 40, "Delete expr", cb_delete_expr}
    , btn_show_history{Point{150, 10}, 100, 40, "History", cb_show_history}
{
    attach(btn_show_history);
    attach(btn_del_ans);
    attach(btn_del_expr);
    attach(anss);
    attach(qst);
    size_range(width, height, width, height); //fixed window size

    make_btn(0,0, cb_expr, "1");
    make_btn(0,1, cb_expr, "2");
    make_btn(0,2, cb_expr, "3");
    make_btn(0,3, cb_expr, "+");
    make_btn(0,4, cb_expr, "-");
    make_btn(0,5, cb_expr, ",");
    make_btn(1,0, cb_expr, "4");
    make_btn(1,1, cb_expr, "5");
    make_btn(1,2, cb_expr, "6");
    make_btn(1,3, cb_expr, "(");
    make_btn(1,4, cb_expr, ")");
    make_btn(1,5, cb_expr, "_‎");
    make_btn(2,0, cb_expr, "7");
    make_btn(2,1, cb_expr, "8");
    make_btn(2,2, cb_expr, "9");
    make_btn(2,3, cb_expr, "*");
    make_btn(2,4, cb_expr, "/");
    make_btn(2,5, cb_expr, "pow");
    make_btn(3,0, cb_help, "help");
    make_btn(3,1, cb_expr, "0");
    make_btn(3,2, cb_quit, "q");
    make_btn(3,3, cb_expr, "!");
    make_btn(3,4, cb_result, "=");
    make_btn(3,5, cb_clean_ch, "c");

    for (int i = 0; i < my_btns.size(); ++i)
    {
        my_btns[i].label.push_back(sign[i]);
    }
}

std::string read_answer(const std::string& path){

    std::ifstream ifs{path}; // поток для записи
    std::string line;

    while (ifs)
    {
        ifs>>line;
    }

//cout<<" lime"<<line<<endl;
    return line;
}


Help_win::Help_win(Point xy, int w, int h, const std::string &title)
    : My_window{xy, w, h, title}
     // help_g{Point{10, 50},x_max()-20,y_max() - 60, "j"}
{

 //   text_buff = new Fl_Text_Buffer();
   // txt_edit->buffer( txt_buff );

   // std::string ans = read_answer("help.txt");
  //  attach(help_g);
   // string s = "asd  asd";


    //help_g.put(s);
    //help_g.put(s);
}






void Grid::expr(Address widget)
{
    Fl_Widget &w = reference_to<Fl_Widget>(widget);
    string name_btn = at(Point{w.x(), w.y()});
    expression += name_btn;
    qst.put(expression);
    Fl::redraw();
}


void write_expr(const std::string& path, const std::string& expr)
{
    std::ofstream foutt{path}; // поток для записи
    if (foutt)
    {
        foutt << expr << std::endl;
    }
}


void Grid::show_history(Address widget)
{
    //

}

void Grid::result(Address)
{
    write_expr("expression.txt", expression);
    cout << " in result "<<endl;
    calculate();

    std::string ans = read_answer("ans.txt");
    cout<<" ans "<<ans<<endl;

    anss.put(ans);
    Fl::redraw();

}


void Grid::clean_ch(Address)
{
    if (expression!="\0"){
    expression.pop_back();
    qst.put(expression);
    Fl::redraw();

    }
}

void Grid::quit(Address)
{
    hide();
}

void Grid::help(Address)
{
    Help_win win_h {Point{100,100}, 300, 300, "help"};

    win_h.wait_for_button();
}


string Grid::at(Point p)
{
    int i = (height - H_of_box - p.y - margin) / Buttons::size_h;
    int j = (p.x - margin) / Buttons::size_w;
    std::cout << i <<" "<< j<< " "<<(my_btns[(N_w*N_h-6)-i * N_w + j]).value()<<std::endl;

    return (my_btns[(N_w*N_h-6)-i * N_w + j]).value();
}



