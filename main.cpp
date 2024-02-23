//
// Created by tarokh on 23/02/24.
//

#include <iostream>

int mySum(int, int);

int main(int argc, char* argv[]) {
    bool isActive = true;
    bool isNotActive = false;
    bool isFine( true );
    bool isNotFine{ false };

    char a = 'a';
    char b{ 'b' };

    std::cout << "the character a is ---->>>> " << a << '\n';
    std::cout << "the character b is ---->>>> " << b << '\n';
    std::cout << "The size of a char byte is --->>>> " << sizeof(char) << " bytes(s)" << std::endl;  // a character is one byte :)
    std::cout  << isNotFine << std::endl;   // it will show zero
    std::cout  << isActive << " " << isNotActive << std::endl;
    std::cout  << "Hello from learning_cxx\n";

    /**
     *  There are other types of characters like wchar_t for holding characters of Unicode character set,
     *  char16_t for holding UTF_16 character sets.
     */

    char c = 'a';
    char other_c = 97;  // these two are both the same (check the ASCII table)

    // each character is represented by an integer number in the character set.
    // a character literal is a character enclosed in single-quotes

    std::cout << "first 'a' character is -------->>>>> " << "(" << c << ")" << "\nsecond a character is ---->>>> " << other_c << std::endl;

    int x = 10;     // Decimal
    int y = 012;    // octal
    int z = 0xA;    // Hex

    std::cout << "these three are the same ----D--O--H--->>>>>>>>>>> " << x << " " << y << " " << z << std::endl;

    // Also, There are other integer types such as int64_t

    double PI{ 3.14 };
    double another_double{ 1. };
    double also_another_double{ .25 };
    double last_double { 3.14e10 };

    std::cout << PI << " " << another_double << " " << also_another_double << " " << last_double << std::endl;

    // there are other floating-point number types in C++ such as float and long double.

    // type void:

    // void is a type that has no value, we can not have objects of type void
    // we can have functions of type void (functions that do not return anything)
    // also, we can have pointers of type void -> void* ptr;

    unsigned long int o = 4578699897;
    std::cout << "the unsigned long int o has the value ---------->>>>>>>>> " << o << std::endl;

    double another_z = 123 / 456.0;
    std::cout << "The value of z is: " << another_z << '\n';

    std::cout << "Enter a number, I will echo it again ------>>>>> ";
    int inp_num = 0;
    std::cin >> inp_num;
    std::cout << "The number you've entered is ---------->>>>>>>>>> " << inp_num << std::endl;
    int first_number, second_number, sum_nums;
    first_number = second_number = sum_nums = 0;
    std::cout << "Enter two numbers , I will give you the sum of them --->>> " << std::endl;
    std::cin >> first_number >> second_number;
    sum_nums = mySum(static_cast<int>(first_number), static_cast<int>(second_number));
    std::cout << "The sum of the two numbers that you recently entered is --------->>>>>>>> " << std::abs(sum_nums) << std::endl;



    // for initializing a pointer that does not point to anywhere we can use the nullptr literal
    // for example

    char* ptr = nullptr;    // this pointer does not point to anywhere

    // to access a value stored in an object pointed to by a pointer, we need to dereference the pointer.
    // dereference operator is *

    char mychar = 97;
    char* pptr = &mychar;
    std::cout << "the value stored in pptr is ------------>>>>>> " << *pptr << "\n" << " the address of pptr itself is ------>>>> " << &pptr << std::endl;

    int correct = 54;
    int* wrong = &correct;
    *wrong = 67;
    std::cout << "value of wrong is ==============>>>>>>>> " << *wrong << " " << wrong << " " << &wrong << std::endl;


    return 0;

}


int mySum(int first, int second) {
    return first + second;
}
