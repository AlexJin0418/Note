#include <iostream>
#include <string>
#include <cctype>

using namespace std; 

int main()
{

    string s = "lower case string";

    // 使用对 c 的引用
    for (auto &c : s)
    {
        c = toupper(c);
    }

    cout << s << endl;

    return 0;
}