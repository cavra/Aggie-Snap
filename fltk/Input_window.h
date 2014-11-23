#ifndef SUBMIT_WINDOW_GUARD
#define SUBMIT_WINDOW_GUARD 1

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include "../std_lib_facilities_4.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Input_window : Graph_lib::Window {
    Input_window(Point xy, int w, int h, const string& title );
    
    bool wait_for_button();

private:
    Button submit_button;
    
    In_box input;
    
    bool button_pushed;
    
    static void cb_submit(Address, Address);
    void submit();

};

//------------------------------------------------------------------------------

#endif
