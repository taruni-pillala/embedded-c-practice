#include <stdio.h>
#include <stdlib.h>
// data segment-global variable WITH initial value
int global_with_value = 42;
// BSS segment-global variable without the inital value
int global_no_value;
int main()
{
    // Stack-local variable inside function
    int local_variable = 100;
    // heap-dynamically allocated memory
    int *heap_variable = (int *)malloc(sizeof(int));
    *heap_variable = 200;
    // static- stays in DATA segment, remembered between calls
    static int stactic_variable = 50;

    printf("==MEMORY LAYOUT EXAMPLE==\n\n");

    printf("DATA SEGMENT:\n");
    printf("global_with_value: %d\n", global_with_value);
    printf("Address: %p\n\n", (void *)&global_with_value);

    printf("BSS SEGMENT:\n");
    printf("global_no_value: %d\n", global_no_value);
    printf("Address: %p\n\n", (void *)&global_no_value);

    printf("STACK:\n");
    printf("local_variable: %d\n", local_variable);
    printf("Address: %p\n\n", (void *)&local_variable);

    printf("Data segment(static):\n");
    printf("stactic_variable: %d\n", stactic_variable);
    printf(" Address: %p\n\n", (void *)&static_variable);
    // always free heap
    free(heap_variable);
    return 0;
}