#include "std_lib_facilities_4.h"
#include "fltk/Menu_window.h"
#include "fltk/Graph.h"
#include "images.h"

int main()
try {
    get_images(); //load vectors with the database from images.cpp
    
    if(H112 != 201401L) error("Error: incorrect std_lib_facilities_4.h version ", H112);
    Menu_window win_main(Point(0,0),700,600,"AggieSnap");
        
    win_main.wait_for_button();
    return 0;
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
    }
catch (...) {
    cerr << "Some exception\n";
    return 2;
}