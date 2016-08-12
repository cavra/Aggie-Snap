#include "Error_window.h"
#include "../database.h"
#include "../std_lib_facilities_4.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

//define the window and its objects
Error_window::Error_window(Point xy, int w, int h, const string& title, const string& message) :
    Window(xy,w,h,title),

    quit_button(Point(x_max()-70,0), 70, y_max(), "Close", cb_quit),
    error_message{Point{10,15}, "Error: "+message},

//attach the objects
button_pushed(false)
{
    attach(error_message);
    attach(quit_button);
}

//------------------------------------------------------------------------------

//wait_for_button() function, taken from Simple_window.cpp
bool Error_window::wait_for_button()
{
    show();
    button_pushed = false;
#if 1
    while (!button_pushed) Fl::wait();
    Fl::redraw();
#else
    Fl::run();
#endif
    return button_pushed;
}

//------------------------------------------------------------------------------

//callback function for quit button
void Error_window::cb_quit(Address, Address pw)
{
    reference_to<Error_window>(pw).quit();
}

//------------------------------------------------------------------------------

//quit function, close the window
void Error_window::quit()
{
    hide();
    button_pushed = true;
}

//------------------------------------------------------------------------------
