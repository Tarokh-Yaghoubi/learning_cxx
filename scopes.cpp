
#include <iostream>
#include <string>

int main() {
    int val = 45;
    {
        // this 'val' is a different variable from the outer 'val'
        // Because it is in another block (It has a different scope)
        int val = 67;
        std::cout << "the value of val is ------>>>> " << val << std::endl; // this is 67
    }

    std::cout << "the value of outer val is ------->>>>> " << val << std::endl;     // this is 45

    // lifetime: The lifetime of an object, is the time that an object spends in memory. The lifetime is determined by a
    // so-called storage duration. There are different kinds of storage durations.

    // Automatic Storage Duration: The Automatic Storage Duration is a duration where memory for an object is automatically allocated at
    // the beginning of a block and deallocated when the code block ends. This is also called a stack memory; Objects are allocated on the stack.
    // In this case, the Objects lifetime is determined by its scope. All local objects have this storage duration.

    // Dynamic Storage Duration: The dynamic storage duration is a duration where memory for an object is manually allocated and manually deallocated.
    // This kind of storage is often referred to as 'heap memory'. The user determines when the memory for an object will be allocated, and when it will
    // be released. The lifetime of an object is not determined by a scope in which the object was defined. We do it through operator (new) and 'smart pointers'.
    // In modern C++, We should prefer the 'smart pointer' facilities to operator 'new'.

    // Static Storage Duration: When an object declaration is prepended with a static specifier, it means the storage for a static object is allocated when the program
    // starts, and deallocated when the program ends. There is only one instance of such objects, and (with a few exceptions) their lifetime ends when a program ends.
    // They are objects we can access at any given time during the execution of a program.


    // OPERATOR NEW AND DELETE
    // we can dynamically allocate and deallocate storage for our object and have pointers pointing to this newly allocated memory.
    // The operator new allocates space for an object. The object is allocated on the free-store, often called heap or heap memory.
    // The allocated memory must be deallocated using operator 'delete'.

    int* p = new int;
    *p = 234;
    std::cout << "The pointed value is : " << *p << std::endl;
    delete p;       // deallocate p after you are done.

    int* ptr = new int[3];
    ptr[0] = 23;
    ptr[1] = 45;
    ptr[2] = 65;
    std::cout << ptr[0] << " " << ptr[1] << " " << ptr[2] << std::endl;
    delete [] ptr;

    int x = 34;
    int* newPtr = new int;
    *newPtr = x;
    std::cout << "The value of newPtr after initializing it using x is ------->>>>> " << *newPtr << std::endl;
    delete newPtr;

    return 0;

}   // end of scope here !!
