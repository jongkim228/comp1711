#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct 
{
    char date[11];
	char time[6];
	char steps[4];
} FITNESS_DATA;

// Define any additional variables here

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
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

// Complete the main function
int main(){
   
    int line_count = 0; //define line count to count lines in csv file
    int print_count = 0; //define print_count to print lines until 3
    FITNESS_DATA fd; //define structure name
    
    char filename[] = "FitnessData_2023.csv"; // define filename
    FILE *file = fopen(filename,"r"); // open file
    
    if (file == NULL){ //error if file is not opened 
        perror("");
        return 1;
    }
    int buffer_size = 100; //define buffer size
    char line_buffer[buffer_size]; //define line buffer

    while(fgets(line_buffer,buffer_size,file) != NULL){ //use while loop to get file details until buffer size
        line_count ++; //count lines until buffer size 
    }
    printf("Number of records in file: %d\n",line_count); //print buffer size

    fclose(file); //close file to get lines until line 3

    
    file = fopen(filename,"r"); //reopen the file
     
     if (file == NULL){ //error if file is not opened
        perror("");
        return 1;
    }
    
    while(fgets(line_buffer,buffer_size,file) != NULL){ //get file data until buffer_size
        print_count ++; //count lines untill the end
        
        tokeniseRecord(line_buffer, ",", fd.date, fd.time, fd.steps); //change format comma to slash
        
            int steps_int = atoi(fd.steps); //chage char steps to int
            printf("%s/%s/%d\n", fd.date, fd.time, steps_int); 
        }
    }
    fclose(file);
    return 0;
