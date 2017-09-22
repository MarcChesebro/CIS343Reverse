//file_utils.c

#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

//function that reads a file
//char* filename: path of file relative to exe
//char** buffer: pointer to the pointer that hold the files data
int read_file( char* filename, char **buffer ){

	printf("filename: %s\n", filename);
	
	//calculate size of file using stat
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;

	//allocate memory for the data in the file
	*buffer = (char*)malloc(size);
	
	//open file
	FILE* file = fopen(filename, "r");
	
	//check if we successfully grabed the file
	if(file == NULL){
		fprintf(stderr, "Could not open file");
		return 1;
	}	
	
	//determine the number of characters in the file
	int numElements = size / (int)sizeof(char);
	//load the characters into the buffer with fread
	fread(*buffer, sizeof(char), numElements, file);

	printf("%s\n", *buffer);
	
	//return succsess
	return 0;
}

//Function that writes to a file
//char* filename: path to write to/create
//char* buffer: data to be written
//int size: size of data
int write_file( char* filename, char *buffer, int size){
	return 0;
}
