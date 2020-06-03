#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main ()
{
    string sentence = " Hello, World !!! ";

    int punc_cnt = 0, space_cnt = 0;

    for (auto c : sentence)
    {
        if (ispunct(c))
        {
            punc_cnt ++;
        }

        if (isspace(c))
        {
            space_cnt ++;
        }
    }

    cout << punc_cnt << " number of punctuation characters" << endl;
    cout << space_cnt << " number of space characters" << endl;

    return 0;
}