#ifndef FILTERED_IMAGE_WINDOW_GUARD
#define FILTERED_IMAGE_WINDOW_GUARD 1

#include "GUI.h"
#include "Graph.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

//Filtered_image_window will pop up when a user wants to search via tags
//Filtered_image_window inherits from Window from Graph_lib
struct Filtered_image_window : Graph_lib::Window {
    Filtered_image_window(Point xy, int w, int h, const string& title );

    bool wait_for_button();

private:
    //declare buttons, images, text, and the background rectangle, as well as the callback functions
    Button next_button;
    Button previous_button;
    Button quit_button;
        
    Image picture;
    Text tagz;
    Rectangle rec;

    bool button_pushed;
    
    static void cb_next(Address, Address);
    static void cb_previous(Address, Address);
    static void cb_quit(Address, Address);

    void next();
    void previous();
    void quit();
};

//------------------------------------------------------------------------------

#endif