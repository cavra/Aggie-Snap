#include "Del_window.h"
#include "../database.h"
#include "../std_lib_facilities_4.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

Del_window::Del_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),

    submit_button(Point(x_max()-140,0), 70, y_max(), "Delete", cb_submit),
    quit_button(Point(x_max()-70,0), 70, y_max(), "Close", cb_quit),

    image_input   {Point(110,0), x_max()-250, y_max(), "Image to delete:"},

    button_pushed(false)
{
    attach(image_input);
    attach(submit_button);
    attach(quit_button);
}

//------------------------------------------------------------------------------

bool Del_window::wait_for_button()
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

void Del_window::cb_submit(Address, Address pw)
{
    reference_to<Del_window>(pw).submit();
}

//------------------------------------------------------------------------------

void Del_window::cb_quit(Address, Address pw)
{
    reference_to<Del_window>(pw).quit();
}

//------------------------------------------------------------------------------

void Del_window::submit()
{
    hide();
    button_pushed = true;
    delete_image(image_input.get_string()); //call the delete_image function from database.cpp
}

//------------------------------------------------------------------------------

void Del_window::quit()
{
    hide();
    button_pushed = true;
}

//------------------------------------------------------------------------------
