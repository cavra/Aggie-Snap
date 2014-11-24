#include "std_lib_facilities_4.h"
#include "fltk/Menu_window.h"
#include "fltk/Graph.h"
#include "fltk/GUI.h"
#include "input.h"
#include "images.h"

void open_file(string input, string tags){
    vector<string> pic_names;

    string file_name = "images/"+input;
    string tag1, tag2, tag3, tag4, tag5;
    
    ifstream ist{ "picture_list.txt" };
    if (!ist) error("Cant open input file", "picture_list.txt");
    string x;
    while (getline(ist, x)){
        pic_names.push_back(x);
    }
    ist.close();

    pic_names.push_back(file_name);
    
    ofstream ost{"picture_list.txt"};
    if(!ost) error("Cant open output file", "picture_list.txt");
    for(int i=0; i<pic_names.size(); i++){
        ost<<pic_names[i]<<endl;
    }
    ost.close();

    pic_names.erase(pic_names.begin());
    
    apply_tags(file_name, tags);
}

void open_url(string url, string tags, string name){
    vector<string> vec;
    string file_name = "images/"+name;
   
    system((string("wget ")+ url +" -O "+file_name).c_str());
    
    ifstream ist{ "picture_list.txt" };
    if (!ist) error("Cant open input file", "picture_list.txt");
    string x;
    while (getline(ist, x)){
        vec.push_back(x);
    }
    ist.close();
    
    vec.push_back(file_name);
    
    ofstream ost {"picture_list.txt"};
    if(!ost) error("Cant open output file", "picture_list.txt");
    for(int i=0; i<vec.size(); i++){
        ost<<vec[i]<<endl;
    }
    ost.close();
    
    vec.erase(vec.begin());
    
    apply_tags(file_name, tags);
}

void apply_tags(string file_name, string tags){
    vector<string> tag_vector;
    vector<string> file_vector;
    tag_vector.push_back(tags);
    
    ifstream ist{ "picture_list.txt" };
    if (!ist) error("Cant open input file", "picture_list.txt");
    string x;
    while (getline(ist, x)){
        if(x == file_name){
            ofstream ost {"picture_list.txt"};
            if(!ost) error("Cant open output file", "picture_list.txt");
            for(int i=0; i<tag_vector.size(); i++){
                ost<<x<<' ';
                ost<<tag_vector[i]<<endl;
            }
            ost.close();
        }
        else file_vector.push_back(x);
    }
    ist.close();
    
    tag_vector.erase(tag_vector.begin());
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

int j = 0;
int increase_index(){
    j = j+1;
    return j;
}

int decrease_index(){
    j = j-1;
    return j;
}
