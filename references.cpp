
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "A message from reference.cpp" << std::endl;

    // another somewhat similar concept to pointers, are references.
    // a reference type is an alias to an existing object in memory.
    // References must be initialized .

    int x(123);
    const int &y(x);  // now, y is a reference to x, if you change y, you have also changed x.
    // If you change x, you have also changed y; (because y is a reference to x);

    x = 78;
    std::cout << "the value of x and y after changing x to 78 is ----->>>>>>> " << x << " " << y << std::endl;

    return 0;
}
