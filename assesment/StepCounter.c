#include "FitnessDataStruct.h"

int main()
{
    FITNESS_DATA fd;
    STEP_COUNTER sc;
    
    sc.count,sc.print_count,sc.steps_int = 0;
    #define buffer_size 1024
    
    int i = 0;
    int total_steps = 0;
    int flag = 1;
    int continuous_count = 0;
    int end_index;
    int start_index;
    int longest_count=0;
    int most_start_index;
    int count_a=0;
    int linecount;
    int max_line_number = 0;
    int min_line_number = 0;

    char line_buffer[buffer_size];  
    char filename[buffer_size];
    printf("Please enter the name of the data file: ");
    fgets(line_buffer, buffer_size, stdin);
    sscanf(line_buffer, " %s ", filename);


    FILE *input = fopen(filename, "r");
    if (!input)
    {
        printf("Error: File could not be opened\n");
        return 1;
    }
    
    while (fgets(line_buffer, buffer_size, input))
            {
                sc.count++;
            }

    fseek(input,0,SEEK_SET);
     for (int i = 0; i < sc.count; i++) {
        fgets(line_buffer, buffer_size, input);
        tokeniseRecord(line_buffer, ",", fd.date, fd.time,fd.steps);
        sc.steps_int=atoi(fd.steps);
        sc.count_steps[i] = sc.steps_int;
    }

    int min = sc.count_steps[0];
    int max = sc.count_steps[0];


    while(flag){
    
    printf("A: Input filename\n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the data and time of the timeslot with the fewest steps\n");
    printf("D: Find the data and time of the timeslot with the largest number of steps \n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500steps\n");
    printf("Q: To quit\n");
    printf("Choose Option : ");
    
    scanf(" %c",&sc.op); 

    switch(sc.op){
    case 'A':
        printf("Input filename : %s\n",filename);
        break;
    case 'B':
        printf("The total number of records in the file : %d\n",sc.count);
        break;
    case 'C':

        for (i=0;i<sc.count;i++){
            if(sc.count_steps[i] < min){
                min = sc.count_steps[i];
                min_line_number = i;
            }
        }
        fseek(input,0,SEEK_SET);
        linecount=0;
        while (fgets(line_buffer, buffer_size, input) != NULL) {
        linecount++;
        if (linecount == min_line_number + 1) {
            tokeniseRecord(line_buffer, ",", fd.date, fd.time, fd.steps);
            printf("Fewest Steps: %s %s\n", fd.date, fd.time);
            break;
        }
    }
        break;

    case 'D':
        
        for (i=1;i<sc.count;i++){
            if(sc.count_steps[i] > max){
                max = sc.count_steps[i];
                max_line_number = i;
            }
        }
        fseek(input, 0, SEEK_SET);
        linecount = 0;
        while (fgets(line_buffer, buffer_size, input) != NULL) {
        linecount++;
        if (linecount == max_line_number + 1) {
            tokeniseRecord(line_buffer, ",", fd.date, fd.time, fd.steps);
            printf("Largest Steps: %s %s\n", fd.date, fd.time);
            break;
        }
    }
    
    break;

    case 'E':
        for (i=0;i<sc.count;i++)
        {
            total_steps += sc.count_steps[i];
        }
        printf("Mean step count : %d\n",total_steps/sc.count);
    break;
        

   case 'F':

    fseek(input, 0, SEEK_SET);
    linecount=0;
    for (i = 0; i < sc.count; i++) {
        if (sc.count_steps[i] >= 500) { 
            continuous_count++;

            if (continuous_count == 1) {
                start_index = i-1; 
            }

            if (continuous_count > longest_count) {
                longest_count = continuous_count;
                most_start_index = start_index;
                end_index = i + 1;
            }
        } else {
            continuous_count = 0;
            
        }
    }
   
    while (fgets(line_buffer, buffer_size, input) != NULL) {
        linecount++;
        if(linecount==most_start_index){
            tokeniseRecord(line_buffer, ",", fd.date, fd.time, fd.steps);
            printf( "%s %s\n", fd.date, fd.time);
            
        }
        if(linecount==end_index){
            tokeniseRecord(line_buffer, ",", fd.date, fd.time, fd.steps);
            printf( "%s %s\n", fd.date, fd.time);
            
        }
    
    }
    break;
    
    case 'Q':
        flag = 0;
        break;
        
    }

    }
   return 0;
}
