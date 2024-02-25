
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


// When we initialize an object with another object of the same class, we invoke a copy constructor.
// If we do not supply our copy constructor, The compiler generates a default copy constructor that performs
// the so-called shallow copy.

class CopyConstructorClass
{
private:
    int x, y;
public:
    CopyConstructorClass(int xx, int yy) : x{xx}, y{yy}
    { }

    void prnPrintXXYY();
};

void CopyConstructorClass::prnPrintXXYY() {
    std::cout << x << " " << y << std::endl;
}

// We can provide our own copy constructor.
// The copy constructor has a special parameter signature of MyClass(const MyClass& rhs)

class UserDefinedCopyConstructor
{
private:
    int x, y;

public:
    UserDefinedCopyConstructor(int xx, int yy) : x{ xx }, y { yy }
    { }

    // User defined copy constructor

    UserDefinedCopyConstructor(const UserDefinedCopyConstructor& rhs) : x{rhs.x}, y{rhs.y}  // Initialize members with other object's members
    {
        std::cout << "User defined copy constructor invoked " << x << " " << y << std::endl;
    }
};

// Please note that the default copy constructor does not correctly copy members of some types, such as pointers, arrays, etc.
// In order to properly make copies, we need to define our own copy logic inside the copy constructor. This is referred to as 'deep copy'.
// For pointers, for example, we need both to create a pointer and assign a value to the object it points to int our user-defined copy constructor.

class DeepCopyClass
{
private:
    int x;
    int* ptr;

public:

    DeepCopyClass(int xx, int pp) : x{xx}, ptr{ new int(pp) }
    { }

    DeepCopyClass(const DeepCopyClass& rhs) : x{rhs.x}, ptr{ new int {*rhs.ptr }}
    {
        std::cout << "values of x and ptr is --------->>>>>>> " << x << " " << *ptr << std::endl;

    }

    void printXandPtr();
};

void DeepCopyClass::printXandPtr() {
    std::cout << "values of x and ptr is --------->>>>>>> " << x << " " << *ptr << std::endl;
}

int main() {

    int x, y;
    x = y = 0;

    int* ptr = &x;

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

    CopyConstructorClass copyConstObj{x, y};
    CopyConstructorClass copyConstObj1{copyConstObj};
    copyConstObj1.prnPrintXXYY();

    std::cout << std::endl << "-------------------------------" << std::endl;

    UserDefinedCopyConstructor o{ 1, 5 };
    UserDefinedCopyConstructor o2 = o;  // user defined copy constructor invoked

    DeepCopyClass deepCopy{56, 65};
    DeepCopyClass deepCopy2 = deepCopy;     // user defined copied constructor invoked
    deepCopy2.printXandPtr();

}


