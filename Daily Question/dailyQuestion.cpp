#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>  // 添加这一行
#include <unordered_map>
#include <iostream>

using namespace std ;
//链表
struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x):val(x),next(NULL){}
    };

class Solution {
public:
    //最大二进制奇数 3.13
    string maximumOddBinaryNumber(string s) {
        int count = 0;
        string res;
         for(char c :s)
         {
            if(c=='1') count++;
         }
         for(int i =0;i<s.size()-1;i++)
         {
            if(i<count-1)res+="1";
            else res+="0";
         }
         return res+"1";
    }
    
    //合并后数组中的最大元素
    long long maxArrayValue(vector<int>& nums) {
        long long res = nums[nums.size()-1];
        if(nums.size()==1) return nums[0];
        for(int i =nums.size()-2 ;i>=0;i--)
        {
            if(res>=nums[i]) 
            {
                res = res+nums[i];
            }
            else{
                res = nums[i];
            }
        }
        return res;
    }
};



int main()
{
 // 创建 Solution 对象
    Solution solution;

    std::vector<int> nums1 = {5,3,3};
    std::cout << "Maximum sum of nums1: " << solution.maxArrayValue(nums1) << std::endl;

    return 0;
}