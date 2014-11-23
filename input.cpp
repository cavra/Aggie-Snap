#include "std_lib_facilities_4.h"
#include "fltk/Menu_window.h"
#include "fltk/Graph.h"
#include "fltk/GUI.h"
#include "input.h"

void open_file(string input){
    vector<string> pic_names;
    pic_names.push_back(input);
    
    ifstream ist{ "picture_list.txt" };
    if (!ist) error("Cant open input file", "picture_list.txt");
    
    string x;
    while (getline(ist, x)){
        pic_names.push_back(x);
    }
    ist.close();

    ofstream ost{"picture_list.txt"};
    if(!ost) error("Cant open output file", "picture_list.txt");
    
    for(int i=0; i<pic_names.size(); i++){
        ost<<pic_names[i]<<endl;
    }
    ost.close();

    pic_names.erase(pic_names.begin());
        
    Image i(Point(50, 50), pic_names[0]);
    Image j(Point(100, 100), pic_names[0]);
        
    Text t(Point(400, 300), pic_names[0]);
}

void open_url(string input){
    Vector_ref<string> vec;
    /*
    string URLpic(string URLstring, string filename_string){
    system((string("wget ") + filename_string + " –O " + URLstring).c_str());
    return filename_string;
    }
    */
    
    string url = input;
    
 	string file_name = "test.jpg";
    system((string("wget ")+ url +" -O "+file_name).c_str());
    Image test_img(Point(200,200),file_name);
    
    ofstream ost {"urls.txt"};
    if(!ost) error("Cant open output file", "urls.txt");
    ost<<url<<endl;
    
    //win1.attach(test_img);
    //vec.push_back(new Image(Point(200,200),file_name));
    /*  
    for(int i =0; i < vec.size(); ++i){
        win1.attach(vec[i]);
    }
    */
}

void search_tags(string input){
     vector<string> tag_vector;
     
     tag_vector.push_back(input);
    
     ofstream ost {"tags.txt"};
     if(!ost) error("Cant open output file", "tags.txt");
     
     for(int i=0; i<tag_vector.size(); i++){
     ost<<tag_vector[i]<<endl;
     }
     ost.close();
}
