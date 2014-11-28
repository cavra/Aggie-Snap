#include <FL/fl_draw.H>
#include <FL/Fl_Image.H>
#include "fltk/Point.h"
#include "std_lib_facilities_4.h"

//two main functions
void get_images();
void get_filtered_images();

//tag function called to get tags for display
string get_tags(string file_name);

//all sub-functions of get_tags()
void get_current_line(string file_name);
void line_to_string();
void find_tags();
string tags_to_string(); //returns string to get_tags() to be returned to original caller