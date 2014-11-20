
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef SIMPLE_WINDOW_GUARD
#define SIMPLE_WINDOW_GUARD 1

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Simple_window : Graph_lib::Window {
    Simple_window(Point xy, int w, int h, const string& title );

    bool wait_for_button(); // simple event loop

private:
    
    Button next_button;
    Button previous_button;
    Button search_button;
    Button upload_button;
    Button quit_button;
    
    In_box url_input;
    In_box search_input;
    
    bool button_pushed;     // implementation detail

    static void cb_next(Address, Address);
    static void cb_previous(Address, Address);
    static void cb_search(Address, Address);
    static void cb_upload(Address, Address);
    static void cb_quit(Address, Address);

    void next();
    void previous();
    void search();
    void upload();
    void quit();
};

//------------------------------------------------------------------------------

#endif // SIMPLE_WINDOW_GUARD
