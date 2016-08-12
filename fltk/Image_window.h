#ifndef IMAGE_WINDOW_GUARD
#define IMAGE_WINDOW_GUARD 1

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

//Image_window will pop up when a user opens/downloads an image
//Image_window inherits from Window from Graph_lib
struct Image_window : Graph_lib::Window {
    Image_window(Point xy, int w, int h, const string& title, const string& file_name);
    
    bool wait_for_button();

private:
    //declare the quit button, the image, and the text for tags, as well as the callback functions
    Button quit_button;
    
    Image picture;
    Text tagz;
    
    bool button_pushed;
    
    static void cb_quit(Address, Address);

    void quit();

};

//------------------------------------------------------------------------------

#endif
