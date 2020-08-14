//ls 

#include <stdio.h> 
#include <dirent.h> 
  
int main() 
{ 
    struct dirent *de;   
   
    DIR *dr = opendir(".");
    
    if (dr == NULL)   
    { 
        write(1,"Could not open current directory",33); 
        return 0; 
    } 
  
    while ((de = readdir(dr)) != NULL) 
            printf("\n%s",de->d_name); 
  
    closedir(dr);     
    return 0; 
} 

