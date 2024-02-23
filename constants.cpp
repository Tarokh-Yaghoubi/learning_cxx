
#include <iostream>
#include <string>

constexpr int add (int first, int second) {
    return first + second;
}

int main() {

    const int n = 4;        // this object is now immutable
    int arr[n] = {1, 2, 3, 5};
    for (auto i : arr) std::cout << "i: " << i << std::endl;

    const std::string s = "tarokh is a moderate programmer";

    // YOU CANNOT CHANGE THE VALUE OF S ;

    std::cout << "The value of constant s is : " << s << std::endl;

    // an object that is defined as const, MUST be initialized.
    // You can not postpone the definition for some time later.


    // constexpr is used to declare variables or functions that can be evaluated at compile time
    // It is evaluated at compile time whenever possible
    // It can apply to variables, functions, and expressions.

    constexpr int res = add(4, 4);
    std::cout << "the value of res is " << res << std::endl;

    return 0;
}

