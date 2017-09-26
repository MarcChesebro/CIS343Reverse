//reverse.c
//used to reverse all the characters in a file
//format: reverse [inputFile] [outputFile]

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

int main(int argc, char** argv){
	
	//check to make sure 2 arguments were passed	
	if(argc == 3){

		//declare the char* for the data
		char* data;

		//fill data buffer from file and store the size of the file
		int size = read_file(argv[1], &data);
		
		//check to see if the file was read succeffully and return -1 if it did not.
		//read_file() already output and error to the error stream so no need to print another
		if(size == -1){
			return -1;
		}
		
		//flip the data
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

		//write the data back to the file and store what was returned in writeError 
		//for error checking
		int writeError = write_file(argv[2], flipData, size);
		
		//check if the write was succesfull if not return -1
		if(writeError == -1){
			return -1;
		}

		//free data and flipdata
		free(data);
		free(flipData);
	}else{
		//print error if the ammount of of agruments was incorrect
		fprintf(stderr, "Incorrect amount of arguments");
	}
}
