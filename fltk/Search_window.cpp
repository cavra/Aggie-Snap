#include "Search_window.h"
#include "Error_window.h"
#include "../database.h"
#include "../images.h"
#include "../std_lib_facilities_4.h"
#include "Filtered_image_window.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

//define the window and its objects
Search_window::Search_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),

    submit_button(Point(x_max()-140,0), 70, y_max(), "Submit", cb_submit),
    quit_button(Point(x_max()-70,0), 70, y_max(), "Close", cb_quit),

    tag_input   {Point(110,0), x_max()-250, y_max(), "Search by Tag:"},

//attach the objects
    button_pushed(false)
{
    attach(tag_input);
    attach(submit_button);
    attach(quit_button);
}

//------------------------------------------------------------------------------

//wait_for_button() function, taken from Simple_window.cpp
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

//callback function for submit button
void Search_window::cb_submit(Address, Address pw)
{
    reference_to<Search_window>(pw).submit();
}

//------------------------------------------------------------------------------

//callback function for quit button
void Search_window::cb_quit(Address, Address pw)
{
    reference_to<Search_window>(pw).quit();
}

//------------------------------------------------------------------------------

//submit function, send the inputted tag to the database in database.cpp
//and open Filtered_image_window if the tag finds any images
//otherwise open Error_window
void Search_window::submit()
{
    hide();
    button_pushed = true;
    search_tags(tag_input.get_string());
    get_filtered_images();
    extern vector<string> found_vector;
    if(found_vector.size() > 0){
        Filtered_image_window win_filtered(Point(200,200),700,500,"Filtered Images");
        win_filtered.wait_for_button();
    }
    else {
        cerr<<"No images found"<<endl;
        Error_window win_err(Point(200,200),250,25,"Error", "No images found");
        win_err.wait_for_button();
    }
}

//------------------------------------------------------------------------------

//quit function, close the window
void Search_window::quit()
{
    hide();
    button_pushed = true;
}

//------------------------------------------------------------------------------
