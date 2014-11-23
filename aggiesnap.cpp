//AggieSnap
//CSCE 121-510/508
//Due: December, 2014

#include "std_lib_facilities_4.h"
#include "fltk/Menu_window.h"
#include "fltk/Graph.h"

int main()
try {
    if(H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ", H112);
    Menu_window win(Point(0,0),700,600,"AggieSnap");
    
    //Image menu_background {Point{100,0}, "images/menu.jpg"};
    //menu_background.set_mask(Point{0,0},600,500);
    
    //win.attach(menu_background);
        
    win.wait_for_button();
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
