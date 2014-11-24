#ifndef URL_WINDOW_GUARD
#define URL_WINDOW_GUARD 1

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include "../std_lib_facilities_4.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct URL_window : Graph_lib::Window {
    URL_window(Point xy, int w, int h, const string& title );
    
    bool wait_for_button();

private:
    Button submit_button;
    Button quit_button;
    
    In_box url_input;
    In_box name_input;
    In_box tag_input;

    bool button_pushed;
    
    static void cb_submit(Address, Address);
    static void cb_quit(Address, Address);

    void submit();
    void quit();

};

//------------------------------------------------------------------------------

#endif
