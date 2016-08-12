#ifndef DEL_WINDOW_GUARD
#define DEL_WINDOW_GUARD 1

#include "GUI.h"
#include "Graph.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

//Del_window will pop up when a user wants to delete a local image from the database vector
//Del_window inherits from Window from Graph_lib
struct Del_window : Graph_lib::Window {
    Del_window(Point xy, int w, int h, const string& title );
    
    bool wait_for_button();

private:
    //declare buttons and input boxes, as well as the callback functions
    Button submit_button;
    Button quit_button;
    
    In_box image_input;
    
    bool button_pushed;
    
    static void cb_submit(Address, Address);
    static void cb_quit(Address, Address);

    void submit();
    void quit();

};

//------------------------------------------------------------------------------

#endif
