#include <stdio.h>

/**
 * This program declares variable a
 * and prints out its address.
 *
 * @author Johannes Nupen Theigen
 * @version 03.10.2025
 * @since 03.10.2025
 */

int main() {
    char a;  // Memory implicitly allocated by the compiler on the stack (automatic storage)

    printf("Address of a: %p\n", &a);  // Prints the address of a

    return 0;
}
