#include "fltk/Menu_window.h"
#include "fltk/Graph.h"
#include "fltk/GUI.h"
#include "fltk/Error_window.h"
#include "images.h"
#include "std_lib_facilities_4.h"

//define the vectors here, to be used across all functions
vector<string> images_vector;
vector<string> filtered_images_vector;
vector<string> tag_vector;
vector<string> holding_tag_vector;
vector<string> holding_vector;

//declare string to be used across several functions
string found_line;

//------------------------------------------------------------------------------

void get_images(){
    //clear vectors of old data
    images_vector.erase(images_vector.begin(), images_vector.end());
    holding_vector.erase(holding_vector.begin(), holding_vector.end());

    //open the text file and write all image filenames to a vector
    ifstream ist{ "database.txt" };
    if (!ist) error("Cant open input file", "database.txt");
    string x;
    while (ist>>x) holding_vector.push_back(x);
    for(int i = 0; i<holding_vector.size(); i++){
        size_t pos = holding_vector[i].find("images/");
        if (pos != string::npos) images_vector.push_back(holding_vector[i]);
    }
    ist.close();
}

//------------------------------------------------------------------------------

void get_filtered_images(){
    //clear vectors of old data
    filtered_images_vector.erase(filtered_images_vector.begin(), filtered_images_vector.end());
    holding_vector.erase(holding_vector.begin(), holding_vector.end());

    //open the text file and write all image filenames to a vector to be scanned
    ifstream ist{ "database_filtered.txt" };
    if (!ist) error("Cant open input file", "database_filtered.txt");
    string x;
    while (ist>>x) holding_vector.push_back(x);
    for(int i = 0; i<holding_vector.size(); i++){
        size_t pos = holding_vector[i].find("images/");
        if (pos != string::npos) filtered_images_vector.push_back(holding_vector[i]);
    }
    ist.close();
}

//------------------------------------------------------------------------------

string get_tags(string file_name){
    //clear vectors of old data
    tag_vector.erase(tag_vector.begin(), tag_vector.end());
    holding_tag_vector.erase(holding_tag_vector.begin(), holding_tag_vector.end());
    holding_vector.erase(holding_vector.begin(), holding_vector.end());
    
    get_current_line(file_name);
    line_to_string();
    find_tags();
    return tags_to_string();
}

//------------------------------------------------------------------------------

//find the line of the current picture
void get_current_line(string file_name){
        ifstream ist{ "database.txt" };
    if (!ist) error("Cant open input file", "database.txt");
    string x;
    while (getline(ist, x)){
        holding_vector.push_back(x);
    }
    for(int i = 0; i<holding_vector.size(); i++){
        size_t pos = holding_vector[i].find(file_name);
        if (pos != string::npos) found_line = holding_vector[i];
    }
    ist.close();
}

//------------------------------------------------------------------------------

//convert line into series of strings
void line_to_string(){
    string buff;
    stringstream ss(found_line);
    while (ss>>buff) {
        holding_tag_vector.push_back(buff);
    }
}

//------------------------------------------------------------------------------

//find which strings are tags and put them into a new vector
void find_tags(){
    for(int i = 0; i<holding_tag_vector.size(); i++){
        size_t pos1 = holding_tag_vector[i].find("images/");
        size_t pos2 = holding_tag_vector[i].find(",");
        size_t pos3 = holding_tag_vector[i].find(";");
        if (pos1 == string::npos && pos2 == string::npos && pos3 == string::npos){
            tag_vector.push_back(holding_tag_vector[i]);
        }
    }
}

//------------------------------------------------------------------------------

//turn the new vector into a string and return
string tags_to_string(){
    string image_tags;
    stringstream strs;
    copy(tag_vector.begin(), tag_vector.end(), ostream_iterator<string>(strs," "));
    image_tags = strs.str();
    return image_tags;
}