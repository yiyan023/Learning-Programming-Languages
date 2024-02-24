#include <iostream>
using namespace std;

int main() {
    // data types are referenced similar to C 

    //strings 
    std::string message = "Hello World";

    // + operator is used to append / add strings together
    std::string first_word = "Hello";
    std::string second_word = "World";

    std::string message = first_word + " " + second_word;

    // can also access specific letters in a string, like an array
    char letter = message[0]; // letter is "H"

    // we can also retrieve the length of a string:
    int message_length = message.length(); // 11
    }