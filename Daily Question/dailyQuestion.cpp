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

    // 3115. 质数的最大距离
    bool isPrime(int n) {
        if(n<=1) return false;
        if(n==2) return true;
        for(int i = 2; i*i<=n; i++) {
            if(n % i == 0) {
                return false;
            }
        }
        return true;
        
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int pre =0;
        while(!isPrime(nums[pre]))
        {
            pre++;
        }
        cout<<pre<<endl;
        int res = 0;
        for(int i =pre;i<nums.size();i++)
        {
            if(isPrime(nums[i]))
            {
                res = max(res,i-pre);
            }
        }
        return res;
    }
    // 3033. 修改矩阵
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i =0;i<n;i++)
        {
            int maxNum = -1;
            for(int j =0;j<m;j++)
            {
                maxNum = max(maxNum,matrix[j][i]);
            }
            for(int j =0;j<m;j++)
            {
                if(matrix[j][i]==-1)
                {
                    matrix[j][i] = maxNum;
                }
            }
        }
        return matrix;
    }
};



int main()
{
 // 创建 Solution 对象
    Solution solution;

     // 创建测试用例
    vector<int> nums = {4,2,9,5,3};

    // 调用函数并打印结果
    int maxDiff = solution.maximumPrimeDifference(nums);
    cout << "Maximum prime difference: " << maxDiff << endl;

    return 0;
}