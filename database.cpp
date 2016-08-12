#include "std_lib_facilities_4.h"
#include "fltk/Menu_window.h"
#include "fltk/Error_window.h"
#include "fltk/Graph.h"
#include "fltk/GUI.h"
#include "database.h"
#include "images.h"

//define the vectors here, to be used across all functions
vector<string> lines_vector;
vector<string> tags_vector;
vector<string> found_vector;

//------------------------------------------------------------------------------

bool open_file(string input, string tags){
    //edit the user inputted filename to be placed in the image file
    string file_name = "images/"+input;
    
    //check if image is good
    if(can_open(file_name)){
        separate_tags(tags);
        copy_contents();
        write_to_database(file_name);
        get_images(); //from images.cpp
        return true;
    }
    else {
        cerr<<"Cannot open image"<<endl;
        return false;
    }
}

//------------------------------------------------------------------------------

bool open_url(string url, string tags, string name){
    //edit the user inputted filename to be placed in the image file
    string file_name = "images/"+name;
   
    //get image from url
    system((string("wget ")+ url +" -O "+file_name).c_str());

    //check if image is good
    if(can_open(file_name)){
        separate_tags(tags);
        copy_contents();
        write_to_database(file_name);
        get_images(); //from images.cpp
        return true;
    }
    else {
        cerr<<"Cannot open image"<<endl;
        return false;
    }
}

//------------------------------------------------------------------------------

void search_tags(string tag){
    //clear the vectors of any old data
    found_vector.erase(found_vector.begin(), found_vector.end());
    
    //refresh lines_vector
    copy_contents();
    
    //using lines_vector, search each line for a user inputted tag
    for(int i = 0; i<lines_vector.size(); i++){
        size_t pos = lines_vector[i].find(tag);
        if (pos != string::npos){
            found_vector.push_back(lines_vector[i]);
        }
    }
    
    //write the found lines to a new .txt file
    ofstream ost{"database_filtered.txt"};
    if(!ost) error("Cant open output file", " database_filtered.txt");
    for(int i = 0; i<found_vector.size(); i++) ost<<found_vector[i]<<endl;
    ost.close();
}

//------------------------------------------------------------------------------

void delete_image(string file_name){
    //refresh lines_vector
    copy_contents();
    
    //write all elements of lines_vector back into the database, except for file to be deleted
    ofstream ost{"database.txt"};
    if(!ost) error("Cant open output file", " database.txt");
    for(int i=0; i<lines_vector.size(); i++){
        size_t pos = lines_vector[i].find(file_name);
        if (pos == string::npos)
            ost<<lines_vector[i]<<endl;
    }
}

//------------------------------------------------------------------------------

bool can_open(string file_name){
    //make sure image exists and can be opened (taken from Graph.cpp)
    ifstream fn(file_name.c_str());
    return fn;
}

void separate_tags(string tags){
    //clear the vectors of any old data
    tags_vector.erase(tags_vector.begin(), tags_vector.end());
    
    //separate the user inputted string of tags into several substrings
    string buff;
    stringstream ss(tags);
    while (ss>>buff) {
        tags_vector.push_back(buff);
    }
}

//------------------------------------------------------------------------------

void copy_contents(){
    //clear the vectors of any old data
    lines_vector.erase(lines_vector.begin(), lines_vector.end());
    
    //read all lines of the database into lines_vector
    ifstream ist{ "database.txt" };
    if (!ist) error("Cant open input file", " database.txt");
    string x;
    while (getline(ist, x)){
        lines_vector.push_back(x);
    }
    ist.close();
}

//------------------------------------------------------------------------------

void write_to_database(string file_name){
    //write all elements of lines_vector back into the database, except for file to be added with new tags
    ofstream ost{"database.txt"};
    if(!ost) error("Cant open output file", " database.txt");
    for(int i=0; i<lines_vector.size(); i++){
        size_t pos = lines_vector[i].find(file_name);
        if (pos == string::npos)
            ost<<lines_vector[i]<<endl;
    }
    
    //write the user inputted filename
    ost<<file_name;
    
    //write the separated tags after that, separated with a comma
    for(int i=0; i<tags_vector.size() && i<5; i++){
        ost<<" , "<<tags_vector[i];
    }
    
    //finish the line with a semicolon for marking purposes
    ost<<" ;"<<endl;
    ost.close();
}

//------------------------------------------------------------------------------

//define ints to be used as indexes
int j = -1;
int k = 0;

//define the external vectors from images.cpp
extern vector<string> images_vector;
extern vector<string> filtered_images_vector;

//for each function, make sure the index does not exceed/subceed the size of the vector
//send a message to console if it does

//------------------------------------------------------------------------------

bool increase_index(){
    if(j<images_vector.size()-1){
        j+=1;
        return true;
    }
    else {
	j=0;
	return true;
    }
}

//------------------------------------------------------------------------------

bool decrease_index(){
    if(j>0){ //vectors cannot have a size < 0
        j-=1;
        return true;
    }
    else {
	j=images_vector.size()-1;
        return true;		
    }
}

//------------------------------------------------------------------------------

bool increase_filtered_index(){
    if(k<filtered_images_vector.size()-1){
        k+=1;
        return true;
    }
    else {
        cerr<<"No more Images"<<endl;
        Error_window win_err(Point(200,200),250,25,"Error", "No more images");
        win_err.wait_for_button();
        return false;
    }
}

//------------------------------------------------------------------------------

bool decrease_filtered_index(){
    if(k>0){ //vectors cannot have a size < 0
        k-=1;
        return true;
    }
    else {
        cerr<<"No more Images"<<endl;
        Error_window win_err(Point(200,200),250,25,"Error", "No more images");
        win_err.wait_for_button();
        return false;
    }
}
