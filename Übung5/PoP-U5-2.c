// Author: Poecksteiner Patrick
// Filename: PoP-U5-2.c
// Last Update: 2022-04-18
// Content: Programm whichs reads input from stdin or file(s) and sort it depending on -d or not.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 500
#define MAX_LINES 1000

//char ** read_lines(int *lines, FILE *fp);
void read_lines(char* **text, int *lines, FILE *fp);
void file_handling(char* **text, int *lines, int argc, char* argv[]);
void sort_text_asc(char **text, int lines);
void sort_text_desc(char **text, int lines);

int main(int argc, char* argv[])
{
	char **text = NULL;
	int lines=0;

	//Argument handling for selecting the sorting type
	if(argc == 1) 
	{
		// without -d and from stdin
		read_lines(&text, &lines, stdin);
		sort_text_desc(text, lines);
	}
	else if((argc == 2) && (strcmp(argv[1], "-d")==0))	
	{
		// with -d and from stdin
		read_lines(&text, &lines, stdin);
		sort_text_asc(text, lines);
	}
	else if ((argc >= 2) && (strcmp(argv[1], "-d")!=0))
	{
		// without -d and from file(s)
		file_handling(&text, &lines, argc, argv);
		sort_text_desc(text, lines);
	}
	else if ((argc > 2) && (strcmp(argv[1], "-d")==0))
	{	
		// with -d and from file(s)
		file_handling(&text, &lines, argc, argv);
		sort_text_asc(text, lines);
	}
	else
	{
		printf("Usage: .\\PoP-U5-2 [-d] [FILE1] [FILE-N]\n");
		exit(1);
	}

	printf("------------------------------------\n");
	printf("Output:\n");
  	for ( int i = 0; i < lines; i++)
	{
		printf("%s", text[i]);
	}

	//Freeing of pointer
	if(text != NULL)
	{
		free(*text);
		text = NULL;
	}

	return 0;
}

//Name: read_lines
//Parameter: char* **text - triple-pointer, which points the pointer list, which pointing to the rows, int *lines - number of lines and sums them up, FILE *fp - file pointer either stdin or files
//Description: Functions reads all the lines until EOF depending on the file pointer
//Return value: -
void read_lines(char* **text, int *lines, FILE *fp)
{
	char line_buffer[MAX_LENGTH];
	size_t line_length;
	
	while(fgets(line_buffer, MAX_LENGTH, fp) != NULL)
	{
		//Check if lines below MAX_LINES
		if (*lines > MAX_LINES-1)
			break;

		line_length = strlen(line_buffer);
		
		if(line_buffer[line_length-1] == '\n')
		{	
			//Add addtional line for array reallaction is needed
			*text = (char**) realloc(*text, (*lines+1)*sizeof(char*));

			//Allocate the needed size for new line 
			(*text)[*lines] = (char *) malloc(sizeof(char) * (line_length + 1));
			strcpy((*text)[*lines], line_buffer);
	
			++(*lines);
		}
		else
		{
			//Clear line
			while ( getchar() != '\n' );
			printf("Error: String was too long - not saved!\n");
		}
	}
}

//Name: file_handling
//Parameter: char* **text - triple-pointer, which points the pointer list, which pointing to the rows, int *lines - number of lines and sums them up, int argc - passing through the arguments counter, char* argv[] - passing through the values of the command-line
//Description: Functions reads through all command-line arguments for file names, opens the files and calls the function to read all the lines
//Return value: -
void file_handling(char* **text, int *lines, int argc, char* argv[])
{
	int i;
	FILE *fptr;

	//Check if -d is given or not. Then set iterating val.
	if (strcmp(argv[1], "-d")==0)
		i=2;
	else
		i=1;

	while(i < argc)
	{
		
		if ((fptr = fopen(argv[i],"r")) == NULL)
		{
			// Program exits if the file pointer returns NULL
			printf("Error! opening file!\n");
			exit(1);
		}

		//Calling other function to reads all the files
		read_lines(text, lines, fptr);

		fclose(fptr);
		i++;
	}
	
}

//Name: sort_text_desc
//Parameter: char **text - points to each of the rows, int lines - number of lines
//Description: Function sorts the list according bubblesort descending aaa-zzz
//Return value: -
void sort_text_desc(char **text, int lines)
{
	int i,j, sorted=1;
	char *tmp;

	for(i=lines-1; i>0 && sorted; i--)
	{
		sorted=0;
		for(j=0; j<i;j++)
		{
			if(*text[j] < *text[j+1])
			{
				tmp = text[j];
				text[j] = text[j+1];
				text[j+1] = tmp;
				sorted = 1;
			}
		}
	}
}

//Name: file_handling
//Parameter: char **text - points to each of the rows, int lines - number of lines
//Description: Function sorts the list according bubblesort asccending zzz-aaa
//Return value: -
void sort_text_asc(char **text, int lines)
{
	int i,j, sorted=1;
	char *tmp;

	for(i=lines-1; i>0 && sorted; i--)
	{
		sorted=0;
		for(j=0; j<i;j++)
		{
			if(*text[j] > *text[j+1])
			{
				tmp = text[j];
				text[j] = text[j+1];
				text[j+1] = tmp;
				sorted = 1;
			}
		}
	}
}