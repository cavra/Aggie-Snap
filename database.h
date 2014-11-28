#include "std_lib_facilities_4.h"

//four main functions
bool open_file(string file, string tags);
bool open_url(string url, string tags, string file_name);
void search_tags(string tag);
void delete_image(string file_name);

//functions called by above functions
bool can_open(string file_name);
void separate_tags(string tags);
void copy_contents();
void write_to_database(string file_name);

//functions called directly whenever a next/previous button is pressed
bool increase_index();
bool decrease_index();
bool increase_filtered_index();
bool decrease_filtered_index();
