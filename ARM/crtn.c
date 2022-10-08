//
//  crtn.c
//  Runtime-Kernel
//
//  Created by FireWolf on 2021-01-29.
//

// Define the type of global destructor functions
typedef void (*GlobalDestructor)(void);

// Start address of the array of global destructors
extern GlobalDestructor __fini_array_start[0];

// End address of the array of global destructors
extern GlobalDestructor __fini_array_end[0];

// Initialize C++ global variables
void _fini(void)
{
    for (GlobalDestructor* destructor = __fini_array_start; destructor != __fini_array_end; destructor += 1)
    {
        (*destructor)();
    }
}
