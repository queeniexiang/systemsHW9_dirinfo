#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>



int main() {
  DIR * stream = opendir("..");
  //printf("Pointer: %p", stream);
  struct dirent * d_ptr;

  struct stat d_file;
  int size = 0; 
  

  if (stream) {
    printf("Directory Statistics: \n"); 
    printf("\nPrinting files in directory: \n");
    while ( (d_ptr = readdir(stream))) {
      stat(d_ptr->d_name, &d_file);
      size += d_file.st_size;
      
      if (d_ptr->d_type == DT_DIR) {
	printf("Directory: ");
      }

      else {
	printf("File: ");
      }
      
      printf("%s\n", d_ptr->d_name);
	
    }
    printf("\nTotal directory size: %d Bytes\n", size);
  }
}
