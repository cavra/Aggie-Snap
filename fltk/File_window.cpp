#include "File_window.h"
#include "Image_window.h"
#include "Error_window.h"
#include "../database.h"
#include "../std_lib_facilities_4.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

//define the window and its objects
File_window::File_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),

    submit_button(Point(x_max()-140,0), 70, y_max(), "Submit", cb_submit),
    quit_button(Point(x_max()-70,0), 70, y_max(), "Close", cb_quit),

    file_input{Point(100,0), x_max()-240, y_max()/2, "File: (images/)"},
    tag_input{Point(40,y_max()/2), x_max()-180, y_max()/2, "Tags:"},

//attach the objects
    button_pushed(false)
{
    attach(file_input);
    attach(tag_input);
    attach(submit_button);
    attach(quit_button);
}

//------------------------------------------------------------------------------

//wait_for_button() function, taken from Simple_window.cpp
bool File_window::wait_for_button()
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
void File_window::cb_submit(Address, Address pw)
{
    reference_to<File_window>(pw).submit();
}

//------------------------------------------------------------------------------

//callback function for quit button
void File_window::cb_quit(Address, Address pw)
{
    reference_to<File_window>(pw).quit();
}

//------------------------------------------------------------------------------

//submit function, send the inputted image name to the database in database.cpp
//and open Image_window if the image can be opened
//otherwise open Error_window
void File_window::submit()
{
    hide();
    button_pushed = true;
    string image = "images/"+file_input.get_string();
    if (open_file(file_input.get_string(), tag_input.get_string())){
        Image_window win_image(Point(200,200),500,500, file_input.get_string(), image);
        win_image.wait_for_button();
    }
    else {
        cerr<<"This image does not exist"<<endl;
        Error_window win_err(Point(200,200),300,25,"Error", "This image does not exist");
        win_err.wait_for_button();
    }
}

//------------------------------------------------------------------------------

//quit function, close the window
void File_window::quit()
{
    hide();
    button_pushed = true;
}

//------------------------------------------------------------------------------
