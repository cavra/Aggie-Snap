#include "Image_window.h"
#include "Graph.h"
#include "../database.h"
#include "../images.h"
#include "../std_lib_facilities_4.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

Image_window::Image_window(Point xy, int w, int h, const string& title, const string& file_name) :
    Window(xy,w,h,title),

    quit_button(Point(x_max()-70,0), 70, 20, "Close", cb_quit),

    picture(Point(0,20), file_name),
    tagz(Point(0,15), "Tags: "+get_tags(file_name)),

    button_pushed(false)
{
    picture.set_mask(Point{0,0},x_max(),y_max());
    attach(quit_button);
    attach(picture);
    attach(tagz);
}

//------------------------------------------------------------------------------

bool Image_window::wait_for_button()
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

void Image_window::cb_quit(Address, Address pw)
{
    reference_to<Image_window>(pw).quit();
}

//------------------------------------------------------------------------------

void Image_window::quit()
{
    hide();
    button_pushed = true;
}

//------------------------------------------------------------------------------
