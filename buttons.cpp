#include "buttons.h"

using namespace Graph_lib;

Buttons::Buttons(Point xy, Callback cb, const std::string& name)
    : Button{xy, size_h, size_w, "", cb},
      val{name}
{}


