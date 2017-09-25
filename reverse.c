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
		//printf("data size:%lu\n", sizeof(*data));
		//printf("data:%s\n", data);
		//printf("char size:%lu\n", sizeof(char));
		
		//calculate size of file using stat
		struct stat st;
		stat(argv[1], &st);
		int size = st.st_size;

		//determine the number of elements in the data array
		int numElement = size / sizeof(char);
		printf("numElement%i\n", numElement);
		
		//create a char* to hold the fliped data
		char* flipData;
		
		flipData = (char*)malloc(size);
		int j = 0;
		for(int i = numElement - 1; i >= 0; i--){
			
			flipData[j] = data[i];
			j++;
		}

		printf("flipData:%s\n", flipData);

		free(data);
		free(flipData);
	}else{
		fprintf(stderr, "Incorrect amount of arguments");
	}
}
