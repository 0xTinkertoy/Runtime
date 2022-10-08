//
//  crti.c
//  Runtime-Kernel
//
//  Created by FireWolf on 2021-01-29.
//

// ARM's ABI places global constructors in the `.init_array` section.
// The `crti.o` object provided by the cross compiler does nothing.

// Define the type of global constructor functions
typedef void (*GlobalConstructor)(void);

// Start address of the array of global constructors
extern GlobalConstructor __init_array_start[0];

// End address of the array of global constructors
extern GlobalConstructor __init_array_end[0];

// Initialize C++ global variables
void _init(void)
{
    for (GlobalConstructor* constructor = __init_array_start; constructor != __init_array_end; constructor += 1)
    {
        (*constructor)();
    }
}