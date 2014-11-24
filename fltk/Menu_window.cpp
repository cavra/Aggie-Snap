/*
   Simple_window.cpp
   Minimally revised for C++11 features of GCC 4.6.3 or later
   Walter C. Daugherity		June 10, 2012
*/

//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "../std_lib_facilities_4.h"
#include "Menu_window.h"
#include "File_window.h"
#include "URL_window.h"
#include "Search_window.h"
#include "../input.h"
#include "../images.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

Menu_window::Menu_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),

    next_button     (Point(x_max()-100,0), 100, (y_max()/6)*5, "Next", cb_next),
    previous_button (Point(0,0), 100, (y_max()/6)*5, "Previous", cb_previous),

    open_button     (Point((x_max()/4)*0,y_max()-100), (x_max()/4)*1, y_max()/6, "Open File", cb_open),
    upload_button   (Point((x_max()/4)*1,y_max()-100), (x_max()/4)*1, y_max()/6, "Upload File", cb_upload),
    search_button   (Point((x_max()/4)*2,y_max()-100), (x_max()/4)*1, y_max()/6, "Search by Tags", cb_search),
    quit_button     (Point((x_max()/4)*3,y_max()-100), (x_max()/4)*1, y_max()/6, "Quit", cb_quit),

button_pushed(false)
{
    attach(next_button);
    attach(previous_button);
    attach(open_button);
    attach(upload_button);
    attach(search_button);
    attach(quit_button);
}

//------------------------------------------------------------------------------

bool Menu_window::wait_for_button()
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

void Menu_window::cb_next(Address, Address pw)
{
    reference_to<Menu_window>(pw).next();    
}

//------------------------------------------------------------------------------

void Menu_window::cb_previous(Address, Address pw)
{
    reference_to<Menu_window>(pw).previous();
}

//------------------------------------------------------------------------------

void Menu_window::cb_open(Address, Address pw)
{
    reference_to<Menu_window>(pw).open();
}

//------------------------------------------------------------------------------

void Menu_window::cb_upload(Address, Address pw)
{
    reference_to<Menu_window>(pw).upload();
}

//------------------------------------------------------------------------------

void Menu_window::cb_search(Address, Address pw)
{
    reference_to<Menu_window>(pw).search();
}

//------------------------------------------------------------------------------

void Menu_window::cb_quit(Address, Address pw)
{
    reference_to<Menu_window>(pw).quit();
}

//------------------------------------------------------------------------------

void Menu_window::next()
{
    button_pushed = true;
    increase_index();
    extern int j;
    extern vector<string> images_vector;
    Image pic{Point{100,10}, images_vector[j]};
    pic.set_mask(Point{0,0},500,490);
    attach(pic);
    redraw();
    wait_for_button();
}

//------------------------------------------------------------------------------

void Menu_window::previous()
{
    button_pushed = true;
    decrease_index();
    extern int j;
    extern vector<string> images_vector;
    Image pic{Point{100,10}, images_vector[j]};
    pic.set_mask(Point{0,0},500,490);
    attach(pic);
    redraw();
    wait_for_button();
}

//------------------------------------------------------------------------------

void Menu_window::open()
{
    button_pushed = true;
    File_window win_open(Point(200,200),400,50,"Open File");
    win_open.wait_for_button();
    wait_for_button();
}

//------------------------------------------------------------------------------

void Menu_window::upload()
{
    button_pushed = true;
    URL_window win_upload(Point(200,200),400,70,"Upload File");
    win_upload.wait_for_button();
    wait_for_button();
}

//------------------------------------------------------------------------------

void Menu_window::search()
{
    button_pushed = true;
    Search_window win_search(Point(200,200),400,25,"Search");
    win_search.wait_for_button();
    wait_for_button();
}

//------------------------------------------------------------------------------


void Menu_window::quit()
{
    hide();
    button_pushed = true;
}
