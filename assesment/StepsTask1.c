#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct 
{
	char date[11];
	char time[6];
	int steps;
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
int main() {

   FILE* fp = fopen("FitnessData_2023.csv","r");
   if (fp == NULL){
    printf("fail to read file");
    return 0;
   }

   char buff[1024];
   int row_count = 0;
   int field_count=0;

   while(fgets(buff,1024,fp))
   {
    printf("%s\n",buff);
    row_count++;

   }
   printf("Number of record in file : %d\n",row_count);
        
    
}

    

    


