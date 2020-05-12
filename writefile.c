#include <stdio.h> 
#include <string.h> 
   
int main(){ 
  
    // Declare the file pointer 
    FILE *fd; 
      
    // Get the data to be written in file 
    char buffer[50] = "this is a test\n"; 
  
    // Open the existing file GfgTest.c using fopen() 
    // in write mode using "w" attribute 
    fd = fopen("received_data/test.txt", "a"); 
      
    // Check if this filePointer is null 
    // which maybe if the file does not exist 
    if (fd == NULL) { 
        printf("test.txt file failed to open\n."); 
    } 
    else{ 
        printf("The file is now opened.\n"); 
          
        // Write the buffer into the file 
        if(strlen(buffer) > 0) { 

            // writing in the file using fputs() 
            fputs(buffer, fd);    
            fputs("\n", fd); 
        } 

        // Closing the file using fclose() 
        fclose(fd); 
          
        printf("Data successfully written in file test.txt\n"); 
        printf("The file is now closed.\n"); 
    } 
    return 0;         
} 