#include <iostream>
#include <string>
#include <typeinfo>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

    cout << "Enter two numbers" << endl;

    int x = 0, y = 0;

    cin >> x >> y;

    cout << "The sum of two number is: " << x + y << endl;

    // Constructor: Fills the string with n consecutive copies of character c.
    string s1(3, 'b');

    cout << s1 << endl;

    size_t size = s1.size();

    cout << "Size of s1 is: " << size << endl;

    string s = "test";

    cout << "type of s: " << typeid(s) << endl;

    cout << "type of 'test': " << typeid("test") << endl;
    
    return 0;
}