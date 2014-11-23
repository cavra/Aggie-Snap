#include "Input_window.h"
#include "../input.h"
#include "../std_lib_facilities_4.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

Input_window::Input_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),

    submit_button(Point(x_max()-70,0), 70, y_max(), "Submit   ", cb_submit),

    input{Point(45,0), x_max()-115, y_max(), "Enter:"},

    button_pushed(false)
{
    attach(submit_button);
    attach(input);
}

//------------------------------------------------------------------------------

bool Input_window::wait_for_button()
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

void Input_window::cb_submit(Address, Address pw)
{
    reference_to<Input_window>(pw).submit();
}

//------------------------------------------------------------------------------

void Input_window::submit()
{
    string str_input = input.get_string();

    button_pushed = true;
    if (Input_window::label() == "Open File") {
        open_file(str_input);
    }
    if (Input_window::label() == "Upload File") {
        open_url(str_input);
    }
    if (Input_window::label() == "Search") {
        search_tags(str_input);
    }
    hide();
}

//------------------------------------------------------------------------------
