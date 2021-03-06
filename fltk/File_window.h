#ifndef FILE_WINDOW_GUARD
#define FILE_WINDOW_GUARD 1

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include "../std_lib_facilities_4.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

//File_window will pop up when a user wants to open a local image file
//File_window inherits from Window from Graph_lib
struct File_window : Graph_lib::Window {
    File_window(Point xy, int w, int h, const string& title );
    
    bool wait_for_button();

private:
    //declare buttons and input boxes, as well as the callback functions
    Button submit_button;
    Button quit_button;
    
    In_box file_input;
    In_box tag_input;
    
    bool button_pushed;
    
    static void cb_submit(Address, Address);
    static void cb_quit(Address, Address);

    void submit();
    void quit();

};

//------------------------------------------------------------------------------

#endif
