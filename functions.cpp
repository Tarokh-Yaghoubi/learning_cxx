
#include <iostream>
#include <string>

void func();    // this is function declaration
int intfn();
int multiple_returns(int);
void byValue(int val);
void byReference(int&);
void byConstReference(const std::string&);
void byPointer(int*);

// overloaded functions

void myPrint_overloaded(char);
void myPrint_overloaded(std::string);
void myPrint_overloaded(int);
// then we implement function definitions and call each one.

int main () {
    // we can break our program into smaller chunks called 'functions'.
    // a function has a return type, a name, a list of parameters, and a function body.

    /**
     *      type function_name (param1, param2) {
     *          statement;
     *          statement2;
     *          return something;
     *      }
     */

    std::cout << "the return value of intfn function is : " << intfn() << std::endl;
    std::cout << "the return value of multiple_returns functions is : " << multiple_returns(4) << std::endl;

    // There are different ways of passing values to functions,
    // 1 - Passing by value / copy
    // 2 - Passing by reference
    // 3 - Passing by constant reference
    // 4 - Passing by Pointer (In C programming)

    // PASSING BY VALUE / COPY

    // when we pass an argument to a function, a copy of that argument is made and passed to the function if the function parameter type is
    // not a reference. This means the value of the original argument does not change. A copy of the argument is made.

    int val = 4;
    byValue(val);
    std::cout << "the value of val after passing to byValue() function " << val << std::endl;   // the value is still 4

    // because it was copy by value;

    // PASSING BY REFERENCE

    // when a function parameter type is a reference type, then the actual argument is passed to the function,
    // The function can modify the value of the argument.
    byReference(val);
    std::cout << "the value of val after passing to byReference() function " << val << std::endl;   // the value is 5 !
    // passing by reference is best avoided.

    // What is preferred is passing an argument by const reference, also referred to as a reference to const.
    // It will be more efficient to pass an argument by reference, but to make sure that it is not changed,
    // we make it of const reference type.
    std::string str = "tarokh is a moderate programmer";
    byConstReference(str);
    // In  this function, you cannot change the value of the argument, because it is (reference to const).
    // We use passing by const reference for efficiency reasons, and the const modifier ensures the value of an argument
    // will not be changed.

    // We also have passing by pointer (used in C programming language);
    // the value of the argument is also changed in this way , and it is not a type of copying.
    byPointer(&val);
    std::cout << "The value of val after passing the byPointer is " << val << std::endl;

    // FUNCTION OVERLOADING

    // we can have multiple functions with the same name, but with different parameter types.
    // This is called 'function overloading'. A simple explanation is: when the function names are the same
    // but the parameter types differ, then we have overloaded the functions.

    myPrint_overloaded('a');    // calling character overload
    myPrint_overloaded("tarokh is a moderate programmer");      // calling string overload
    myPrint_overloaded(657);    // calling integer overload

}

void func() {
    std::cout << "This is function definition" << std::endl;
}


int intfn() {
    return 3 + 5;
}

int multiple_returns(int x) {
    if (x > 10) return x;
    else return x + 23;
}

void byValue(int val) {
    val++;
    std::cout << "the value of val is " << val << " after incrementing" << std::endl;
}

void byReference(int& val) {
    val++;
    std::cout << "The value of val after incrementing is : " << val << std::endl;
}

void byConstReference(const std::string& str) {
    std::cout << "Argument passed by const reference " << str << std::endl;
}

void byPointer(int* number) {
    (*number)++;
}

void myPrint_overloaded(char param) {
    std::cout << "the value of char param is : " << param << std::endl;
}

void myPrint_overloaded(const std::string& str) {
    std::cout << "the value of string param is : " << str << std::endl;
}

void myPrint_overloaded(int x) {
    std::cout << "the value of integer param is : " << x << std::endl;
}
