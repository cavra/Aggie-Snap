#include "URL_window.h"
#include "../input.h"
#include "../std_lib_facilities_4.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

URL_window::URL_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),

    submit_button(Point(x_max()-140,0), 70, y_max(), "Submit", cb_submit),
    quit_button(Point(x_max()-70,0), 70, y_max(), "Close", cb_quit),

    url_input   {Point(50,0), x_max()-190, y_max()/3, "URL:"},
    name_input   {Point(50,y_max()/3), x_max()-190, y_max()/3, "Name:"},
    tag_input   {Point(50,(y_max()/3)*2), x_max()-190, y_max()/3, "Tags:"},

    button_pushed(false)
{
    attach(url_input);
    attach(name_input);
    attach(tag_input);
    attach(submit_button);
    attach(quit_button);
}

//------------------------------------------------------------------------------

bool URL_window::wait_for_button()
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

void URL_window::cb_submit(Address, Address pw)
{
    reference_to<URL_window>(pw).submit();
}

//------------------------------------------------------------------------------

void URL_window::cb_quit(Address, Address pw)
{
    reference_to<URL_window>(pw).quit();
}

//------------------------------------------------------------------------------

void URL_window::submit()
{
    button_pushed = true;
    open_url(url_input.get_string(), tag_input.get_string(), name_input.get_string());
    wait_for_button();
}

//------------------------------------------------------------------------------

void URL_window::quit()
{
    hide();
    button_pushed = true;
}

//------------------------------------------------------------------------------
