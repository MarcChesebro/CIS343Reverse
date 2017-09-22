//file_utils.h

//include guards
#ifndef file_utils
#define file_utils

//function that reads a file
//char* filename: path of file relative to exe
//char** buffer: pointer to the pointer that hold the files data
int read_file( char* filename, char **buffer );

//Function that writes to a file
//char* filename: path to write to/create
//char* buffer: data to be written
//int size: size of data
int write_file( char* filename, char *buffer, int size);

#endif
