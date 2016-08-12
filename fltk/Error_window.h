#ifndef ERROR_WINDOW_GUARD
#define ERROR_WINDOW_GUARD 1

#include "GUI.h"
#include "Graph.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

//Error window will pop up whenever an error occurs
//Error_window inherits from Window from Graph_lib
struct Error_window : Graph_lib::Window {
    Error_window(Point xy, int w, int h, const string& title, const string& message);
    
    bool wait_for_button();

private:
    //declare the close button and error text, as well as the callback functions
    Button quit_button;
    
    Text error_message;
    
    bool button_pushed;
    
    static void cb_submit(Address, Address);
    static void cb_quit(Address, Address);

    void submit();
    void quit();

};

//------------------------------------------------------------------------------

#endif
