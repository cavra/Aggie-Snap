#include "URL_window.h"
#include "Image_window.h"
#include "Error_window.h"
#include "../database.h"
#include "../std_lib_facilities_4.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

//define the window and its objects
URL_window::URL_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),

    submit_button(Point(x_max()-140,0), 70, y_max(), "Submit", cb_submit),
    quit_button(Point(x_max()-70,0), 70, y_max(), "Close", cb_quit),

    url_input   {Point(50,0), x_max()-190, y_max()/3, "URL:"},
    name_input   {Point(50,y_max()/3), x_max()-190, y_max()/3, "Name:"},
    tag_input   {Point(50,(y_max()/3)*2), x_max()-190, y_max()/3, "Tags:"},

//attach the objects
    button_pushed(false)
{
    attach(url_input);
    attach(name_input);
    attach(tag_input);
    attach(submit_button);
    attach(quit_button);
}

//------------------------------------------------------------------------------

//wait_for_button() function, taken from Simple_window.cpp
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

//callback function for submit button
void URL_window::cb_submit(Address, Address pw)
{
    reference_to<URL_window>(pw).submit();
}

//------------------------------------------------------------------------------

//callback function for quit button
void URL_window::cb_quit(Address, Address pw)
{
    reference_to<URL_window>(pw).quit();
}

//------------------------------------------------------------------------------

//submit function, send the entered data to the database in database.cpp
//and open Image_window if the url is valid and image exists
//otherwise open Error_window
void URL_window::submit()
{
    hide();
    button_pushed = true;
    string image = "images/"+name_input.get_string();
    if(open_url(url_input.get_string(), tag_input.get_string(), name_input.get_string())){
        Image_window win_image(Point(200,200),500,500, name_input.get_string(), image);
        win_image.wait_for_button();
    }
    else {
        cerr<<"This image does not exist or this is an invalid url"<<endl;
        Error_window win_err(Point(200,200),500,25,"Error", "This image does not exist or this is an invalid url");
        win_err.wait_for_button();
    }
}

//------------------------------------------------------------------------------

//quit function, close the window
void URL_window::quit()
{
    hide();
    button_pushed = true;
}

//------------------------------------------------------------------------------
