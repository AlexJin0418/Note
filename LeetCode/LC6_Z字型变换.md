# LC6. Z字型变换

将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);

> 输入：s = "PAYPALISHIRING", numRows = 3
> 输出："PAHNAPLSIIGYIR"

> 输入：s = "PAYPALISHIRING", numRows = 4
> 输出："PINALSIGYAHRPI"
> 解释：
> P     I    N
> A   L S  I G
> Y A   H R
> P     I



## 思路

使用一个二维数组来保存

二维数组的长度不好确定，只能使用字符串的长度

这样会造成大量的空间浪费

```C++
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        std::vector<std::vector<char>> board(numRows, vector<char>(s.size(), ' '));
        
        int x = 0, y = 0, direction = 0;
        for (int i = 0; i < s.size(); i++)
        {
            board[x][y] = s[i];
            if (x == 0)
            {
                direction = 0;
                x += 1;
            }
            else if (x == numRows - 1)
            {
                direction = 1;
                x -= 1;
                y += 1;
            }
            else if (direction == 0)
            {
                x += 1;
            }
            else if (direction == 1)
            {
                x -= 1;
                y += 1;
            }
        }

        //print(board);

        string ans;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] != ' ')
                {
                    ans += board[i][j];
                }
            }
        }

        return ans;
    }
};
```



## 改进思路

由于**处于同一行的字符在最终输出时是在一起的**

所以可以使用一个一维数组代替二维数组

一维数组的每个元素不是字符而是一个字符串，代表这一行的所有字符

这样能够节省许多空间

```C++
class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size() == 1) return s;

        std::vector<string> board(min(int(s.size()), numRows));

        int x = 0, direction = -1;
        for (int i = 0; i < s.size(); i++)
        {
            board[x] += s[i];

            if (x == 0 || x == numRows - 1) direction *= -1;
            x += direction == 1 ? 1 : -1;
        }
        string ans;

        for (string s : board) ans += s;
        return ans;
    }
};
```

