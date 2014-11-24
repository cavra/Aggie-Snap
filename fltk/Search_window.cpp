#include "Search_window.h"
#include "../input.h"
#include "../std_lib_facilities_4.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

Search_window::Search_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),

    submit_button(Point(x_max()-140,0), 70, y_max(), "Submit", cb_submit),
    quit_button(Point(x_max()-70,0), 70, y_max(), "Close", cb_quit),

    tag_input   {Point(110,0), x_max()-250, y_max(), "Search by Tag:"},

    button_pushed(false)
{
    attach(tag_input);
    attach(submit_button);
    attach(quit_button);
}

//------------------------------------------------------------------------------

bool Search_window::wait_for_button()
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

void Search_window::cb_submit(Address, Address pw)
{
    reference_to<Search_window>(pw).submit();
}

//------------------------------------------------------------------------------

void Search_window::cb_quit(Address, Address pw)
{
    reference_to<Search_window>(pw).quit();
}

//------------------------------------------------------------------------------

void Search_window::submit()
{
    button_pushed = true;

    search_tags(tag_input.get_string());
   
    wait_for_button();
}

//------------------------------------------------------------------------------

void Search_window::quit()
{
    hide();
    button_pushed = true;
}

//------------------------------------------------------------------------------
