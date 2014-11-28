Alright. This. Is. Everything. 
It opens images, downloads url's, adds tags, deletes images, searches for tags, everything. It also supports 2 extra file types, png and bmp (although png takes FOREVER to load onto the screen).

Secondly, to edit the tags: just open up the "Open file" window and type in the image you want to edit and enter the new tags. It will overwrite the old tags with the new ones. 

A few glitches/bugs:
If the database.txt file is empty, then it will crash.
It can't really detect invalid url's (it can, but only if the url contains spaces, like if you entered "this is not a real url" for the url. If you entered "thisisnotarealurl" then it wouldn't detect it and try to open the image).
When searching for tags, it can only search for one tag at a time. I know the instructions say "Any combination of tags" but ours only works if you enter one tag.

Furthermore, we are still missing:
The 2 c++14 features. We don't have either of those.
I'm not sure, but all the functions should be less than 24 lines (which is required) once all the comments are removed. We'll have to remove the comments for the actual program, but leave them for now because they're required on the report. I haven't commented on the entire thing, however, just the files in the main folder. The window class files in the fltk folder need to be commented for the report
Also, I'm not entirely sure that the window files (Menu_window, File_window_, Error_window, etc) count as classes. I think they do, but I'm not 100% sure. 

Lastly, we actually have 3 of the last objectives completed, so we should get 5 extra points

Right now, I'm guessing we would get <80 on the project. If we can get the things we're missing, we could get a 100 or more.