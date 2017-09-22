//reverse.c
//used to reverse all the characters in a file
//format: reverse [inputFile] [outputFile]

#include <stdio.h>
#include "file_utils.h"

int main(int argc, char** argv){
	
	//declare the char* for the data
	char* data;
	
	//check to make sure 2 arfuments were passed	
	if(argc == 2){
		//fill data buffer from file
		read_file(argv[1], &data);
	}else{
		fprintf(stderr, "Incorrect amount of arguments");
	}
}
