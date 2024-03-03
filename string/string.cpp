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
        for(int i =0;i<s.size();i+=(2*k))
        {
            if(i+k<=s.size())
            {
                reverse(s.begin()+i,s.begin()+i+k);
            }
            else
            {
                reverse(s.begin()+i,s.end());
            }
        }
        return s;
    }
    
    //反转字符串中的单词
    void reverses(string& s,int start,int end)
    {
        for(int i =start,j= end;i<j;i++,j--)
        {
            swap(s[i],s[j]);
        }
    }
    string reverseWords(string s) {
        int slow = 0;
        for(int i = 0 ;i<s.size();i++)
        {
            if(s[i]!=' ')
            {
                if(slow!=0)
                {
                    s[slow++]=' ';
                }
                while(s[i]!=' ' && i<s.size())
                {
                    s[slow++]=s[i++];
                }
            }
        }
        s.resize(slow);
        reverses(s,0,slow-1);
        int pre = 0;
        for(int i = 0 ;i<s.size();i++)
        {
            if(s[i]==' ')
            {
               reverses(s,pre,i-1); 
               pre = i+1;
            }
        }
        reverses(s,pre,s.size()-1); 
    return s;
    }

    //找出字符串中第一个匹配项的下标
    void getNext(int* next,const string& s)
    {
        int j=-1;
        next[0]=j;
        for(int i =1;i<s.size();i++)
        {
            //不匹配,一直回退到上一次匹配的
            while(j>=0&&s[j+1]!=s[i])
            {
                j=next[j];
            }
            if(s[j+1]==s[i])
            {
                j++;
            }
            next[i]=j;
        }
    }
    int strStr(string haystack, string needle) {
        int next[needle.size()];
        getNext(next,needle);
        int j = -1;
        for(int i=0;i<haystack.size();i++)
        {
            while(j>=0 && haystack[i]!=needle[j+1])
            {
                j=next[j];
            }
            if(haystack[i]==needle[j+1])
            {
                j++;
            }
            if(j==needle.size()-1)
            {
                return i-needle.size()+1;
            }
        }
        return -1;
    }

    //重复的子字符串
    bool repeatedSubstringPattern(string s) {

    }

};



int main()
{
 // 创建 Solution 对象
    Solution solution;

    // 示例输入字符串
    vector<char> input = {'h', 'e', 'l', 'l', 'o'};
    string s = "the sky is blue";
    int k = 2;
    // 打印原始字符串
    for (char c : s) {
        cout << c;
    }
    cout << endl;
    string testNext ="aabaaf";
    int next[testNext.size()];
    solution.getNext(next,testNext);
    for(int nnn : next)
    {
        cout<< nnn<< " ";
    }
    cout<<endl;
    // 调用反转函数
    string ress=solution.reverseWords(s);
    string res = solution.reverseStr(s,k);

    // 打印反转后的字符串
    for (char c : ress) {
        cout << c;
    }
    cout << endl;

    return 0;

    

    return 0;
}