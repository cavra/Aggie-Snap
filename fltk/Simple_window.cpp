/*
   Simple_window.cpp
   Minimally revised for C++11 features of GCC 4.6.3 or later
   Walter C. Daugherity		June 10, 2012
*/

//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"

vector<string> url_vector;
vector<string> tag_vector;

using namespace Graph_lib;

//------------------------------------------------------------------------------

Simple_window::Simple_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),

    next_button(Point(x_max()-100,0), 100, 500, "Next", cb_next),
    previous_button(Point(0,0), 100, 500, "Previous", cb_previous),
    search_button(Point(x_max()-120,540), 100, 20, "Search", cb_search),
    upload_button(Point(x_max()-120,570), 100, 20, "Upload", cb_upload),
    quit_button(Point(0,500), 100, 100, "Quit", cb_quit),

    url_input{Point(180,570), 400, 20, "Url:"},
    search_input{Point(180,540), 400, 20, "Tags:"},

button_pushed(false)
{
    attach(next_button);
    attach(previous_button);
    attach(search_button);
    attach(upload_button);
    attach(quit_button);
    
    attach(url_input);
    attach(search_input);
}

//------------------------------------------------------------------------------

bool Simple_window::wait_for_button()
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

void Simple_window::cb_next(Address, Address pw)
{
    reference_to<Simple_window>(pw).next();    
}

//------------------------------------------------------------------------------

void Simple_window::cb_previous(Address, Address pw)
{
    reference_to<Simple_window>(pw).previous();
}

//------------------------------------------------------------------------------

void Simple_window::cb_search(Address, Address pw)
{
    reference_to<Simple_window>(pw).search();
}

//------------------------------------------------------------------------------

void Simple_window::cb_upload(Address, Address pw)
{
    reference_to<Simple_window>(pw).upload();
}

//------------------------------------------------------------------------------

void Simple_window::cb_quit(Address, Address pw)
{
    reference_to<Simple_window>(pw).quit();
}

//------------------------------------------------------------------------------

void Simple_window::next()
{
    button_pushed = true;
    wait_for_button();
}

//------------------------------------------------------------------------------

void Simple_window::previous()
{
    button_pushed = true;
    wait_for_button();
}

//------------------------------------------------------------------------------

void Simple_window::search()
{
    button_pushed = true;
    string tags = search_input.get_string();

    tag_vector.push_back(tags);
    
    string filename;
    filename = "tags.txt";
    ofstream ost {filename};
    if(!ost) error("Cant open output file ", filename);
    
    for(int i=0; i<tag_vector.size(); i++){
        ost<<tag_vector[i]<<endl;
    }
    ost.close();

    wait_for_button();
}

//------------------------------------------------------------------------------

void Simple_window::upload()
{
    button_pushed = true;
    string urls = url_input.get_string();
    
    url_vector.push_back(urls);
    
    string filename;
    filename = "urls.txt";
    ofstream ost {filename};
    if(!ost) error("Cant open output file ", filename);
    
    for(int i=0; i<url_vector.size(); i++){
        ost<<url_vector[i]<<endl;
    }
    ost.close();
    
    wait_for_button();
}

//------------------------------------------------------------------------------

void Simple_window::quit()
{
    hide();
    button_pushed = true;
}
