#ifndef SEARCH_WINDOW_GUARD
#define SEARCH_WINDOW_GUARD 1

#include "GUI.h"
#include "Graph.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

//Search_window will pop up when a user wants to search for an image via tag
//Search_window inherits from Window from Graph_lib
struct Search_window : Graph_lib::Window {
    Search_window(Point xy, int w, int h, const string& title );
    
    bool wait_for_button();

private:
    //declare buttons and the input box, as well as the callback functions
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
