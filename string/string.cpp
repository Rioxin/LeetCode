#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>  // 添加这一行
#include <unordered_map>
#include <iostream>

using namespace std ;
class Solution {
public:
    //反转字符串
    void reverseString(vector<char>& s) {
    for(int i=0,j=s.size()-1;i<j;i++,j--)
    {
        swap(s[i],s[j]);
    }
    }

    //反转字符串2
    string reverseStr(string s, int k) {
        if(s.size()<2*k)
        {
            return s;
        }
        for(int i =0;i<s.size();i+=(2*k))
        {
            if(i+k<=s.size())
            {
                reverse(s.begin()+i,s[i+k]);
            }
            else
            {
                reverse(s[i+k+1],s.end());
            }
        }
    }


};



int main()
{
 // 创建 Solution 对象
    Solution solution;

    // 示例输入字符串
    vector<char> input = {'h', 'e', 'l', 'l', 'o'};
    string s = "abcdefg";
    int k = 2;
    // 打印原始字符串
    for (char c : s) {
        cout << c;
    }
    cout << endl;

    // 调用反转函数
    solution.reverseString(input);
    res = solution.reverseStr(s,k);

    // 打印反转后的字符串
    for (char c : res) {
        cout << c;
    }
    cout << endl;

    return 0;

    

    return 0;
}