#ifndef MENU_WINDOW_GUARD
#define MENU_WINDOW_GUARD 1

#include "GUI.h"
#include "Graph.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Menu_window : Graph_lib::Window {
    Menu_window(Point xy, int w, int h, const string& title );

    bool wait_for_button();

private:
    
    Button next_button;
    Button previous_button;
    Button open_button;
    Button upload_button;
    Button search_button;
    Button del_button;
    Button quit_button;
        
    Image picture;
    Text tagz;
    
    Rectangle rec;
    
    bool button_pushed;
    
    static void cb_next(Address, Address);
    static void cb_previous(Address, Address);
    static void cb_open(Address, Address);
    static void cb_upload(Address, Address);
    static void cb_search(Address, Address);
    static void cb_del(Address, Address);
    static void cb_quit(Address, Address);

    void next();
    void previous();
    void open();
    void upload();
    void search();
    void del();
    void quit();
};

//------------------------------------------------------------------------------

#endif