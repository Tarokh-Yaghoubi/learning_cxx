
#include <iostream>
#include <cstring>

int main() {

    // expressions ending with a semicolon are statements.
    // selection statement: they allow us to use a condition, and base on that condition, execute the appropriate statement.

    bool b( true );
    if (b) std::cout << "The condition is true" << std::endl;

    // To use multiple statements if the condition is true, we use curly braces {}

    b = false;
    if (b)
        std::cout << "Second condition is true " << std::endl;
    else
        std::cout << "Second condition is false " << std::endl;

    bool mycondition = true;
    int x = 0;

    if (mycondition) {
        x = 1;
    }
    else if (!mycondition) {
        x = 2;
    }

    std::cout << "the value of x is : " << x << std::endl;

    // we can rewrite the above expression using conditional expression like this :

    bool otherCondition = true;
    x = (otherCondition) ? 1 : -2;
    std::cout << "The value of x in the ternary condition is : " << x << std::endl;

    bool a = true;
    bool p = true;

    if (a && p) std::cout << "The entire condition is true" << std::endl;
    else std::cout << "The entire condition is false" << std::endl;

    return 0;
}
