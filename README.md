# Array of Structures and File I/O

This assigment contains function to get familiar with getting data from file into array of structures, sorting the data and finally expoting data to new .txt file

## Required_files_to_download 
 1. [input_file.txt](https://github.com/ap5967ap/Structures/blob/main/input_file.txt)
 2. [Structure.txt](https://github.com/ap5967ap/Structures/blob/main/Structures.c)
 One can download the files by cloning the repository

### Explaining the functions of Structures.c 
 1.get_data() takes a pointer to structure and File pointer to input_file.txt and reads value from input_file.txt and inputs in a Student struct instance
 2.get_data_array() add data to each element to array of structures. It is done by calling the get_data() function
 3.sort() function sort the given array of structures based on id of students in the array.
   The sorting meechanism used is "Bubble sort"
   ### "The method works by examining each set of adjacent elements in the array, from left to right, switching their positions if they are out of order."
