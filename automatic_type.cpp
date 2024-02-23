
#include <iostream>
#include <string>

int main() {
    auto c = 'a';       // char type
    auto x = 123;       // int type

    // the type can be also deduced based on the type of expression
    auto d = 123.45 / 345.98;   // d is now double
    std::cout << "the value of d is : " << d << std::endl;

    // we can use auto as part of the reference type

    int num = 546;
    auto& y = num;      // y is type (int)

    const auto& ref = num;      // ref is now type (const int)

    return 0;
}
