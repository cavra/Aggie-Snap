#include <FL/fl_draw.H>
#include <FL/Fl_Image.H>
#include "fltk/Point.h"
#include "std_lib_facilities_4.h"

void get_images();

struct Tag_Image : Shape {
    Tag_Image(Point xy, string file_name, string tag1, string tag2, string tag3, string tag4, string tag5, Suffix::Encoding e = Suffix::none);
    ~Tag_Image() { delete p; }
    void draw_lines() const;
    void set_mask(Point xy, int ww, int hh) { w=ww; h=hh; cx=xy.x; cy=xy.y; }
    //virtual Fl_Image *copy(int W, int H);
private:
    int w,h;  // define "masking box" within image relative to position (cx,cy)
    int cx,cy;
    Fl_Image* p;
    Text fn;
    
};