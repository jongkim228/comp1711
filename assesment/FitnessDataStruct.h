#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct 
{
    char date[11];
	char time[6];
	char steps[4];
} FITNESS_DATA;

typedef struct
{
    int total_steps;
    int steps_int;
	int print_count;
	int count;
	int buffer_size;
    char op;
	char line_buffer;
    int count_steps[1024];
} STEP_COUNTER;

void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}




