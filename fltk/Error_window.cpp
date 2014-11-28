#include "Error_window.h"
#include "../database.h"
#include "../std_lib_facilities_4.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

Error_window::Error_window(Point xy, int w, int h, const string& title, const string& message) :
    Window(xy,w,h,title),

    quit_button(Point(x_max()-70,0), 70, y_max(), "Close", cb_quit),
    error_message{Point{10,15}, "Error: "+message},

button_pushed(false)
{
    attach(error_message);
    attach(quit_button);
}

//------------------------------------------------------------------------------

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

void Error_window::cb_quit(Address, Address pw)
{
    reference_to<Error_window>(pw).quit();
}

//------------------------------------------------------------------------------

void Error_window::quit()
{
    hide();
    button_pushed = true;
}

//------------------------------------------------------------------------------
