
#include <iostream>
#include <string>

// When an object is created on one line and then assigned to in the next line,
// it them uses the copy assignment operator to copy the data from another object:

// MyClass copyfrom;
// MyClass copyto;
// copyto = copyfrom;       // uses a copy assignment operator



class MyClass
{
public:
    MyClass& operator = (const MyClass& rhs);

};

MyClass& MyClass::operator=(const MyClass &rhs) {
    // Implement the copy logic here
    return *this;
}

class CopyAssignmentClass
{

private:
    int data;

public:
    CopyAssignmentClass(int d): data{d}
    { }

    CopyAssignmentClass& operator = (const CopyAssignmentClass& rhs);

    int getData() const {
        return data;
    }
};

// Here, you are overloading = operator ...

CopyAssignmentClass& CopyAssignmentClass::operator=(const CopyAssignmentClass &rhs) {
    if (this != &rhs)
        data = rhs.data;

    return *this;       // return a reference to the modified object

}


int main() {
    CopyAssignmentClass obj(34);
    CopyAssignmentClass obj2(54);

    std::cout << "Before assignment" << std::endl;
    std::cout << "Object data ---->>> " << obj.getData() << std::endl;
    std::cout << "Object 2 data ---->>> " << obj2.getData() << std::endl;

    //  Assign obj2's data to obj using the copy assignment operator

    obj = obj2;

    std::cout << std::endl << "After Assignment" << std::endl;
    std::cout << "Obj data : " << obj.getData() << std::endl;
    std::cout << "Obj2 data : " << obj2.getData() << std::endl;

    return 0;

}
