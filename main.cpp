
#include <cmath>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

#include "../Graph_lib/GUI.h"
#include "../Graph_lib/Graph.h"


#include"buttons.h"
#include"grid.h"


using namespace Graph_lib;

int main()
{
    Grid chb{Point{30,30}};
    chb.wait_for_button();

}
