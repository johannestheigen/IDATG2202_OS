#include <stdio.h>

/**
Simple program that demonstrates what happens if you try to
create pointer,set it to NULL, and attempt to dereference it.
When compiled and run, the pointer variable causes segmentation fault.
The reason for this is that a NULL pointer does not points to any memory
location,so dereferencing it will result in a segmentation fault.
In other words the pointer is uninitialized, therefore causing
segmentation fault.

@author Johannes Nupen Theigen
@version 02.10.2025
@since 02.10.2025
*/
int main() {

int *num_ptr; // Pointer variable

num_ptr = NULL; // Assigning pointer to NULL. 

printf("Attempting to dereference pointer '*num_ptr': %d\n", *num_ptr); // This will never print out

return 0;

}
