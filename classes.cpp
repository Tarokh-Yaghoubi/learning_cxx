
//
// Tarokh, 25/02/2024
//

#include <iostream>
#include <string>


// Class is a user-defined type. A class consists of members. The members are data members and member functions.
// A class can be described as data and some functionality on that data, wrapped into one. An instance of a class,
// is called an object. To only declare a class name, we write:

class FirstClass;
// to define an empty class we add a class body marked by curly braces {}.


// create an instance

// 'obj' is an object of 'SecondClass'
// 'obj' is an instance of class SecondClass, 'obj' is a Class Instance

// A class can have some set of data in it, These are called 'member fields'.


// Similarly, a class can store functions. These are called member functions. They are mostly used to do some operations
// On data fields

// There are two ways to define this type of functions,
// one way is to define them inside the class.
// the other way is to define them outside.

class ClassWithMemberFunctions {


    static void printx() {
        std::cout << "Print X from ClassWithMemberFunctions" << std::endl;
    }

    static void sayHello() {
        std::cout << "Hello from class ClassWithMemberFunctions" << std::endl;
    }

};

// Access Specifiers

class AccessSpecificClass {
public:
    // everything in here, has public access level.

protected:
    // everything in here, has protected access level.

private:
    // everything in here, has protected access level.
};

// Default access specifier for a class is private if none of access specifiers is present.

// note: Another way to write a class is to write a struct;
// A struct is also a class in which members have public access by default. So, a struct is the same thing as a class.
// but with a public access specifier by default.

// note: we use 'structs' in the C programming language

struct myStruct {
    // everything in here,
    // is public by default
};

class PublicAccessClass {
public:
    int x{32};
    std::string str{"tarokh is a moderate programmer | said by PublicAccessClass "};

    void printX() {
        std::cout << str << " from printX" << std::endl;
    }

    static void doSomething();
};

void PublicAccessClass::doSomething() {
    std::cout << "A message from doSomething() ... " << std::endl;
}

// Private access members are accessible only to other class members, not objects.

class PrivateAccessClass {
private:
    int x{56};

public:
    void printX() {
        std::cout << "The value of x in PrivateAccessClass is ----->>> " << x << std::endl; // x is accessible here
    }

};

// Constructor: A constructor is a member function that has the same name as the class. To initialize an object of a class,
// we use constructors. Constructor's purpose is to initialize an object of a class. It constructs an object and can set
// values to data members. If a class has a constructor, all objects of that class, will be initialized by a constructor
// call

// A constructor without parameters or with default parameters set  is called a 'default constructor'. It is a constructor which can be called
// without arguments.

class ClassWithDefaultConstructor
{
public:
    ClassWithDefaultConstructor() {
        std::cout << "Default Constructor Invoked" << std::endl;
    }
};

// another example of a default constructor; the one with the default arguments.

class ClassWithDefaultArguments
{
public:
    ClassWithDefaultArguments(int x = 56, bool isActive = true) {
        std::cout << "Default Constructor invoked in ClassWithDefaultArguments" << std::endl;
    }
};

// Constructors can have arbitrary parameters, in which case we call them user-defined constructors:

class UserDefinedConstructorClass
{
public:
    int x, y;
    UserDefinedConstructorClass(int xx, int yy) {
        x = xx;
        y = yy;
    }

    void printXY();

};

void UserDefinedConstructorClass::printXY() {
    std::cout << x << " " << y << std::endl;
}

// In previous class, we used a constructor body and assignment to assign value to each class member,
// A better, and more efficient way to initialize an object of a class, is to use the constructor's 'member initializer list',
// In the definition of a constructor:

class MemberInitializationClass
{
public:
    int x, y;
    MemberInitializationClass(int xx, int yy) : x{xx}, y{yy}    //  This is the preferred way of initializing class data members.
    { }
    void prnXY();
};

void MemberInitializationClass::prnXY() {
    std::cout << x << " " << y << std::endl;
}


int main() {

    int x, y;
    x = y = 0;

    PublicAccessClass pacObj;
    pacObj.x = 87;
    std::cout << pacObj.str << std::endl;
    pacObj.printX();
    PublicAccessClass::doSomething();

    PrivateAccessClass prvObj;
    // here, prvObj do not have access to x.
    prvObj.printX();

    ClassWithDefaultConstructor invokeConstructorClassObject;
    ClassWithDefaultArguments invokeConstructorWithArgumentsClassObject;

    std::cout << "Enter values for x and y --------->>>>>>>> " << std::endl;
    std::cin >> x >> y;
    UserDefinedConstructorClass userDefConstClass{x, y};
    userDefConstClass.printXY();

    MemberInitializationClass memInitializationObj{x, y};
    memInitializationObj.prnXY();

}


