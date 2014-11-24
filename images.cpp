#include "std_lib_facilities_4.h"
#include "fltk/Menu_window.h"
#include "fltk/Graph.h"
#include "fltk/GUI.h"
#include "input.h"

vector<string> images_vector;

void get_images(){
    ifstream ist{ "picture_list.txt" };
    if (!ist) error("Cant open input file", "picture_list.txt");
    string x;
    while (getline(ist, x)){
        images_vector.push_back(x);
    }
}
