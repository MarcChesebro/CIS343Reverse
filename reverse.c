//reverse.c
//used to reverse all the characters in a file
//format: reverse [inputFile] [outputFile]

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

int main(int argc, char** argv){
	
	//check to make sure 2 arguments were passed	
	if(argc == 2){

		//declare the char* for the data
		char* data;

		//fill data buffer from file
		read_file(argv[1], &data);
		
		//flip the data
		
		//calculate size of file using stat
		struct stat st;
		stat(argv[1], &st);
		int size = st.st_size;

		//determine the number of elements in the data array
		int numElement = size / sizeof(char);
			
		//create a char* to hold the fliped data
		char* flipData;
		
		//allocate memory for the flipped data
		flipData = (char*)malloc(size);

		//loop through data backwards and fill flipdata
		int j = 0;
		for(int i = numElement - 1; i >= 0; i--){
			
			flipData[j] = data[i];
			j++;
		}

		//write the data back to the file
		write_file(argv[1], flipData, size);

		//free data and flipdata
		free(data);
		free(flipData);
	}else{
		fprintf(stderr, "Incorrect amount of arguments");
	}
}
