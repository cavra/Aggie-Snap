#include "../std_lib_facilities_4.h"
#include "Filtered_image_window.h"
#include "../database.h"
#include "../images.h"

extern int k;
extern vector<string> filtered_images_vector;

using namespace Graph_lib;

//------------------------------------------------------------------------------

//define the window and its objects
Filtered_image_window::Filtered_image_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),

    next_button     (Point(x_max()-100,y_max()/5), 100, (y_max()/5)*4, "Next", cb_next),
    previous_button (Point(0,0), 100, y_max(), "Previous", cb_previous),
    quit_button     (Point((x_max()-100),0), 100, y_max()/5, "Quit", cb_quit),

    picture(Point(100,20), filtered_images_vector[k]),
    tagz{Point{100,15}, "Filename: "+filtered_images_vector[k]+"; Tags: "+get_tags(filtered_images_vector[k])},
    rec(Point{100,0}, 500, 500),

//attach the objects
button_pushed(false)
{
    picture.set_mask(Point{0,0},500,480);
    tagz.set_color(Color::white);
    rec.set_fill_color(Color::black);

    attach(rec);
    attach(picture);
    attach(next_button);
    attach(previous_button);
    attach(quit_button);
    attach(tagz);
}

//------------------------------------------------------------------------------

//wait_for_button() function, taken from Simple_window.cpp
bool Filtered_image_window::wait_for_button()
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

//callback function for next button
void Filtered_image_window::cb_next(Address, Address pw)
{
    reference_to<Filtered_image_window>(pw).next();    
}

//------------------------------------------------------------------------------

//callback function for previous button
void Filtered_image_window::cb_previous(Address, Address pw)
{
    reference_to<Filtered_image_window>(pw).previous();
}

//------------------------------------------------------------------------------

//callback function for quit button
void Filtered_image_window::cb_quit(Address, Address pw)
{
    reference_to<Filtered_image_window>(pw).quit();
}

//------------------------------------------------------------------------------

//next function, increase index of filtered database vector and draw the image
void Filtered_image_window::next()
{
    button_pushed = true;
    increase_filtered_index(); //increase value of k
    
    //create the objects
    Rectangle rec1(Point{100,0}, 500, 500);
    rec1.set_fill_color(Color::black);
    Image pic{Point{100,20}, filtered_images_vector[k]}; //create image using functions from database.cpp
    //create the tags using functions from database.cpp
    Text tags(Point(100,15), "Tags: "+get_tags(filtered_images_vector[k]));
    tags.set_color(Color::white); //make tags white (black background)
    
    //attach everything
    detach(picture); //remove picture attached by main window
    attach(rec1); //attach background before everything else
    attach(pic);
    attach(tags);
    redraw(); //refresh the window
    wait_for_button();
}

//------------------------------------------------------------------------------

//previous function, increase index of filtered database vector and draw the image
void Filtered_image_window::previous()
{
    button_pushed = true;
    decrease_filtered_index(); //decrease value of k
    
    //create the objects
    Rectangle rec1(Point{100,0}, 500, 500);
    rec1.set_fill_color(Color::black);
    Image pic{Point{100,20}, filtered_images_vector[k]}; //create image using functions from database.cpp
    pic.set_mask(Point{0,0},500,480);
    //create the tags using functions from database.cpp
    Text tags(Point(100,15), "Tags: "+get_tags(filtered_images_vector[k]));
    tags.set_color(Color::white); //make tags white (black background)
    
    //attach everything
    detach(picture); //remove picture attached by main window
    attach(rec1); //attach background before everything else
    attach(pic);
    attach(tags);
    redraw(); //refresh the window
    wait_for_button();
}

//------------------------------------------------------------------------------

//quit function, close the window
void Filtered_image_window::quit()
{
    hide();
    button_pushed = true;
}
