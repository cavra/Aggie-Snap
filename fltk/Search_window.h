#ifndef SEARCH_WINDOW_GUARD
#define SEARCH_WINDOW_GUARD 1

#include "GUI.h"
#include "Graph.h"
#include "../std_lib_facilities_4.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Search_window : Graph_lib::Window {
    Search_window(Point xy, int w, int h, const string& title );
    
    bool wait_for_button();

private:
    Button submit_button;
    Button quit_button;
    
    In_box tag_input;
    
    bool button_pushed;
    
    static void cb_submit(Address, Address);
    static void cb_quit(Address, Address);

    void submit();
    void quit();

};

//------------------------------------------------------------------------------

#endif
