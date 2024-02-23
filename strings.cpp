//
// Created by tarokh on 23/02/24.
//

#include <iostream>
#include <cstring>
#include <string>

void getAndPrint(const char*);
void printSubstr(const std::string&, int starting_pos, int len);
void myFind(const std::string& str, const std::string& substring);

int main() {
    std::string firstname = "Tarokh";
    std::cout << firstname << std::endl;
    std::string lastname = " Yaghoubi";
    std::string fullname;
    fullname = firstname + lastname;
    std::cout << "The FUllNAme is ------>>>>> " << fullname << std::endl;

    // we can add a character to our string;

    char exclamation = '!';
    fullname += exclamation;    // concatenated
    std::cout << "The FUllNAme with EXCLAMATION is ------>>>>> " << fullname << std::endl;

    // The type string is so-called class-template. It is implemented using templates.

    // ACCESSING CHARACTERS

    std::string s = "I am going to learn back-end development with JavaScript, and the C++ programming language in parallel !!";
    char c1 = s[0];     // access the first character which is 'I'
    char c2 = s.at(0);  // access the first character in a more modern way, which is 'I'
    char c3 = s[6];
    char c4 = s.at(6);

    std::cout << "First character --->> " << c1 << " " << c2 << " Sixth character ---->>>> " << c3 << " " << c4 << std::endl;

    // COMPARING STRINGS

    std::string s_copy = s;
    if (s_copy == s)
        std::cout << "Strings s_copy and s are equals" << "\n" << s_copy << '\n' << s << std::endl;
    else
        std::cout << "String s_copy and s are not equals" << std::endl;


    // this is what we do in the C programming language
    const char* str = "joke";
    const char* otherstr = "joke";

    if (strcmp(str, otherstr) == 0)
        std::cout << "the same" << std::endl;
    else
        std::cout << "not the same" << std::endl;
    // end-


    // STRING INPUT

    std::string inp_str;
    std::cout << "Please enter a string: " << std::endl;
    std::getline(std::cin, inp_str);
    std::cout << "You just entered this ------>>>>> " << inp_str << std::endl;

    // we use std::getline, because std::cin will not accept while spaces as part of the string,
    // and it will only accept the first part of the string
    // std::getline(read_from, into);

    getAndPrint(inp_str.c_str());
    printSubstr(inp_str.c_str(), 3, 6);

    // .c_str returns a 'pointer' to the strings 'first character'.
    // .c_str is useful when we want to pass our std::string variable to a function that accepts a const char* parameter.

    myFind(inp_str, "programmer");


    return 0;
}

void getAndPrint(const char* something) {
    std::cout << something << std::endl;
}

void printSubstr(const std::string& str, int starting_pos, int len) {

    // .substr: the function returns a substring that starts at a certain position in the main string
    // and is of a certain length.

    std::string substring = str.substr(starting_pos, len);
    std::cout << "Sub string is : " << substring << std::endl;
}

void myFind(const std::string& str, const std::string& substring) {

    // find() searches for a substring in a string, if the substring is found,
    // the function returns its first characters position,
    // if not, the function returns a value that is std::string::npos,
    // The function itself is of type std::string::size_type.

    std::string::size_type found = str.find(substring);
    if (found != std::string::npos)
        std::cout << "found !!!" << " " << found << std::endl;
    else
        std::cout << "The substring is not found" << std::endl;

}

